#pragma once
#include "FileDaoStruct_def.hpp"

template<typename V, typename L>
FileDaoStruct<V, L>::FileDaoStruct(V value, L line)
    : mValue(value)
    , mLine(line)
{
}

template<typename V, typename L>
V FileDaoStruct<V, L>::value()
{
    return mValue;
}

template<typename V, typename L>
L FileDaoStruct<V, L>::line()
{
    return mLine;
}
