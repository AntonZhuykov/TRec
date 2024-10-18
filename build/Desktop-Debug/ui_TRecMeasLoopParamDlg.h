/********************************************************************************
** Form generated from reading UI file 'TRecMeasLoopParamDlg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRECMEASLOOPPARAMDLG_H
#define UI_TRECMEASLOOPPARAMDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTRecMeasLoopParamDlg
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mainButtonLayout;
    QPushButton *CancelButton;
    QPushButton *OKButton;
    QLabel *SchemeLabel;
    QGroupBox *CoefGroupBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *CoefLayout;
    QLabel *k1Label;
    QDoubleSpinBox *k1SpinBox;
    QLabel *k2Label;
    QDoubleSpinBox *k2SpinBox;
    QLabel *k3Label;
    QDoubleSpinBox *k3SpinBox;
    QLabel *EqCoefBanner;
    QLabel *EqCoefLabel;
    QLabel *EqCoefValue;

    void setupUi(QDialog *CTRecMeasLoopParamDlg)
    {
        if (CTRecMeasLoopParamDlg->objectName().isEmpty())
            CTRecMeasLoopParamDlg->setObjectName("CTRecMeasLoopParamDlg");
        CTRecMeasLoopParamDlg->resize(640, 350);
        horizontalLayoutWidget = new QWidget(CTRecMeasLoopParamDlg);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(390, 290, 241, 41));
        mainButtonLayout = new QHBoxLayout(horizontalLayoutWidget);
        mainButtonLayout->setObjectName("mainButtonLayout");
        mainButtonLayout->setContentsMargins(0, 0, 0, 0);
        CancelButton = new QPushButton(horizontalLayoutWidget);
        CancelButton->setObjectName("CancelButton");

        mainButtonLayout->addWidget(CancelButton);

        OKButton = new QPushButton(horizontalLayoutWidget);
        OKButton->setObjectName("OKButton");

        mainButtonLayout->addWidget(OKButton);

        SchemeLabel = new QLabel(CTRecMeasLoopParamDlg);
        SchemeLabel->setObjectName("SchemeLabel");
        SchemeLabel->setGeometry(QRect(9, 20, 615, 140));
        CoefGroupBox = new QGroupBox(CTRecMeasLoopParamDlg);
        CoefGroupBox->setObjectName("CoefGroupBox");
        CoefGroupBox->setGeometry(QRect(9, 170, 621, 71));
        horizontalLayoutWidget_2 = new QWidget(CoefGroupBox);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 30, 601, 31));
        CoefLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        CoefLayout->setObjectName("CoefLayout");
        CoefLayout->setContentsMargins(0, 0, 0, 0);
        k1Label = new QLabel(horizontalLayoutWidget_2);
        k1Label->setObjectName("k1Label");

        CoefLayout->addWidget(k1Label);

        k1SpinBox = new QDoubleSpinBox(horizontalLayoutWidget_2);
        k1SpinBox->setObjectName("k1SpinBox");

        CoefLayout->addWidget(k1SpinBox);

        k2Label = new QLabel(horizontalLayoutWidget_2);
        k2Label->setObjectName("k2Label");

        CoefLayout->addWidget(k2Label);

        k2SpinBox = new QDoubleSpinBox(horizontalLayoutWidget_2);
        k2SpinBox->setObjectName("k2SpinBox");

        CoefLayout->addWidget(k2SpinBox);

        k3Label = new QLabel(horizontalLayoutWidget_2);
        k3Label->setObjectName("k3Label");

        CoefLayout->addWidget(k3Label);

        k3SpinBox = new QDoubleSpinBox(horizontalLayoutWidget_2);
        k3SpinBox->setObjectName("k3SpinBox");

        CoefLayout->addWidget(k3SpinBox);

        EqCoefBanner = new QLabel(CTRecMeasLoopParamDlg);
        EqCoefBanner->setObjectName("EqCoefBanner");
        EqCoefBanner->setGeometry(QRect(10, 265, 331, 18));
        EqCoefLabel = new QLabel(CTRecMeasLoopParamDlg);
        EqCoefLabel->setObjectName("EqCoefLabel");
        EqCoefLabel->setGeometry(QRect(10, 290, 41, 18));
        EqCoefValue = new QLabel(CTRecMeasLoopParamDlg);
        EqCoefValue->setObjectName("EqCoefValue");
        EqCoefValue->setGeometry(QRect(50, 290, 61, 20));
        QFont font;
        font.setBold(false);
        EqCoefValue->setFont(font);

        retranslateUi(CTRecMeasLoopParamDlg);

        QMetaObject::connectSlotsByName(CTRecMeasLoopParamDlg);
    } // setupUi

    void retranslateUi(QDialog *CTRecMeasLoopParamDlg)
    {
        CTRecMeasLoopParamDlg->setWindowTitle(QCoreApplication::translate("CTRecMeasLoopParamDlg", "Dialog", nullptr));
        CancelButton->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "PushButton", nullptr));
        OKButton->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "PushButton", nullptr));
        SchemeLabel->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "TextLabel", nullptr));
        CoefGroupBox->setTitle(QCoreApplication::translate("CTRecMeasLoopParamDlg", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\321\213 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\271 \321\206\320\265\320\277\320\270", nullptr));
        k1Label->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "k\342\202\201 = ", nullptr));
        k2Label->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "k\342\202\202 = ", nullptr));
        k3Label->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "k\342\202\203 = ", nullptr));
        EqCoefBanner->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "\320\255\320\272\320\262\320\270\320\262\320\260\320\273\320\265\320\275\321\202\320\275\321\213\320\271 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\264\320\265\320\273\320\265\320\275\320\270\321\217:", nullptr));
        EqCoefLabel->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "k\342\202\201\342\202\202\342\202\203 = ", nullptr));
        EqCoefValue->setText(QCoreApplication::translate("CTRecMeasLoopParamDlg", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CTRecMeasLoopParamDlg: public Ui_CTRecMeasLoopParamDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRECMEASLOOPPARAMDLG_H
