#pragma once
#include <dao/federationdao.h>
#include "dao/file/FileDao.h"
#include "model/federation.h"

class FederationDaoFileImpl
    : public FederationDao
    , public FileDao
{
public:
    FederationDaoFileImpl();
    virtual ~FederationDaoFileImpl() = default;

    virtual std::vector<std::shared_ptr<Federation>>& getAllFederations() override;

protected:
    virtual void map() override;
    virtual std::string filePath() override;

private:
    const std::string kFilePath = "/home/alejandro/workspace/excursions/src/filedb/federations.txt";
    std::vector<std::shared_ptr<Federation>> mFederations;
};
