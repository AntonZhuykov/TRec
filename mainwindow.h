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
#include <QTcpSocket>
#include <vector>


enum class TRecStatus { NOTCONNECTED,   // АЦП не подключен
                        STANDBY,        // режим ожидания: АЦП подключен, измерения не выполняются
                        ACQUISITION,    // режим измерений (ожидания срабатывания триггера)
                        IMPORT,         // прием данных с платы АЦП
                        };
inline constexpr const char* StatusLabels[] =
    {   "нет соединения с платой АЦП", "плата АЦП подключена, режим ожидания",
        "режим измерений (ожидания срабатывания триггера)",
        "прием данных с платы АЦП"
    };

inline constexpr const char* ADCConnectButtonLabels[] =
    { "Соединить\nс АЦП", "Разорвать\nканал"};


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
    void status_set(TRecStatus status);
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
    void on_ADCConnectButton_clicked();
    void ADCSocketRead();
    void connectSuccessDisplay();
    void connectErrorDisplay(QAbstractSocket::SocketError);
    void disconnectSuccessDisplay();

    void on_StartButton_clicked();

    void on_StopButton_clicked();

private:
    Ui::MainWindow *ui;
    TRecStatus m_status;
    CTRecADC m_ADC;

    QLabel* m_pStatusLabel;
    CTRecMeasLoopParamDlg* m_pMeasLoopParamDlg;
    QPushButton* m_pConnectButton;
    QIcon m_ConnectButtonIcon;
    QIcon m_DisconnectButtonIcon;
    CTRecIPEditBox* m_pIPEdit;
    QLineEdit* m_pPortEdit;
    QTcpSocket m_TcpSocket;

    int histSizeSampleMax;
    vector<class CTRecADCChParamWidgets*> pChWidgets_vec;
};
#endif // MAINWINDOW_H
