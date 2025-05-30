#include "federationdaofileimpl.h"

FederationDaoFileImpl::FederationDaoFileImpl()
    : FederationDao()
    , FileDao()
    , mFederations()
{
    readFile();
}

std::vector<std::shared_ptr<Federation>>& FederationDaoFileImpl::getAllFederations()
{
    return mFederations;
}

void FederationDaoFileImpl::map()
{
    std::shared_ptr<Federation> federation =
    std::make_shared<Federation>(mData.at(0), mData.at(1));
    mFederations.push_back(federation);
}

std::string FederationDaoFileImpl::filePath()
{
    return kFilePath;
}
