#pragma once

#include "dao/PartnerDao.h"

class PartnertDaoFileImpl : public PartnerDao
{
public:
    PartnertDaoFileImpl() = default;
    virtual ~PartnertDaoFileImpl() = default;

    virtual std::vector<Partner*> getPartnerts() override;
    virtual void add(StandarPartner* partner) override;
    virtual void add(ChildrenPartner* partner) override;
    virtual void add(FederatedPartner* partner) override;
    virtual void modifySecureFromPartner(const std::string& partnerId) override;
    virtual void removePartner(const std::string& partnerId) override;
};
