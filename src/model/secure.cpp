#include "secure.h"

Secure::Secure(int price, SecureType type)
    : mPrice(price)
    , mType(type)
{
}

int Secure::getPrice()
{
    return mPrice;
}
SecureType Secure::getType()
{
    return mType;
}
