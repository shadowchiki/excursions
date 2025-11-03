#pragma once

// #include <dao/PartnerDao.h>
#include "model/partner/partner.h"
#include <memory>
#include <vector>

namespace controller::excursion
{

class PartnerController
{
public:
    PartnerController();
    virtual ~PartnerController() = default;

    void add(std::shared_ptr<Partner> excursion);
    std::vector<std::shared_ptr<Partner>> getByDates(std::string startDate, std::string endDate);

private:
    // std::shared_ptr<PartnerDao> mDao;
};
}  // namespace controller::excursion
