#pragma once
#include <string>

class Inscription
{
public:
    Inscription(int id, std::string mPartner, std::string mExcursion);
    virtual ~Inscription() = default;

    int getId();
    std::string getParner();
    std::string getExcursion();

private:
    int mId;
    std::string mPartner;
    std::string mExcursion;
};
