#pragma once
#include <memory>
#include "model/federation.h"
#include "partner.h"

class FederatedPartner : public Partner
{
public:
    FederatedPartner(
        std::string id,
        std::string name,
        std::string nif,
        std::shared_ptr<Federation> federation);

    // Tienen un descuento del 5% para la cuota mensual y 10% en el precio de las excursiones
    virtual int discount() override;

private:
    std::string mNif;
    std::shared_ptr<Federation> mFederation;
};
