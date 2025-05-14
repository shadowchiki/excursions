#include "federatedpartner.h"

FederatedPartner::FederatedPartner(
    std::string id,
    std::string name,
    std::string nif,
    std::shared_ptr<Federation> federation)
    : Partner(id, name)
    , mNif(nif)
    , mFederation(federation)
{
}

int FederatedPartner::discount()
{
}
