#include "TRecADCChParamWidgets.h"


CTRecADCChParamWidgets::CTRecADCChParamWidgets()
{
    pChParam = nullptr;
    pApplyCheck = nullptr;
    pTriggerCheck = nullptr;
    pTriggerGroup = nullptr;
    pTriggerSlider = nullptr;
    pTriggerSpin = nullptr;
    pTriggerValKV = nullptr;
    pTriggerModeGroup = nullptr;
    pTriggerPolarityGroup = nullptr;
}


CTRecADCChParamWidgets::~CTRecADCChParamWidgets()
{

}


CTRecADCChParamWidgets::CTRecADCChParamWidgets(CTRecADCChParam* pParam, QWidget* pParent)
    : QWidget(pParent)
{
    pChParam = pParam;

    QRect tmpQRect = pParent->rect();

    pApplyCheck = new QCheckBox("задействовать канал", this);
    pApplyCheck->setGeometry(WidgetBorder, WidgetSpace,
                               tmpQRect.width()-50, CheckboxHeight);
    pApplyCheck->setChecked(pChParam->OnOff_get());
    connect(pApplyCheck, &QCheckBox::stateChanged, this,
            &CTRecADCChParamWidgets::on_ChApplyCheck);


    pTriggerCheck = new QCheckBox("выставить триггер", this);
    pTriggerCheck->setGeometry(WidgetBorder, 2*WidgetSpace+CheckboxHeight,
                                 tmpQRect.width()-50, CheckboxHeight);
    pTriggerCheck->setChecked(pChParam->OnOffTrigger_get());
    connect(pTriggerCheck, &QCheckBox::stateChanged, this,
            &CTRecADCChParamWidgets::on_ChTriggerCheck);


    pTriggerGroup = new QGroupBox("Настройки триггера", this);
    pTriggerGroup->setGeometry(WidgetBorder,
                               2*WidgetSpace+2*CheckboxHeight+GroupboxTopSpace,
                               tmpQRect.width()-21,
                               tmpQRect.height()-(2*WidgetSpace+2*CheckboxHeight+3*GroupboxTopSpace));


    pTriggerSlider = new QSlider(Qt::Horizontal, pTriggerGroup);
    pTriggerSlider->setGeometry(WidgetBorder, 20+GroupboxTopSpace,
                         TriggerSliderWidth, CheckboxHeight);
    pTriggerSlider->setMinimum(triggerCentMin);
    pTriggerSlider->setMaximum(triggerCentMax);
    pTriggerSlider->setValue(pChParam->trigger_get().m_triggerCent);


    QRect groupboxRect = pTriggerGroup->rect();
    pTriggerSpin = new QSpinBox(pTriggerGroup);
    pTriggerSpin->setGeometry(WidgetBorder+TriggerSliderWidth+WidgetSpace,
                               13+GroupboxTopSpace,
                               TriggerSpinWidth,
                               SpinboxHeight);
    pTriggerSpin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    pTriggerSpin->setMinimum(triggerCentMin);
    pTriggerSpin->setMaximum(triggerCentMax);
    pTriggerSpin->setValue(pChParam->trigger_get().m_triggerCent);

    connect(pTriggerSlider, &QSlider::valueChanged, pTriggerSpin, &QSpinBox::setValue);
    connect(pTriggerSpin, &QSpinBox::valueChanged, pTriggerSlider, &QSlider::setValue);
    connect(pTriggerSlider, &QSlider::valueChanged, this, &CTRecADCChParamWidgets::on_ChTriggerSlider);


    QLabel* pUnitLabelCents = new QLabel("%", pTriggerGroup);
    pUnitLabelCents->setGeometry((WidgetBorder+TriggerSliderWidth+WidgetSpace+TriggerSpinWidth)+4,
                                    13+GroupboxTopSpace,
                                    15,
                                    SpinboxHeight);


    pTriggerValKV = new QLabel(pTriggerGroup);
    pTriggerValKV->setGeometry(groupboxRect.width()-71,
                              13+GroupboxTopSpace,
                              40,
                              SpinboxHeight);
    pTriggerValKV->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    pTriggerValKV->setNum(pChParam->triggerKV_get());


    QLabel* pUnitLabelKV = new QLabel("кВ", pTriggerGroup);
    pUnitLabelKV->setGeometry(groupboxRect.width()-27,
                            13+GroupboxTopSpace,
                            18,
                            SpinboxHeight);



    pTriggerModeGroup = new QButtonGroup(pTriggerGroup);
    int radioGroupWidth = int(0.45*groupboxRect.width());
    int numRadio = sizeof(EdgeTriggerModeLabels) / sizeof(EdgeTriggerModeLabels[0]);
    int currentTriggerMode = static_cast<int>(pChParam->trigger_get().m_triggerMode);
    for(auto i=0; i<numRadio; i++)
    {
        QRadioButton* pRadioMode = new QRadioButton(EdgeTriggerModeLabels[i], pTriggerGroup);
        pRadioMode->setGeometry(WidgetBorder,
                                20+GroupboxTopSpace+(i+1)*CheckboxHeight+(i+2)*WidgetSpace,
                                 radioGroupWidth, CheckboxHeight);
        if(i == currentTriggerMode)
            pRadioMode->setChecked(true);
        pTriggerModeGroup->addButton(pRadioMode);
        pTriggerModeGroup->setId(pRadioMode,i);
    }
    connect(pTriggerModeGroup, &QButtonGroup::idClicked,
            this, &CTRecADCChParamWidgets::on_ChTriggerMode);



    pTriggerPolarityGroup = new QButtonGroup(pTriggerGroup);
    numRadio = sizeof(TriggerPolarityLabels) / sizeof(TriggerPolarityLabels[0]);
    int currentTriggerPolarity = static_cast<int>(pChParam->trigger_get().m_triggerPolarity);
    for(auto i=0; i<numRadio; i++)
    {
        QRadioButton* pRadioMode = new QRadioButton(TriggerPolarityLabels[i], pTriggerGroup);
        pRadioMode->setGeometry(WidgetBorder+radioGroupWidth,
                                20+GroupboxTopSpace+(i+1)*CheckboxHeight+(i+2)*WidgetSpace,
                                radioGroupWidth, CheckboxHeight);
        if(i == currentTriggerPolarity)
            pRadioMode->setChecked(true);
        pTriggerPolarityGroup->addButton(pRadioMode);
        pTriggerPolarityGroup->setId(pRadioMode,i);
    }
    connect(pTriggerPolarityGroup, &QButtonGroup::idClicked,
            this, &CTRecADCChParamWidgets::on_ChTriggerPolarity);
}




