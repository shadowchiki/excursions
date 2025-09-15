#pragma once

#include <model/partner/partner.h>
#include <string>
#include <vector>
#include "model/partner/childrenpartner.h"
#include "model/partner/federatedpartner.h"
#include "model/partner/standarpartner.h"

class PartnerDao
{
public:
    virtual ~PartnerDao() = default;

    virtual std::vector<Partner*> getPartnerts() = 0;
    virtual void add(StandarPartner* partner) = 0;
    virtual void add(ChildrenPartner* partner) = 0;
    virtual void add(FederatedPartner* partner) = 0;
    virtual void modifySecureFromPartner(const std::string& partnerId) = 0;
    virtual void removePartner(const std::string& partnerId) = 0;
};
