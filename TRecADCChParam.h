#ifndef TRECADCCHPARAM_H
#define TRECADCCHPARAM_H

inline constexpr double k1Default = 1000.0;
inline constexpr double k2Default = 400.0;
inline constexpr double k3Default = 1.0;
inline constexpr double triggerPercentDefault = 50.0;

enum class EdgeTriggerTypes { RISING, FALLING, EITHER };


class CTRecADCChParam
{
public:
    CTRecADCChParam();
    ~CTRecADCChParam();
    CTRecADCChParam& operator=(const CTRecADCChParam& Obj);

    void ind_set(const int& ind) { m_ind = ind;}
    void OnOff_set(const bool& flag) { m_OnOff = flag;}
    void k1_set(const double& k1) { m_k1 = k1;}
    void k2_set(const double& k2) { m_k2 = k2;}
    void k3_set(const double& k3) { m_k3 = k3;}
    void k1k2k3_set(const double&, const double&, const double&);
    void triggerType_set(const EdgeTriggerTypes& type) {m_triggerType = type;}

    int ind_get() {return m_ind;}
    double k1_get() {return m_k1;}
    double k2_get() {return m_k2;}
    double k3_get() {return m_k3;}

    void ratio_recalc();

private:
    int m_ind;      // порядковый номер канала
    bool m_OnOff;   // флаг состояния канала (включен/выключен)
    double m_k1, m_k2, m_k3;
    double m_ratio;
    EdgeTriggerTypes m_triggerType;
    double m_triggerPercent;
};

#endif // TRECADCCHPARAM_H
