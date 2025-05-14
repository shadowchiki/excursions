#pragma once
#include <memory>
#include "partner.h"

class ChildrenPartner : public Partner
{
public:
    ChildrenPartner(std::string id, std::string name, std::shared_ptr<Partner> parent);

    // Tienen un descuento del 50% en la cuota mensual
    virtual int discount() override;

private:
    std::shared_ptr<Partner> parent;
};
