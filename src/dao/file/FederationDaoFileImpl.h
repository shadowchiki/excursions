#pragma once
#include <dao/FederationDao.h>
#include "model/federation.h"

class FederationDaoFileImpl
    : public FederationDao
{
public:
    FederationDaoFileImpl();
    virtual ~FederationDaoFileImpl() = default;

    virtual std::vector<std::shared_ptr<Federation>>& getAllFederations() override;


private:
    const std::string kFilePath = "/home/alejandro/workspace/excursions/src/filedb/federations.txt";
    std::vector<std::shared_ptr<Federation>> mFederations;
};
