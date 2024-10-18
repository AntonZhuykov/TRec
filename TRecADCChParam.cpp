#include "TRecADCChParam.h"

/******************************************************* класс CTRecADCChTrigger
********************************************************************************/
CTRecADCChTrigger::CTRecADCChTrigger()
{
    m_triggerMode = EdgeTriggerModes::RISING;
    m_triggerPolarity = TriggerPolarity::POSITIVE;
    m_triggerCent = triggerCentDefault;
}

CTRecADCChTrigger::~CTRecADCChTrigger()
{

}

CTRecADCChTrigger::CTRecADCChTrigger(const int level, const EdgeTriggerModes mode,
                                     const TriggerPolarity polarity)
{
    m_triggerMode = mode;
    m_triggerPolarity = polarity;
    m_triggerCent = level;
}

CTRecADCChTrigger& CTRecADCChTrigger::operator=(const CTRecADCChTrigger& Obj)
{
    if(this == &Obj)
        return *this;

    m_triggerMode = Obj.m_triggerMode;
    m_triggerPolarity = Obj.m_triggerPolarity;
    m_triggerCent = Obj.m_triggerCent;

    return *this;
}





/********************************************************* класс CTRecADCChParam
********************************************************************************/

CTRecADCChParam::CTRecADCChParam()
{
    m_ind = 0;
    m_OnOff = true;
    m_OnOffTrigger = true;
    m_rangeLim = chRangeLimDefault;
    m_k1 = k1Default;
    m_k2 = k2Default;
    m_k3 = k3Default;
    m_ratio = k1Default * k2Default * k3Default;
}

CTRecADCChParam::~CTRecADCChParam()
{

}

CTRecADCChParam& CTRecADCChParam::operator=(const CTRecADCChParam& Obj)
{
    if(this == &Obj)
        return *this;

    m_ind = Obj.m_ind;
    m_OnOff = Obj.m_OnOff;
    m_OnOffTrigger = Obj.m_OnOffTrigger;
    m_rangeLim = Obj.m_rangeLim;
    m_k1 = Obj.m_k1;
    m_k2 = Obj.m_k2;
    m_k3 = Obj.m_k3;
    m_ratio = Obj.m_ratio;

    return *this;
}


void CTRecADCChParam::k1k2k3_set(const double& k1, const double& k2, const double& k3)
{
    m_k1 = k1;
    m_k2 = k2;
    m_k3 = k3;
    ratio_recalc();
}


void CTRecADCChParam::ratio_recalc()
{
    m_ratio = m_k1 * m_k2 * m_k3;
}



double CTRecADCChParam::triggerKV_get() const
{
    return (1e-3 * m_rangeLim * m_ratio * (1e-2*double(m_trigger.m_triggerCent)));
}


