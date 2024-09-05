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

    double k1 = pMainWindow->pADCParam_get()->CHParam_get()->at(0).k1_get();
    ui->k1SpinBox->setValue(k1);
    double k2 = pMainWindow->pADCParam_get()->CHParam_get()->at(0).k2_get();
    ui->k2SpinBox->setValue(k2);
    double k3 = pMainWindow->pADCParam_get()->CHParam_get()->at(0).k3_get();
    ui->k3SpinBox->setValue(k3);
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

    for(auto& ch : *(pMainWindow->pADCParam_get()->CHParam_get()))
    {
        ch.k1k2k3_set(k1, k2, k3);
    }

    close();
}


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Кнопка отклонения изменения и закрытия окна
void CTRecMeasLoopParamDlg::on_CancelButton_clicked()
{
    close();
}

