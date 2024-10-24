#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TRecFolderSelector.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("TRec");

    // Статус программы
    m_status = TRecStatus::NOTCONNECTED;
    QRect windowRect = this->rect();
    m_pStatusLabel = new QLabel(StatusLabels[static_cast<int>(m_status)], this);
    m_pStatusLabel->setGeometry(20, windowRect.height()-25,
                                400, 14);

    // Сокет соединения с платой АЦП
    connect(&m_TcpSocket, &QIODevice::readyRead, this, &MainWindow::ADCSocketRead);
    connect(&m_TcpSocket, &QAbstractSocket::errorOccurred, this, &MainWindow::connectErrorDisplay);
    connect(&m_TcpSocket, &QAbstractSocket::connected, this, &MainWindow:: connectSuccessDisplay);
    connect(&m_TcpSocket, &QAbstractSocket::disconnected, this, &MainWindow:: disconnectSuccessDisplay);
    m_ADC.TcpSocket_set(&m_TcpSocket);

    // Параметры кнопок
    ui->OKButton->setText("Завершить");
    //QIcon OKButtonIcon("..//..//Res//Apply.svg");
    //ui->OKButton->setIcon(OKButtonIcon);

    // ui->manualStartButton->setText("Однократный запуск\nрегистрации");
    // QIcon manualStartButtonIcon("..//..//Res//SingleStart.svg");
    // ui->manualStartButton->setIcon(manualStartButtonIcon);

    ui->StartButton->setText("Запуск\nрегистрации");
    QIcon StartButtonIcon("..//..//Res//Start.svg");
    ui->StartButton->setIcon(StartButtonIcon);

    ui->StopButton->setText("");
    QIcon StopButtonIcon("..//..//Res//Stop.svg");
    ui->StopButton->setIcon(StopButtonIcon);

    ui->RatioSetButton->setText("Настроить");
    QIcon RatioSetButtonIcon("..//..//Res//Settings.svg");
    ui->RatioSetButton->setIcon(RatioSetButtonIcon);

    // Grid с кнопками внизу окна
    ui->horizontalLayout->addWidget(ui->OKButton);

    // Пользовательский Widget ввода параметров соединения с платой АЦП
    QLabel* pIPAddressLabel = new QLabel("IP-адрес платы АЦП:");
    ui->IPAddressGrid->addWidget(pIPAddressLabel, 0, 0, 1, 3);
    m_pIPEdit = new CTRecIPEditBox(this);
    ui->IPAddressGrid->addWidget(m_pIPEdit, 0, 3, 1, 2);
    m_pIPEdit->setMaximumHeight(24);
    m_pIPEdit->IPAddress_set(QString(ADCIPAdressDefault));

    QLabel* pPortLabel = new QLabel("Номер порта платы АЦП:");
    ui->IPAddressGrid->addWidget(pPortLabel, 1, 0, 1, 4);
    m_pPortEdit = new QLineEdit(this);
    m_pPortEdit->setMaximumWidth(56);
    QString portStr;
    m_pPortEdit->setText(portStr.setNum(ADCPortDefault));
    ui->IPAddressGrid->addWidget(m_pPortEdit, 1, 4, 1, 1);

    m_ConnectButtonIcon = QIcon("..//..//Res//Connect2.svg");
    m_DisconnectButtonIcon = QIcon("..//..//Res//Disconnect.svg");
    m_pConnectButton = new QPushButton(m_ConnectButtonIcon,ADCConnectButtonLabels[m_ADC.ConnectStatus_get()? 1:0], this);
    m_pConnectButton->setIconSize(QSize(36,36));
    ui->IPAddressGrid->addWidget(m_pConnectButton, 2, 0, 2, 2);
    connect(m_pConnectButton, &QPushButton::clicked, this, &MainWindow::on_ADCConnectButton_clicked);

    QLabel* pConnectStatus = new QLabel(ADCConnectStatusLabels[m_ADC.ConnectStatus_get()? 1:0]);
    ui->IPAddressGrid->addWidget(pConnectStatus, 2, 2, 2, 3);
    //ui->IPAddressGrid->setVerticalSpacing(15);

    // Grid с элементами задания числа каналов
    ui->CHGrid->addWidget(ui->CHSelectLabel, 0, 0, 1, 4);
    ui->CHGrid->addWidget(ui->CHSelectSpin, 0, 4, 1, 1);
    ui->CHSelectLabel->setText("Число измерительных каналов");
    ui->CHSelectSpin->setMinimum(0);
    ui->CHSelectSpin->setMaximum(CHTotalNum);
    ui->CHSelectSpin->setValue(CHTotalNum);


    // Табы (страницы) для настройки каналов
    auto ChNum = CHTotalNum<2 ? 2 : CHTotalNum;
    CTRecADCParam* pADCParam = m_ADC.ADCParam_get();
    ui->CHTabWidget->clear();
    pADCParam->CHParam_get()->reserve(ChNum);

    for(auto i=0; i<ChNum; i++)
    {
        CTRecADCChParam ChParam;
        ChParam.ind_set(i);
        pADCParam->CHParam_get()->push_back(ChParam);
    }

    CTRecADCChParamWidgets* pCHParamWidgets;
    for(auto i=0; i<ChNum; i++)
    {
        pCHParamWidgets = new CTRecADCChParamWidgets(&(pADCParam->CHParam_get()->at(i)),
                                                     ui->CHTabWidget);
        ui->CHTabWidget->addTab(pCHParamWidgets, QString("Ch%1").arg(i));
        pChWidgets_vec.push_back(pCHParamWidgets);

        connect(pCHParamWidgets->pApplyCheck, &QCheckBox::stateChanged,
                [this]()
                {
                    if(ui->SameChParamCheck->isChecked())
                        ChParamChange(0);
                });

        connect(pCHParamWidgets->pTriggerCheck, &QCheckBox::stateChanged,
                [this]()
                {
                    if(ui->SameChParamCheck->isChecked())
                        ChParamChange(1);
                });

        connect(pCHParamWidgets->pTriggerSlider, &QSlider::valueChanged,
                [this]()
                {
                    if(ui->SameChParamCheck->isChecked())
                        ChParamChange(2);
                });

        connect(pCHParamWidgets->pTriggerModeGroup, &QButtonGroup::buttonClicked,
                [this]()
                {
                    if(ui->SameChParamCheck->isChecked())
                        ChParamChange(3);
                });

        connect(pCHParamWidgets->pTriggerPolarityGroup, &QButtonGroup::buttonClicked,
                [this]()
                {
                    if(ui->SameChParamCheck->isChecked())
                        ChParamChange(4);
                });
    }


    // Grid коэффициента деления
    ui->RatioGrid->setColumnStretch(1,2);
    ui->RatioValue->setNum(pADCParam->CHParam_get()->at(0).ratio_get());


    // Общие параметры
    ui->CommonParamGrid->addWidget(ui->SampleRateLabel, 0,0,1,3);
    ui->CommonParamGrid->addWidget(ui->SampleRateCombo, 0,3,1,1);
    ui->CommonParamGrid->addWidget(ui->SampleRateUnitLabel, 0,4,1,2);

    ui->BufferGrid->addWidget(ui->BufferSizeSpin, 0,0,2,1);
    ui->BufferGrid->addWidget(ui->BufferSizeUnitLabel, 0,1,2,1);
    ui->BufferGrid->addWidget(ui->BufferSizeSampleSpin, 0,2,2,1);
    ui->BufferGrid->addWidget(ui->BufferSizeSampleUnitLabel, 0,3,2,1);
    ui->BufferGrid->addWidget(ui->BufferSizeSlider, 1,0,3,5);

    ui->HistGrid->addWidget(ui->HistSizeSpin, 0,0,2,1);
    ui->HistGrid->addWidget(ui->HistSizeUnitLabel, 0,1,2,1);
    ui->HistGrid->addWidget(ui->HistSizeSampleSpin, 0,2,2,1);
    ui->HistGrid->addWidget(ui->HistSizeSampleUnitLabel, 0,3,2,1);
    ui->HistGrid->addWidget(ui->HistSizeSlider, 1,0,3,5);


    ui->SampleRateLabel->setText("Частота дискретизации");
    ui->SampleRateUnitLabel->setText("МГц");
    ui->BufferSizeUnitLabel->setText("мс");
    ui->BufferSizeSampleUnitLabel->setText("отсчетов");

    ui->HistSizeUnitLabel->setText("мс");
    ui->HistSizeSampleUnitLabel->setText("отсчетов");


    disconnect(ui->SampleRateCombo, &QComboBox::currentIndexChanged, nullptr, nullptr);
    int sampleRateVarNum = static_cast<int>(sizeof(SampleRateVals) / sizeof(SampleRateVals[0]));
    for(auto i=0; i<sampleRateVarNum; i++)
    {
        ui->SampleRateCombo->addItem(QString("%1").arg(SampleRateVals[i], 0, 'g'));
        if(SampleRateVals[i] == m_ADC.ADCParam_get()->SRate_get())
            ui->SampleRateCombo->setCurrentIndex(i);
    }
    connect(ui->SampleRateCombo, &QComboBox::currentIndexChanged,
            this, &MainWindow::on_SampleRateCombo_currentIndexChanged);


    disconnect(ui->BufferSizeSampleSpin, &QSpinBox::valueChanged, nullptr, nullptr);
    disconnect(ui->BufferSizeSlider, &QSlider::valueChanged, nullptr, nullptr);
    ui->BufferSizeSampleSpin->setMinimum(BufferSizeSampleMin);
    ui->BufferSizeSampleSpin->setMaximum(BufferSizeSampleMax);
    ui->BufferSizeSlider->setMinimum(BufferSizeSampleMin);
    ui->BufferSizeSlider->setMaximum(BufferSizeSampleMax);
    ui->BufferSizeSpin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    ui->BufferSizeSpin->setDecimals(2);
    ui->BufferSizeSampleSpin->setSingleStep(1000);
    connect(ui->BufferSizeSlider, &QSlider::valueChanged,
            ui->BufferSizeSampleSpin, &QSpinBox::setValue);
    connect(ui->BufferSizeSampleSpin, &QSpinBox::valueChanged,
            ui->BufferSizeSlider, &QSlider::setValue);
    connect(ui->BufferSizeSlider, &QSlider::valueChanged,
            this, &MainWindow::on_BufferSizeSlider_valueChanged);
    ui->BufferSizeSampleSpin->setValue(m_ADC.ADCParam_get()->BSize_get());

    histSizeMax_set();
    ui->HistSizeSampleSpin->setMinimum(HistSizeSampleMin);
    ui->HistSizeSlider->setMinimum(HistSizeSampleMin);
    ui->HistSizeSpin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    ui->HistSizeSpin->setDecimals(2);
    ui->HistSizeSampleSpin->setSingleStep(1000);


    auto folderSelector = new CTRecFolderSelector();
    ui->SaveFolderGrid->addWidget(folderSelector, 1, 0, 1, 1);


    // Явно устанавливаем статус программы
    status_set(TRecStatus::NOTCONNECTED);

}