CTRecADCChParamWidgets& CTRecADCChParamWidgets::operator=(const CTRecADCChParamWidgets& Obj)
{
    if(this == &Obj)
        return *this;

    pChParam = Obj.pChParam;
    pApplyCheck = Obj.pApplyCheck;
    pTriggerCheck = Obj.pTriggerCheck;
    pTriggerGroup = Obj.pTriggerGroup;
    pTriggerSlider = Obj.pTriggerSlider;
    pTriggerSpin = Obj.pTriggerSpin;
    pTriggerValKV = Obj.pTriggerValKV;
    pTriggerModeGroup = Obj.pTriggerModeGroup;
    pTriggerPolarityGroup = Obj.pTriggerPolarityGroup;

    return *this;
}




void CTRecADCChParamWidgets::ChTriggerValkv_update()
{
    QString tmp;
    pTriggerValKV->setText(tmp.setNum(pChParam->triggerKV_get(), 'g', 4));
}




// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Чекбокс задействования измерительного канала
void CTRecADCChParamWidgets::on_ChApplyCheck(int value)
{
    pChParam->OnOff_set(value ? true : false);
}



// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Чекбокс задействования запуска по триггеру по сигналу канала
void CTRecADCChParamWidgets::on_ChTriggerCheck(int value)
{
    pChParam->OnOffTrigger_set(value ? true : false);
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Регулирование уровня триггера
void CTRecADCChParamWidgets::on_ChTriggerSlider(int value)
{
    pChParam->triggerCent_set(value);
    ChTriggerValkv_update();
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Задание режима триггера
void CTRecADCChParamWidgets::on_ChTriggerMode(int Id)
{
    pChParam->triggerMode_set(static_cast<EdgeTriggerModes>(Id));
}



// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ============================================= Задание полярности триггера
void CTRecADCChParamWidgets::on_ChTriggerPolarity(int Id)
{
    pChParam->triggerPolarity_set(static_cast<TriggerPolarity>(Id));
}


