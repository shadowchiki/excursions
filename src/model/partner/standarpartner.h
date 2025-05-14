#pragma once
#include <memory>
#include "model/secure.h"
#include "partner.h"

class StandarPartner : public Partner
{
public:
    StandarPartner(
        std::string id,
        std::string name,
        std::string nif,
        std::shared_ptr<Secure> secure);
    virtual ~StandarPartner() = default;

    virtual int discount() override;

private:
    std::string mNif;
    std::shared_ptr<Secure> mSecure;
};
