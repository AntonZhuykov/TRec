#include "TRecADCParam.h"
#include <algorithm>


CTRecADCParam::CTRecADCParam()
{
    m_sampleRate = SampleRateVals[2];
    m_bufferSize = BufferSizeSampleDefault;
    m_histSize = HistSizeSampleMin;
    m_ChNum = CHTotalNum;
    m_bitness = bitnessDefault;
}

CTRecADCParam::~CTRecADCParam()
{

}

CTRecADCParam& CTRecADCParam::operator=(const CTRecADCParam& Obj)
{
    if(this == &Obj)
        return *this;

    m_sampleRate = Obj.m_sampleRate;
    m_bufferSize = Obj.m_bufferSize;
    m_histSize = Obj.m_histSize;
    m_ChNum = Obj.m_ChNum;
    m_bitness = Obj.m_bitness;

    return *this;
}


void CTRecADCParam::ChNum_set(const int& ChNum)
{
    if(m_ChNum < ChNum)
    {
        auto [first, last] = ranges::remove_if(m_ChParam_vec,
                                               [&ChNum](auto ch){return ch.ind_get()==ChNum;});
        m_ChParam_vec.erase(first, last);
    }
    else if(m_ChNum > ChNum)
    {
        CTRecADCChParam tmpChParam;
        tmpChParam.ind_set(ChNum);
        m_ChParam_vec.push_back(tmpChParam);
    }
}
