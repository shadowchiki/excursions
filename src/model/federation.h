#pragma once

#include <string>

class Federation
{
public:
    Federation(std::string id, std::string name);

    std::string getId();
    std::string getName();

private:
    std::string mId;
    std::string mName;
};
