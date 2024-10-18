/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *CancelButton;
    QPushButton *OKButton;
    QWidget *gridLayoutWidget;
    QGridLayout *CHGrid;
    QLabel *CHSelectLabel;
    QSpinBox *CHSelectSpin;
    QWidget *gridLayoutWidget_2;
    QGridLayout *CommonParamGrid;
    QLabel *SampleRateLabel;
    QComboBox *SampleRateCombo;
    QLabel *SampleRateUnitLabel;
    QPushButton *manualStartButton;
    QWidget *gridLayoutWidget_3;
    QGridLayout *SaveFolderGrid;
    QLabel *SaveFolderLabel;
    QGroupBox *BufferSizeGroupbox;
    QWidget *gridLayoutWidget_4;
    QGridLayout *BufferGrid;
    QLabel *BufferSizeSampleUnitLabel;
    QLabel *BufferSizeUnitLabel;
    QSpinBox *BufferSizeSampleSpin;
    QSlider *BufferSizeSlider;
    QDoubleSpinBox *BufferSizeSpin;
    QGroupBox *HistSizeGroupbox;
    QWidget *gridLayoutWidget_5;
    QGridLayout *HistGrid;
    QSpinBox *HistSizeSampleSpin;
    QLabel *HistSizeUnitLabel;
    QLabel *HistSizeSampleUnitLabel;
    QDoubleSpinBox *HistSizeSpin;
    QSlider *HistSizeSlider;
    QCheckBox *SameChParamCheck;
    QGroupBox *RatioGroupbox;
    QWidget *gridLayoutWidget_6;
    QGridLayout *RatioGrid;
    QLabel *RatioLabel;
    QPushButton *RatioSetButton;
    QLabel *RatioValue;
    QTabWidget *CHTabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QGroupBox *IPAddressGroupbox;
    QWidget *gridLayoutWidget_7;
    QGridLayout *IPAddressGrid;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(47, 43, 55, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(246, 245, 244, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(222, 221, 218, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(154, 153, 150, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(61, 56, 70, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush4);
        QBrush brush5(QColor(79, 16, 16, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        QBrush brush6(QColor(239, 239, 239, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        QBrush brush7(QColor(119, 118, 123, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        QBrush brush8(QColor(183, 5, 15, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        QBrush brush9(QColor(255, 255, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush9);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        QBrush brush10(QColor(0, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        QBrush brush11(QColor(202, 202, 202, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        QBrush brush12(QColor(159, 159, 159, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        QBrush brush13(QColor(118, 118, 118, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush13);
        QBrush brush14(QColor(48, 140, 198, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush14);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush9);
        QBrush brush15(QColor(247, 247, 247, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        QBrush brush16(QColor(177, 177, 177, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush16);
        QBrush brush17(QColor(145, 145, 145, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush17);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush15);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(560, 540, 221, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(8);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        CancelButton = new QPushButton(horizontalLayoutWidget);
        CancelButton->setObjectName("CancelButton");
        CancelButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(CancelButton);

        OKButton = new QPushButton(horizontalLayoutWidget);
        OKButton->setObjectName("OKButton");
        OKButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(OKButton);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 220, 321, 31));
        CHGrid = new QGridLayout(gridLayoutWidget);
        CHGrid->setObjectName("CHGrid");
        CHGrid->setContentsMargins(0, 0, 0, 0);
        CHSelectLabel = new QLabel(gridLayoutWidget);
        CHSelectLabel->setObjectName("CHSelectLabel");

        CHGrid->addWidget(CHSelectLabel, 0, 0, 2, 1);

        CHSelectSpin = new QSpinBox(gridLayoutWidget);
        CHSelectSpin->setObjectName("CHSelectSpin");

        CHGrid->addWidget(CHSelectSpin, 0, 1, 2, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(380, 110, 401, 31));
        CommonParamGrid = new QGridLayout(gridLayoutWidget_2);
        CommonParamGrid->setObjectName("CommonParamGrid");
        CommonParamGrid->setContentsMargins(0, 0, 0, 0);
        SampleRateLabel = new QLabel(gridLayoutWidget_2);
        SampleRateLabel->setObjectName("SampleRateLabel");
        SampleRateLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        CommonParamGrid->addWidget(SampleRateLabel, 0, 0, 1, 3);

        SampleRateCombo = new QComboBox(gridLayoutWidget_2);
        SampleRateCombo->setObjectName("SampleRateCombo");

        CommonParamGrid->addWidget(SampleRateCombo, 0, 3, 1, 1);

        SampleRateUnitLabel = new QLabel(gridLayoutWidget_2);
        SampleRateUnitLabel->setObjectName("SampleRateUnitLabel");

        CommonParamGrid->addWidget(SampleRateUnitLabel, 0, 4, 1, 1);

        manualStartButton = new QPushButton(centralwidget);
        manualStartButton->setObjectName("manualStartButton");
        manualStartButton->setGeometry(QRect(560, 440, 221, 51));
        manualStartButton->setIconSize(QSize(36, 36));
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(380, 360, 401, 51));
        SaveFolderGrid = new QGridLayout(gridLayoutWidget_3);
        SaveFolderGrid->setObjectName("SaveFolderGrid");
        SaveFolderGrid->setContentsMargins(0, 0, 0, 0);
        SaveFolderLabel = new QLabel(gridLayoutWidget_3);
        SaveFolderLabel->setObjectName("SaveFolderLabel");

        SaveFolderGrid->addWidget(SaveFolderLabel, 0, 0, 1, 1);

        BufferSizeGroupbox = new QGroupBox(centralwidget);
        BufferSizeGroupbox->setObjectName("BufferSizeGroupbox");
        BufferSizeGroupbox->setGeometry(QRect(380, 150, 401, 92));
        gridLayoutWidget_4 = new QWidget(BufferSizeGroupbox);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 381, 71));
        BufferGrid = new QGridLayout(gridLayoutWidget_4);
        BufferGrid->setObjectName("BufferGrid");
        BufferGrid->setVerticalSpacing(20);
        BufferGrid->setContentsMargins(0, 0, 0, 0);
        BufferSizeSampleUnitLabel = new QLabel(gridLayoutWidget_4);
        BufferSizeSampleUnitLabel->setObjectName("BufferSizeSampleUnitLabel");

        BufferGrid->addWidget(BufferSizeSampleUnitLabel, 0, 4, 1, 1);

        BufferSizeUnitLabel = new QLabel(gridLayoutWidget_4);
        BufferSizeUnitLabel->setObjectName("BufferSizeUnitLabel");

        BufferGrid->addWidget(BufferSizeUnitLabel, 0, 2, 1, 1);

        BufferSizeSampleSpin = new QSpinBox(gridLayoutWidget_4);
        BufferSizeSampleSpin->setObjectName("BufferSizeSampleSpin");

        BufferGrid->addWidget(BufferSizeSampleSpin, 0, 3, 1, 1);

        BufferSizeSlider = new QSlider(gridLayoutWidget_4);
        BufferSizeSlider->setObjectName("BufferSizeSlider");
        BufferSizeSlider->setOrientation(Qt::Horizontal);

        BufferGrid->addWidget(BufferSizeSlider, 1, 0, 1, 5);

        BufferSizeSpin = new QDoubleSpinBox(gridLayoutWidget_4);
        BufferSizeSpin->setObjectName("BufferSizeSpin");

        BufferGrid->addWidget(BufferSizeSpin, 0, 0, 1, 2);

        HistSizeGroupbox = new QGroupBox(centralwidget);
        HistSizeGroupbox->setObjectName("HistSizeGroupbox");
        HistSizeGroupbox->setGeometry(QRect(379, 253, 401, 92));
        gridLayoutWidget_5 = new QWidget(HistSizeGroupbox);
        gridLayoutWidget_5->setObjectName("gridLayoutWidget_5");
        gridLayoutWidget_5->setGeometry(QRect(10, 23, 381, 71));
        HistGrid = new QGridLayout(gridLayoutWidget_5);
        HistGrid->setObjectName("HistGrid");
        HistGrid->setHorizontalSpacing(6);
        HistGrid->setVerticalSpacing(20);
        HistGrid->setContentsMargins(0, 0, 0, 0);
        HistSizeSampleSpin = new QSpinBox(gridLayoutWidget_5);
        HistSizeSampleSpin->setObjectName("HistSizeSampleSpin");

        HistGrid->addWidget(HistSizeSampleSpin, 0, 2, 1, 1);

        HistSizeUnitLabel = new QLabel(gridLayoutWidget_5);
        HistSizeUnitLabel->setObjectName("HistSizeUnitLabel");

        HistGrid->addWidget(HistSizeUnitLabel, 0, 1, 1, 1);

        HistSizeSampleUnitLabel = new QLabel(gridLayoutWidget_5);
        HistSizeSampleUnitLabel->setObjectName("HistSizeSampleUnitLabel");

        HistGrid->addWidget(HistSizeSampleUnitLabel, 0, 3, 1, 1);

        HistSizeSpin = new QDoubleSpinBox(gridLayoutWidget_5);
        HistSizeSpin->setObjectName("HistSizeSpin");

        HistGrid->addWidget(HistSizeSpin, 0, 0, 1, 1);

        HistSizeSlider = new QSlider(gridLayoutWidget_5);
        HistSizeSlider->setObjectName("HistSizeSlider");
        HistSizeSlider->setOrientation(Qt::Horizontal);

        HistGrid->addWidget(HistSizeSlider, 1, 0, 1, 4);

        SameChParamCheck = new QCheckBox(centralwidget);
        SameChParamCheck->setObjectName("SameChParamCheck");
        SameChParamCheck->setGeometry(QRect(20, 260, 321, 24));
        QFont font;
        font.setPointSize(10);
        SameChParamCheck->setFont(font);
        RatioGroupbox = new QGroupBox(centralwidget);
        RatioGroupbox->setObjectName("RatioGroupbox");
        RatioGroupbox->setGeometry(QRect(380, 30, 401, 68));
        gridLayoutWidget_6 = new QWidget(RatioGroupbox);
        gridLayoutWidget_6->setObjectName("gridLayoutWidget_6");
        gridLayoutWidget_6->setGeometry(QRect(9, 30, 381, 31));
        RatioGrid = new QGridLayout(gridLayoutWidget_6);
        RatioGrid->setObjectName("RatioGrid");
        RatioGrid->setVerticalSpacing(6);
        RatioGrid->setContentsMargins(0, 0, 0, 0);
        RatioLabel = new QLabel(gridLayoutWidget_6);
        RatioLabel->setObjectName("RatioLabel");

        RatioGrid->addWidget(RatioLabel, 0, 0, 1, 1);

        RatioSetButton = new QPushButton(gridLayoutWidget_6);
        RatioSetButton->setObjectName("RatioSetButton");
        RatioSetButton->setIconSize(QSize(24, 24));

        RatioGrid->addWidget(RatioSetButton, 0, 2, 1, 1);

        RatioValue = new QLabel(gridLayoutWidget_6);
        RatioValue->setObjectName("RatioValue");

        RatioGrid->addWidget(RatioValue, 0, 1, 1, 1);

        CHTabWidget = new QTabWidget(centralwidget);
        CHTabWidget->setObjectName("CHTabWidget");
        CHTabWidget->setGeometry(QRect(20, 295, 321, 261));
        tab = new QWidget();
        tab->setObjectName("tab");
        CHTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        CHTabWidget->addTab(tab_2, QString());
        IPAddressGroupbox = new QGroupBox(centralwidget);
        IPAddressGroupbox->setObjectName("IPAddressGroupbox");
        IPAddressGroupbox->setGeometry(QRect(20, 30, 321, 131));
        QFont font1;
        font1.setPointSize(11);
        IPAddressGroupbox->setFont(font1);
        gridLayoutWidget_7 = new QWidget(IPAddressGroupbox);
        gridLayoutWidget_7->setObjectName("gridLayoutWidget_7");
        gridLayoutWidget_7->setGeometry(QRect(9, 30, 301, 91));
        IPAddressGrid = new QGridLayout(gridLayoutWidget_7);
        IPAddressGrid->setObjectName("IPAddressGrid");
        IPAddressGrid->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        CHTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CancelButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        OKButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        CHSelectLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        SampleRateLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        SampleRateUnitLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        manualStartButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        SaveFolderLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \320\276\321\201\321\206\320\270\320\273\320\273\320\276\320\263\321\200\320\260\320\274\320\274:", nullptr));
        BufferSizeGroupbox->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        BufferSizeSampleUnitLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        BufferSizeUnitLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        HistSizeGroupbox->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\277\321\200\320\265\320\264\320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        HistSizeUnitLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        HistSizeSampleUnitLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        SameChParamCheck->setText(QCoreApplication::translate("MainWindow", "\320\276\320\264\320\270\320\275\320\260\320\272\320\276\320\262\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\262\321\201\320\265\321\205 \320\272\320\260\320\275\320\260\320\273\320\276\320\262", nullptr));
        RatioGroupbox->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\264\320\265\320\273\320\265\320\275\320\270\321\217", nullptr));
        RatioLabel->setText(QCoreApplication::translate("MainWindow", "k\342\202\201\342\202\202\342\202\203 = ", nullptr));
        RatioSetButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        RatioValue->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        CHTabWidget->setTabText(CHTabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        CHTabWidget->setTabText(CHTabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        IPAddressGroupbox->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\201\320\262\321\217\320\267\320\270 \321\201 \320\220\320\246\320\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
