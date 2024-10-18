#ifndef TRECADCCHPARAMWIDGETS_H
#define TRECADCCHPARAMWIDGETS_H

#include <QCheckBox>
#include <QSlider>
#include <QSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include "TRecADCChParam.h"

inline constexpr int WidgetBorder = 8;
inline constexpr int WidgetSpace = 10;
inline constexpr int CheckboxHeight = 15;
inline constexpr int GroupboxTopSpace = 20;
inline constexpr int TriggerSliderWidth = 140;
inline constexpr int TriggerSpinWidth = 50;
inline constexpr int SpinboxHeight = 28;



class CTRecADCChParamWidgets : public QWidget
{
    Q_OBJECT

public:
    CTRecADCChParamWidgets();
    virtual ~CTRecADCChParamWidgets();
    CTRecADCChParamWidgets(CTRecADCChParam*, QWidget*);
    CTRecADCChParamWidgets& operator=(const CTRecADCChParamWidgets& Obj);

    CTRecADCChParam* pChParam;
    QCheckBox* pApplyCheck;
    QCheckBox* pTriggerCheck;
    QGroupBox* pTriggerGroup;
    QSlider* pTriggerSlider;
    QSpinBox* pTriggerSpin;
    QLabel* pTriggerValKV;
    QButtonGroup* pTriggerModeGroup;
    QButtonGroup* pTriggerPolarityGroup;

    void ChTriggerValkv_update();


private slots:
    void on_ChApplyCheck(int value);
    void on_ChTriggerCheck(int value);
    void on_ChTriggerSlider(int value);
    void on_ChTriggerMode(int Id);
    void on_ChTriggerPolarity(int Id);
};

#endif // TRECADCCHPARAMWIDGETS_H
