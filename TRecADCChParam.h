#ifndef TRECADCCHPARAM_H
#define TRECADCCHPARAM_H

#include <QString>

inline constexpr double k1Default = 1000.0;
inline constexpr double k2Default = 400.0;
inline constexpr double k3Default = 1.0;
inline constexpr int triggerCentMin = 0;
inline constexpr int triggerCentMax = 100;
inline constexpr int triggerCentDefault = 50;       // ур-нь триггера в процентах
inline constexpr double chRangeLimDefault = 5.0;    // max значение входного диапазона АЦП, В

enum class EdgeTriggerModes { RISING, FALLING, EITHER };
inline constexpr const char* EdgeTriggerModeLabels[] = {"по фронту", "по спаду", "оба варианта"};
enum class TriggerPolarity { POSITIVE, NEGATIVE, EITHER };
inline constexpr const char* TriggerPolarityLabels[] = {"+ полярность", "- полярность", "оба полярности"};



class CTRecADCChTrigger
{
public:
    CTRecADCChTrigger();
    CTRecADCChTrigger(const int, const EdgeTriggerModes, const TriggerPolarity);
    ~CTRecADCChTrigger();
    CTRecADCChTrigger& operator=(const CTRecADCChTrigger& Obj);

    EdgeTriggerModes m_triggerMode;
    TriggerPolarity m_triggerPolarity;
    int m_triggerCent;  // ур-нь триггера в процентах
};



class CTRecADCChParam
{
public:
    CTRecADCChParam();
    ~CTRecADCChParam();
    CTRecADCChParam& operator=(const CTRecADCChParam& Obj);

    void ind_set(const int& ind) { m_ind = ind;}
    void OnOff_set(const bool& flag) { m_OnOff = flag;}
    void OnOffTrigger_set(const bool& flag) { m_OnOffTrigger = flag;}
    void rangeLim_set(const double& Lim) {m_rangeLim = Lim;}
    void k1_set(const double& k1) { m_k1 = k1;}
    void k2_set(const double& k2) { m_k2 = k2;}
    void k3_set(const double& k3) { m_k3 = k3;}
    void k1k2k3_set(const double&, const double&, const double&);
    void trigger_set(const CTRecADCChTrigger trigger) {m_trigger = trigger;}
    void triggerMode_set(const EdgeTriggerModes& type) {m_trigger.m_triggerMode = type;}
    void triggerPolarity_set(const TriggerPolarity& sign) {m_trigger.m_triggerPolarity = sign;}
    void triggerCent_set(const int& mille) {m_trigger.m_triggerCent = mille;}

    int ind_get() const {return m_ind;}
    bool OnOff_get() const {return m_OnOff;}
    bool OnOffTrigger_get() const {return m_OnOffTrigger;}
    double rangeLim_get() const {return m_rangeLim;}
    double k1_get() const {return m_k1;}
    double k2_get() const {return m_k2;}
    double k3_get() const {return m_k3;}
    double ratio_get() const {return m_ratio;}
    CTRecADCChTrigger trigger_get() const {return m_trigger;}
    // EdgeTriggerModes triggerMode_get() const {return m_triggerMode;}
    // TriggerPolarity triggerPolarity_get() const {return m_triggerPolarity;}
    // int triggerCent_get() const {return m_triggerCent;}
    double triggerKV_get() const;

    void ratio_recalc();

private:
    int m_ind;      // порядковый номер канала
    bool m_OnOff;   // флаг состояния канала (включен/выключен)
    bool m_OnOffTrigger;    // флаг отслеживания сигнала на предмет запуска регистрации
    double m_rangeLim;      // max зн-е входного диапазона [В]
    double m_k1, m_k2, m_k3;
    double m_ratio;
    CTRecADCChTrigger m_trigger;
};

#endif // TRECADCCHPARAM_H
