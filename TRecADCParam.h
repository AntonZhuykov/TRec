#ifndef TRECADCPARAM_H
#define TRECADCPARAM_H

#include "TRecADCChParam.h"
#include <vector>

using namespace std;

inline constexpr double SampleRateVals[] = {15.625, 31.25, 62.5, 125.0};
inline constexpr int BufferSizeSampleMin = 12500;
inline constexpr int BufferSizeSampleMax = 12500000;
inline constexpr int BufferSizeSampleDefault = 625000;
inline constexpr int HistSizeSampleMin = 0;
inline constexpr double HistSizeSampleMaxCoef = 0.9;
inline constexpr int CHTotalNum = 8;
inline constexpr int bitnessDefault = 12;


class CTRecADCParam
{
public:
    CTRecADCParam();
    ~CTRecADCParam();
    CTRecADCParam& operator=(const CTRecADCParam& Obj);

    void SRate_set(const double& rate) {m_sampleRate = rate;}
    void BSize_set(const int& bsize) {m_bufferSize = bsize;}
    void HSize_set(const int& hsize) {m_histSize = hsize;}
    void ChNum_set(const int& ChNum);
    void Bitness_set(const int& bit) {m_bitness = bit;}

    double SRate_get() const {return m_sampleRate;}
    int BSize_get() const {return m_bufferSize;}
    int HSize_get() const {return m_histSize;}
    vector<class CTRecADCChParam>* CHParam_get() {return &m_ChParam_vec;}
    int Bitness_get() const {return m_bitness;}

private:
    double m_sampleRate;
    int m_bufferSize;
    int m_histSize;
    int m_ChNum;
    int m_bitness;
    vector<class CTRecADCChParam> m_ChParam_vec;
};

#endif // TRECADCPARAM_H
