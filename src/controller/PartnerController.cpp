#include "PartnerController.h"

namespace controller::excursion {

PartnerController::PartnerController() {}

void PartnerController::add(std::shared_ptr<Partner> excursion) {
  excursion->discount();
}

std::vector<std::shared_ptr<Partner>>
PartnerController::getByDates(std::string startDate, std::string endDate) {}

} // namespace controller::excursion
