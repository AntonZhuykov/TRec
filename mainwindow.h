#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TRecMeasLoopParamDlg.h"
#include "TRecADCParam.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // сетеры-гетеры
    TRecADCParam* pADCParam_get() {return &m_ADCParam;}

    // пользовательские функции
    void histSizeMax_set();

private slots:
    void on_SampleRateCombo_currentIndexChanged(int index);

    void on_BufferSizeSlider_valueChanged(int value);

    void on_BufferSizeSampleSpin_valueChanged(int arg1);

    void on_BufferSizeSpin_valueChanged(double arg1);

    void on_CHSelectSpin_valueChanged(int arg1);

    void on_OKButton_clicked();

    void on_HistSizeSpin_valueChanged(double arg1);

    void on_HistSizeSlider_valueChanged(int value);

    void on_HistSizeSampleSpin_valueChanged(int arg1);

    void on_manualStartButton_clicked();

    void on_SameChParamCheck_toggled(bool checked);

    void on_RatioSetButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::MainWindow *ui;
    TRecADCParam m_ADCParam;
    CTRecMeasLoopParamDlg* m_pMeasLoopParamDlg;

    // пользовательские переменные
    int histSizeSampleMax;
};
#endif // MAINWINDOW_H
