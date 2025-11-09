#pragma once

template<typename V, typename L>
class FileDaoStruct
{
public:
    FileDaoStruct(V value, L line);
    virtual ~FileDaoStruct() = default;

    V value();
    L line();

private:
    V mValue;
    L mLine;
};
