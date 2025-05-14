#pragma once

#include <string>

class Partner
{
public:
    Partner(std::string id, std::string name);
    virtual ~Partner() = default;

    virtual int discount() = 0;

protected:
    std::string id;
    std::string name;
};
