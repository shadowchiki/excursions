#pragma once

#include <memory>
#include <vector>
#include "model/secure.h"

class SecureDao
{
public:
    SecureDao() = default;
    virtual ~SecureDao() = default;

    virtual std::vector<std::shared_ptr<Secure>>& getAllSecure() = 0;
};
