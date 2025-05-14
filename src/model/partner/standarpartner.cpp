#include "standarpartner.h"

StandarPartner::StandarPartner(
    std::string id,
    std::string name,
    std::string nif,
    std::shared_ptr<Secure> secure)
    : Partner(id, name)
    , mNif(nif)
    , mSecure(secure)
{
}

int StandarPartner::discount()
{
}
