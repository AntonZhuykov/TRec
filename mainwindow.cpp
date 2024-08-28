#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TRecFolderSelector.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("TRec");

    // Параметры кнопок
    ui->OKButton->setText("Применить");
    QIcon OKButtonIcon("..//..//Res//Apply.svg");
    ui->OKButton->setIcon(OKButtonIcon);

    ui->CancelButton->setText("Отменить");
    QIcon CancelButtonIcon("..//..//Res//Cancel.svg");
    ui->CancelButton->setIcon(CancelButtonIcon);

    ui->manualStartButton->setText("Однократный запуск\nрегистрации");
    QIcon manualStartButtonIcon("..//..//Res//SingleStart.svg");
    ui->manualStartButton->setIcon(manualStartButtonIcon);

    ui->RatioSetButton->setText("Настроить");
    QIcon RatioSetButtonIcon("..//..//Res//Settings.svg");
    ui->RatioSetButton->setIcon(RatioSetButtonIcon);

    // QPalette OKPal = ui->OKButton->palette();
    // OKPal.setColor(QPalette::Button, ButtonColor);
    // ui->OKButton->setPalette(OKPal);
    // ui->OKButton->setAutoFillBackground(true);
    //ui->OKButton->setStyleSheet("QPushButton {background-color: #CBD0D7; color: #AE1818;}");


    // Grid коэффициента деления

    // Grid с кнопками внизу окна
    ui->horizontalLayout->addWidget(ui->CancelButton);
    ui->horizontalLayout->addWidget(ui->OKButton);
    ui->horizontalLayout->insertStretch(1, 6);

    // Grid с элементами задания числа каналов
    ui->CHGrid->addWidget(ui->CHSelectLabel, 0, 0, 1, 4);
    ui->CHGrid->addWidget(ui->CHSelectSpin, 0, 4, 1, 1);
    ui->CHSelectLabel->setText("Число измерительных каналов");
    ui->CHSelectSpin->setMinimum(0);
    ui->CHSelectSpin->setMaximum(CHTotalNum);
    ui->CHSelectSpin->setValue(CHTotalNum);

    // Табы (страницы) для настройки каналов
    auto ChNum = CHTotalNum<2 ? 2 : CHTotalNum;
    ui->CHTabWidget->setTabText(0, "Ch0");
    ui->CHTabWidget->setTabText(1, "Ch1");

    for(auto i=2; i<ChNum; i++)
    {
        auto *TmpTab = new QWidget();
        ui->CHTabWidget->addTab(TmpTab, QString("Ch%1").arg(i));
    }

    for(auto i=0; i<ChNum; i++)
    {
        CTRecADCChParam tmpChParam;
        tmpChParam.ind_set(i);
        m_ADCParam.CHParam_get()->push_back(tmpChParam);
    }

    // Общие параметры
    //ui->CommonParamGrid->setColumnMinimumWidth(3, 80);
    //ui->CommonParamGrid->setColumnMinimumWidth(4, 20);
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


    //int sampleRateVarNum = static_cast<int>(sizeof(SampleRateValsString) / sizeof(SampleRateValsString[0]));
    for(auto v : SampleRateVals)
    {
        ui->SampleRateCombo->addItem(QString("%1").arg(v, 0, 'g'));
    }

    ui->BufferSizeSampleSpin->setMinimum(BufferSizeSampleMin);
    ui->BufferSizeSampleSpin->setMaximum(BufferSizeSampleMax);
    ui->BufferSizeSlider->setMinimum(BufferSizeSampleMin);
    ui->BufferSizeSlider->setMaximum(BufferSizeSampleMax);
    ui->BufferSizeSpin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    ui->BufferSizeSpin->setDecimals(2);
    ui->BufferSizeSampleSpin->setSingleStep(1000);

    histSizeMax_set();
    ui->HistSizeSampleSpin->setMinimum(HistSizeSampleMin);
    ui->HistSizeSlider->setMinimum(HistSizeSampleMin);
    ui->HistSizeSpin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    ui->HistSizeSpin->setDecimals(2);
    ui->HistSizeSampleSpin->setSingleStep(1000);



    auto folderSelector = new CTRecFolderSelector();
    ui->SaveFolderGrid->addWidget(folderSelector, 1, 0, 1, 1);

}

MainWindow::~MainWindow()
{
    delete ui;
}




// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Регулирование частоты дискретизации
void MainWindow::on_SampleRateCombo_currentIndexChanged(int index)
{
    m_ADCParam.SRate_set(SampleRateVals[index]);
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
    ui->BufferSizeSampleSpin->setValue(value);
    m_ADCParam.BSize_set(value);
    ui->BufferSizeSpin->setValue(value/SampleRateVals[ui->SampleRateCombo->currentIndex()]*1e-3);

    histSizeMax_set();
}


void MainWindow::on_BufferSizeSampleSpin_valueChanged(int arg1)
{
    ui->BufferSizeSlider->setValue(arg1);
    m_ADCParam.BSize_set(arg1);
    histSizeMax_set();
}


void MainWindow::on_BufferSizeSpin_valueChanged(double arg1)
{
    ui->BufferSizeSampleSpin->setValue(static_cast<double>(arg1*SampleRateVals[ui->SampleRateCombo->currentIndex()]*1e3));
    m_ADCParam.BSize_set(arg1);
    histSizeMax_set();
}


void MainWindow::on_CHSelectSpin_valueChanged(int arg1)
{
    for(auto i = 0; i<CHTotalNum; i++)
    {
        ui->CHTabWidget->setTabEnabled(i, i<arg1);
    }
    m_ADCParam.ChNum_set(arg1-1);
}


void MainWindow::on_OKButton_clicked()
{
    exit(0);
}


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Регулирование размера предыстории
void MainWindow::on_HistSizeSpin_valueChanged(double arg1)
{
    ui->HistSizeSampleSpin->setValue(static_cast<double>(arg1*SampleRateVals[ui->SampleRateCombo->currentIndex()]*1e3));
    m_ADCParam.HSize_set(arg1);
}


void MainWindow::on_HistSizeSlider_valueChanged(int value)
{
    ui->HistSizeSampleSpin->setValue(value);
    m_ADCParam.HSize_set(value);
    ui->HistSizeSpin->setValue(value/SampleRateVals[ui->SampleRateCombo->currentIndex()]*1e-3);
}


void MainWindow::on_HistSizeSampleSpin_valueChanged(int arg1)
{
    ui->HistSizeSlider->setValue(arg1);
    m_ADCParam.HSize_set(arg1);
}





// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Пользовательские функции
void MainWindow::histSizeMax_set()
{
    histSizeSampleMax = round(HistSizeSampleMaxCoef * ui->BufferSizeSampleSpin->value());
    ui->HistSizeSampleSpin->setMaximum(histSizeSampleMax);
    ui->HistSizeSlider->setMaximum(histSizeSampleMax);
}




// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка однократного ручного запуска
void MainWindow::on_manualStartButton_clicked()
{
    // однократный запуск
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Переключатель совпадения параметров каналов
void MainWindow::on_SameChParamCheck_toggled(bool checked)
{
    // одинакковые параметры всех каналов
}

