#include "excursioncontroller.h"
#include <memory>
#include "dao/file/excursiondaofileimpl.h"

namespace controller::excursion
{
ExcursionController::ExcursionController()
    : mDao(std::make_shared<ExcursionDaoFileImpl>())
{
}

void ExcursionController::add(std::shared_ptr<Excursion> excursion)
{
    mDao->add(excursion);
}

std::vector<std::shared_ptr<Excursion>> ExcursionController::getByDates(
    std::string startDate,
    std::string endDate)
{
    return mDao->getByDates(startDate, endDate);
}

}  // namespace controller::excursion
