#include "TRecADC.h"

CTRecADC::CTRecADC()
{
    m_IP = QHostAddress("10.0.2.200");
    m_Port = ADCPortDefault;
}


CTRecADC::~CTRecADC()
{

}


CTRecADC& CTRecADC::operator=(const CTRecADC& Obj)
{
    if(this == &Obj)
        return *this;

    m_ADCParam = Obj.m_ADCParam;
    m_IP = Obj.m_IP;
    m_Port = Obj.m_Port;

    return *this;
}

