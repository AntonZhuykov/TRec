#include "TRecADCChParam.h"

CTRecADCChParam::CTRecADCChParam()
{
    m_ind = 0;
    m_OnOff = true;
    m_k1 = k1Default;
    m_k2 = k2Default;
    m_k3 = k3Default;
    m_ratio = k1Default * k2Default * k3Default;
    m_triggerType = EdgeTriggerTypes::RISING;
    m_triggerPercent = triggerPercentDefault;
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
    m_k1 = Obj.m_k1;
    m_k2 = Obj.m_k2;
    m_k3 = Obj.m_k3;
    m_ratio = Obj.m_ratio;
    m_triggerType = Obj.m_triggerType;
    m_triggerPercent = Obj.m_triggerPercent;

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


