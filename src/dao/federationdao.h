#pragma once
#include <model/federation.h>
#include <memory>
#include <vector>

class FederationDao
{
public:
    FederationDao() = default;
    virtual ~FederationDao() = default;

    virtual std::vector<std::shared_ptr<Federation>>& getAllFederations() = 0;
};
