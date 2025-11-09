#include "FederationDaoFileImpl.h"

FederationDaoFileImpl::FederationDaoFileImpl()
    : FederationDao()
    , mFederations()
{
}

std::vector<std::shared_ptr<Federation>>& FederationDaoFileImpl::getAllFederations()
{
    return mFederations;
}

