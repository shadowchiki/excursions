#include "ExcursionController.h"
#include <dao/file/ExcursionDaoFileImpl.h>
#include <chrono>
#include <memory>

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
    if (startDate == "")
    {
        startDate = "1900-01-01";
    }
    if (endDate == "")
    {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::tm tm = *std::localtime(&t);

        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d");
        endDate = oss.str();
    }
    return mDao->getByDates(startDate, endDate);
}

}  // namespace controller::excursion
