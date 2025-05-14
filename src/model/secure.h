#pragma once

#include "securetype.h"

class Secure
{
public:
    Secure(int price, SecureType type);
    virtual ~Secure() = default;

    int getPrice();
    SecureType getType();

private:
    int mPrice;
    SecureType mType;
};
