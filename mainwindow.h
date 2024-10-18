#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TRecMeasLoopParamDlg.h"
#include "TRecADC.h"
#include "TRecADCChParamWidgets.h"
#include "TRecIPEditBox.h"
#include <QCheckBox>
#include <QSlider>
#include <QDoubleSpinBox>
#include <vector>





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
    CTRecADC* pADC_get() {return &m_ADC;}

    // пользовательские функции
    void histSizeMax_set();
    void ChParamChange(int flag);

private slots:
    void on_SampleRateCombo_currentIndexChanged(int index);

    void on_BufferSizeSlider_valueChanged(int value);

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

    void on_MeasLoopParamChanged(int res);

private:
    Ui::MainWindow *ui;
    //CTRecADCParam m_ADCParam;
    CTRecADC m_ADC;
    CTRecMeasLoopParamDlg* m_pMeasLoopParamDlg;

    // пользовательские переменные
    int histSizeSampleMax;
    vector<class CTRecADCChParamWidgets*> pChWidgets_vec;
};
#endif // MAINWINDOW_H
