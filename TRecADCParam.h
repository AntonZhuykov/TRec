#ifndef TRECADCPARAM_H
#define TRECADCPARAM_H

#include "TRecADCChParam.h"
#include <vector>

using namespace std;

inline constexpr double SampleRateVals[] = {25.0, 50.0, 100.0, 200.0};
inline constexpr int BufferSizeSampleMin = 50000;
inline constexpr int BufferSizeSampleMax = 500000;
inline constexpr int HistSizeSampleMin = 0;
inline constexpr double HistSizeSampleMaxCoef = 0.9;
inline constexpr int CHTotalNum = 6;


class TRecADCParam
{
public:
    TRecADCParam();
    ~TRecADCParam();
    TRecADCParam& operator=(const TRecADCParam& Obj);

    void SRate_set(const double& rate) {m_sampleRate = rate;}
    void BSize_set(const int& bsize) {m_bufferSize = bsize;}
    void HSize_set(const int& hsize) {m_histSize = hsize;}
    void ChNum_set(const int& ChNum);

    double SRate_get() const {return m_sampleRate;}
    int BSize_get() const {return m_bufferSize;}
    int HSize_get() const {return m_histSize;}
    vector<class CTRecADCChParam>* CHParam_get() {return &m_ChParam_vec;}

private:
    double m_sampleRate;
    int m_bufferSize;
    int m_histSize;
    int m_ChNum;
    vector<class CTRecADCChParam> m_ChParam_vec;
};

#endif // TRECADCPARAM_H
