#include "inscription.h"

Inscription::Inscription(int id, std::string mPartner, std::string mExcursion)
    : mId(id)
    , mPartner(mPartner)
    , mExcursion(mExcursion)
{
}

int Inscription::getId()
{
    return mId;
}

std::string Inscription::getParner()
{
    return mPartner;
}

std::string Inscription::getExcursion()
{
    return mExcursion;
}
