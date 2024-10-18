#include "TRecMeasLoopParamDlg.h"
#include "mainwindow.h"
#include "ui_TRecMeasLoopParamDlg.h"
#include <QPixmap>

CTRecMeasLoopParamDlg::CTRecMeasLoopParamDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CTRecMeasLoopParamDlg)
{
    ui->setupUi(this);

    // Указатель на родительское окно (главное окно программы)
    MainWindow* pMainWindow = ((MainWindow*)parentWidget());

    // Параметры кнопок
    ui->OKButton->setText("Применить");
    QIcon OKButtonIcon("..//..//Res//Apply.svg");
    ui->OKButton->setIcon(OKButtonIcon);

    ui->CancelButton->setText("Отменить");
    QIcon CancelButtonIcon("..//..//Res//Cancel.svg");
    ui->CancelButton->setIcon(CancelButtonIcon);

    // Схема измерительной цепи
    QPixmap SchemeSVG("..//..//Res//measloop.svg");
    ui->SchemeLabel->setPixmap(SchemeSVG);

    // Виджеты задания зн-й коэффициентов
    ui->CoefLayout->insertStretch(2, 2);
    ui->CoefLayout->insertStretch(5, 2);

    ui->k1SpinBox->setMaximum(SpinMaxVal);
    ui->k2SpinBox->setMaximum(SpinMaxVal);
    ui->k3SpinBox->setMaximum(SpinMaxVal);
    ui->k3SpinBox->setSingleStep(0.1);

    vector<class CTRecADCChParam>* pADCChParam_vec =
        pMainWindow->pADC_get()->ADCParam_get()->CHParam_get();

    double k1 = pADCChParam_vec->at(0).k1_get();
    ui->k1SpinBox->setValue(k1);
    double k2 = pADCChParam_vec->at(0).k2_get();
    ui->k2SpinBox->setValue(k2);
    double k3 = pADCChParam_vec->at(0).k3_get();
    ui->k3SpinBox->setValue(k3);
    double k123 = pADCChParam_vec->at(0).ratio_get();
    ui->EqCoefValue->setNum(k123);
}

CTRecMeasLoopParamDlg::~CTRecMeasLoopParamDlg()
{
    delete ui;
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка принятия изменения и закрытия окна
void CTRecMeasLoopParamDlg::on_OKButton_clicked()
{
    MainWindow* pMainWindow = ((MainWindow*)parentWidget());

    double k1 = ui->k1SpinBox->value();
    double k2 = ui->k2SpinBox->value();
    double k3 = ui->k3SpinBox->value();

    for(auto& ch : *(pMainWindow->pADC_get()->ADCParam_get()->CHParam_get()))
    {
        ch.k1k2k3_set(k1, k2, k3);
    }

    this->done(0);
}


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка отклонения изменения и закрытия окна
void CTRecMeasLoopParamDlg::on_CancelButton_clicked()
{
    this->done(1);
}



// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Регулирование значений коэффициентов
void CTRecMeasLoopParamDlg::on_k1SpinBox_valueChanged(double arg1)
{
    double k123 = arg1 * ui->k2SpinBox->value() * ui->k3SpinBox->value();
    ui->EqCoefValue->setNum(k123);
}


void CTRecMeasLoopParamDlg::on_k2SpinBox_valueChanged(double arg1)
{
    double k123 = ui->k1SpinBox->value() * arg1 * ui->k3SpinBox->value();
    ui->EqCoefValue->setNum(k123);
}


void CTRecMeasLoopParamDlg::on_k3SpinBox_valueChanged(double arg1)
{
    double k123 = ui->k1SpinBox->value() * ui->k2SpinBox->value() * arg1;
    ui->EqCoefValue->setNum(k123);
}

