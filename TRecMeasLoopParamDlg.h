#ifndef TRECMEASLOOPPARAMDLG_H
#define TRECMEASLOOPPARAMDLG_H

#include <QDialog>

inline constexpr double SpinMaxVal = 99999.9;


namespace Ui {
class CTRecMeasLoopParamDlg;
}

class CTRecMeasLoopParamDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CTRecMeasLoopParamDlg(QWidget *parent = nullptr);
    ~CTRecMeasLoopParamDlg();

private slots:
    void on_OKButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::CTRecMeasLoopParamDlg *ui;
};

#endif // TRECMEASLOOPPARAMDLG_H
