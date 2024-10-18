#ifndef TRECADC_H
#define TRECADC_H

#include "TRecADCParam.h"
#include <QHostAddress>


inline constexpr int ADCPortDefault = 1024;



class CTRecADC
{
public:
    CTRecADC();
    ~CTRecADC();
    CTRecADC& operator=(const CTRecADC& Obj);

    CTRecADCParam* ADCParam_get() {return &m_ADCParam;}

    void ADCInit(); // инициализация платы АЦП, включая физическое подключение АЦП к входам
    void ADCReset();// сброс настроек платы АЦП
    void ADCStart();// старт регистрации (отслеживания триггеров по каналам)
    void ADCStop(); // останов регистрации
    void ChInit(CTRecADCChTrigger); // инициализация канала АЦП (включая параметры триггера)

protected:
    CTRecADCParam m_ADCParam;
    QHostAddress m_IP;
    int m_Port;
};

#endif // TRECADC_H
