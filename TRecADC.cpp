#include "TRecADC.h"
#include <cstdlib>


CTRecADC::CTRecADC()
{
    m_pTcpSocket = nullptr;
    m_IP = QHostAddress(ADCIPAdressDefault);
    m_Port = ADCPortDefault;
    m_ConnectStatus = false;
}


CTRecADC::~CTRecADC()
{

}


CTRecADC& CTRecADC::operator=(const CTRecADC& Obj)
{
    if(this == &Obj)
        return *this;

    m_ADCParam = Obj.m_ADCParam;
    m_pTcpSocket = Obj.m_pTcpSocket;
    m_IP = Obj.m_IP;
    m_Port = Obj.m_Port;
    m_ConnectStatus = Obj.m_ConnectStatus;

    return *this;
}


void CTRecADC::ADCConnect()
{
    m_pTcpSocket->abort();
    m_pTcpSocket->connectToHost(m_IP, m_Port);
}


void CTRecADC::ADCDisconnect()
{
    m_pTcpSocket->disconnectFromHost();
}


void CTRecADC::ADCReset()
{
    m_pTcpSocket->write(ADCResetCommand);
}


void CTRecADC::ADCInit()
{
    for(auto& ch : *(m_ADCParam.CHParam_get()))
    {
        auto tmp = div(ch.ind_get(), CHPerADCNum);
        QString ADCNum;
        QString command = TriggerLevelCommandPreamble + ADCNum.setNum(tmp.quot + 1);
        m_pTcpSocket->write(command.toUtf8());
    }
}