MainWindow::~MainWindow()
{
    delete ui;
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Изменение статуса программы
void MainWindow::status_set(TRecStatus status)
{
    m_status = status;
    m_pStatusLabel->setText(StatusLabels[static_cast<int>(m_status)]);

    switch(m_status)
    {
    case TRecStatus::NOTCONNECTED:
        m_ADC.ConnectStatus_set(false);
        m_pConnectButton->setText(ADCConnectButtonLabels[m_ADC.ConnectStatus_get()? 1:0]);
        m_pConnectButton->setIcon(m_ConnectButtonIcon);
        m_pConnectButton->setEnabled(true);
        ui->StartButton->setEnabled(false);
        ui->StopButton->setEnabled(false);
        break;
    case TRecStatus::STANDBY:
        m_ADC.ConnectStatus_set(true);
        m_pConnectButton->setText(ADCConnectButtonLabels[m_ADC.ConnectStatus_get()? 1:0]);
        m_pConnectButton->setEnabled(true);
        m_pConnectButton->setIcon(m_DisconnectButtonIcon);
        ui->StartButton->setEnabled(true);
        ui->StopButton->setEnabled(false);
        break;
    case TRecStatus::ACQUISITION:
        ui->StartButton->setEnabled(false);
        ui->StopButton->setEnabled(true);
        break;
    case TRecStatus::IMPORT:
        ui->StartButton->setEnabled(false);
        ui->StopButton->setEnabled(false);
        break;
    }
}




// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Регулирование частоты дискретизации
void MainWindow::on_SampleRateCombo_currentIndexChanged(int index)
{
    m_ADC.ADCParam_get()->SRate_set(SampleRateVals[index]);
    ui->BufferSizeSpin->setMinimum(BufferSizeSampleMin/SampleRateVals[index]*1e-3);
    ui->BufferSizeSpin->setMaximum(BufferSizeSampleMax/SampleRateVals[index]*1e-3);
    ui->BufferSizeSpin->setValue(ui->BufferSizeSampleSpin->value()/SampleRateVals[index]*1e-3);

    ui->HistSizeSpin->setValue(ui->HistSizeSampleSpin->value()/SampleRateVals[index]*1e-3);
    histSizeMax_set();
}


// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Регулирование размера буфера под осциллограмму
void MainWindow::on_BufferSizeSlider_valueChanged(int value)
{
    m_ADC.ADCParam_get()->BSize_set(value);
    ui->BufferSizeSpin->setValue(value/SampleRateVals[ui->SampleRateCombo->currentIndex()]*1e-3);

    histSizeMax_set();
}


void MainWindow::on_BufferSizeSpin_valueChanged(double arg1)
{
    ui->BufferSizeSampleSpin->setValue(static_cast<double>(arg1*SampleRateVals[ui->SampleRateCombo->currentIndex()]*1e3));
}


void MainWindow::on_CHSelectSpin_valueChanged(int arg1)
{
    for(auto i = 0; i<CHTotalNum; i++)
    {
        ui->CHTabWidget->setTabEnabled(i, i<arg1);
    }
    m_ADC.ADCParam_get()->ChNum_set(arg1-1);
}


// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопки закрытия окна
void MainWindow::on_OKButton_clicked()
{
    exit(0);
}
void MainWindow::on_CancelButton_clicked()
{
    exit(0);
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Регулирование размера предыстории
void MainWindow::on_HistSizeSpin_valueChanged(double arg1)
{
    ui->HistSizeSampleSpin->setValue(static_cast<double>(arg1*SampleRateVals[ui->SampleRateCombo->currentIndex()]*1e3));
    m_ADC.ADCParam_get()->HSize_set(arg1);
}


void MainWindow::on_HistSizeSlider_valueChanged(int value)
{
    ui->HistSizeSampleSpin->setValue(value);
    m_ADC.ADCParam_get()->HSize_set(value);
    ui->HistSizeSpin->setValue(value/SampleRateVals[ui->SampleRateCombo->currentIndex()]*1e-3);
}


void MainWindow::on_HistSizeSampleSpin_valueChanged(int arg1)
{
    ui->HistSizeSlider->setValue(arg1);
    m_ADC.ADCParam_get()->HSize_set(arg1);
}





// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Пользовательские функции
void MainWindow::histSizeMax_set()
{
    histSizeSampleMax = round(HistSizeSampleMaxCoef * ui->BufferSizeSampleSpin->value());
    ui->HistSizeSampleSpin->setMaximum(histSizeSampleMax);
    ui->HistSizeSlider->setMaximum(histSizeSampleMax);
}




// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка установки соединения с АЦП
void MainWindow::on_ADCConnectButton_clicked()
{
    m_pConnectButton->setEnabled(false);
    if(m_ADC.ConnectStatus_get())   // соединение установлено, надо разорвать
    {
        m_ADC.ADCDisconnect();
    }
    else    // соединения нет, пробуем установить
    {
        m_ADC.IPAddress_set(m_pIPEdit->IPAddress_get());
        m_ADC.IPPort_set(m_pPortEdit->text().toInt());
        m_ADC.ADCConnect();
    }
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка однократного ручного запуска
void MainWindow::on_manualStartButton_clicked()
{
    // однократный запуск
}



// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка запуска регистрации
void MainWindow::on_StartButton_clicked()
{
    // Сброс настроек платы АЦП
    m_ADC.ADCReset();
    // Инициализация платы (настройка измерительных каналов)
    m_ADC.ADCInit();
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка останова регистрации
void MainWindow::on_StopButton_clicked()
{

}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Переключатель совпадения параметров каналов
void MainWindow::on_SameChParamCheck_toggled(bool checked)
{
    if(checked)
    {
        ChParamChange(0);
        ChParamChange(1);
        ChParamChange(2);
        ChParamChange(3);
        ChParamChange(4);
    }
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка вызова диалога задания коэффициентов
void MainWindow::on_RatioSetButton_clicked()
{
    m_pMeasLoopParamDlg = new CTRecMeasLoopParamDlg(this);
    m_pMeasLoopParamDlg->setAttribute(Qt::WA_DeleteOnClose);
    m_pMeasLoopParamDlg->setWindowTitle("Передаточные коэффициенты измерительного тракта");

    QObject::connect(m_pMeasLoopParamDlg, SIGNAL(finished(int)),
                     this, SLOT(on_MeasLoopParamChanged(int)));

    m_pMeasLoopParamDlg->exec();
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Задание идентичными параметров всех каналов
void MainWindow::ChParamChange(int flag)
{
    vector<class CTRecADCChParam>* pADCChParam_vec = m_ADC.ADCParam_get()->CHParam_get();

    int ind = ui->CHTabWidget->currentIndex();
    bool ans;
    int triggerPermille = pADCChParam_vec->at(ind).trigger_get().m_triggerCent;
    int modeId = static_cast<int>(pADCChParam_vec->at(ind).trigger_get().m_triggerMode);
    int polarityId = static_cast<int>(pADCChParam_vec->at(ind).trigger_get().m_triggerPolarity);

    switch(flag)
    {
    case 0:
        ans = pADCChParam_vec->at(ind).OnOff_get();
        for(auto& w : pChWidgets_vec)
            w->pApplyCheck->setCheckState(ans ? Qt::Checked : Qt::Unchecked);
        break;
    case 1:
        ans = pADCChParam_vec->at(ind).OnOffTrigger_get();
        for(auto& w : pChWidgets_vec)
            w->pTriggerCheck->setCheckState(ans ? Qt::Checked : Qt::Unchecked);
        break;
    case 2:
        for(auto& w : pChWidgets_vec)
            w->pTriggerSlider->setValue(triggerPermille);
        break;
    case 3:
        for(auto& w : pChWidgets_vec)
            w->pTriggerModeGroup->button(modeId)->setChecked(true);
        break;
    case 4:
        for(auto& w : pChWidgets_vec)
            w->pTriggerPolarityGroup->button(polarityId)->setChecked(true);
        break;
    }
}



// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Отработка изменения значения коэф. деления
void MainWindow::on_MeasLoopParamChanged(int res)
{
    if(!res)
    {
        ui->RatioValue->setNum(m_ADC.ADCParam_get()->CHParam_get()->at(0).ratio_get());
        for(auto& w : pChWidgets_vec)
            w->ChTriggerValkv_update();
    }
}



// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Считываем данные, поступившие от АЦП
void MainWindow::ADCSocketRead()
{

}



// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Обрабатываем успешное соединение с АЦП
void MainWindow::connectSuccessDisplay()
{
    QMessageBox::information(this, "Соединение с платой АЦП",
                             "Соединение с платой АЦП успешно установлено");

    status_set(TRecStatus::STANDBY);
}



// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Обрабатываем ошибку соединения с АЦП
void MainWindow::connectErrorDisplay(QAbstractSocket::SocketError socketError)
{
    switch(socketError)
    {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::warning(this, "Заголовок", "Хост не найден");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::warning(this, "Заголовок", "Соединение прервано");
        break;
    default:
        QMessageBox::warning(this, "Заголовок", tr("Произошла ошибка: %1.").arg(m_TcpSocket.errorString()));
    }

    status_set(TRecStatus::NOTCONNECTED);
}



// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Обрабатываем успешный разрыв связи с АЦП
void MainWindow::disconnectSuccessDisplay()
{
    QMessageBox::information(this, "Соединение с платой АЦП",
                             "Соединение с платой АЦП успешно разорвано");

    status_set(TRecStatus::NOTCONNECTED);
}

