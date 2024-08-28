#include "TRecADCParam.h"
#include <ranges>
#include <algorithm>

TRecADCParam::TRecADCParam()
{
    m_sampleRate = SampleRateVals[0];
    m_bufferSize = BufferSizeSampleMin;
    m_histSize = HistSizeSampleMin;
    m_ChNum = CHTotalNum;
}

TRecADCParam::~TRecADCParam()
{

}

TRecADCParam& TRecADCParam::operator=(const TRecADCParam& Obj)
{
    if(this == &Obj)
        return *this;

    m_sampleRate = Obj.m_sampleRate;
    m_bufferSize = Obj.m_bufferSize;
    m_histSize = Obj.m_histSize;
    m_ChNum = Obj.m_ChNum;

    return *this;
}


void TRecADCParam::ChNum_set(const int& ChNum)
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
