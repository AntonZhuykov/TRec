#ifndef TRECADC_H
#define TRECADC_H

#include "TRecADCParam.h"
#include <QHostAddress>
#include <QTcpSocket>


inline constexpr const char* ADCIPAdressDefault = "10.0.2.200";
inline constexpr int ADCPortDefault = 1024;
inline constexpr const char* ADCResetCommand = "#RESET";
inline constexpr const char* TriggerLevelCommandPreamble = "#LEVEL 0 ";

inline constexpr const char* ADCConnectStatusLabels[] =
    { "соединение с АЦП\nотсутствует", "соединения с АЦП\nустановлено"};



class CTRecADC
{
public:
    CTRecADC();
    ~CTRecADC();
    CTRecADC& operator=(const CTRecADC& Obj);

    void TcpSocket_set(QTcpSocket* pSocket) {m_pTcpSocket = pSocket;}
    void IPAddress_set(const QHostAddress& IP) {m_IP = IP;}
    void IPAddress_set(const QString& IPStr) {m_IP = QHostAddress(IPStr);}
    void IPPort_set(const int& port) {m_Port = port;}
    void ConnectStatus_set(const bool& status) {m_ConnectStatus = status;}

    CTRecADCParam* ADCParam_get() {return &m_ADCParam;}
    bool ConnectStatus_get() {return m_ConnectStatus;}

    void ADCConnect();  // установка соединения с платой АЦП
    void ADCDisconnect();
    void ADCInit(); // инициализация платы АЦП, включая физическое подключение АЦП к входам
    void ADCReset();// сброс настроек платы АЦП
    void ADCStart();// старт регистрации (отслеживания триггеров по каналам)
    void ADCStop(); // останов регистрации
    void ChInit(CTRecADCChTrigger); // инициализация канала АЦП (включая параметры триггера)

protected:
    CTRecADCParam m_ADCParam;
    QTcpSocket* m_pTcpSocket;
    QHostAddress m_IP;
    int m_Port;
    bool m_ConnectStatus;
};

#endif // TRECADC_H
