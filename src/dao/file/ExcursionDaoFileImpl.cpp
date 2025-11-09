#include "ExcursionDaoFileImpl.h"
#include <model/excursion.h>
#include <utils/date/datefilterfactory.h>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include "dao/file/GenericFileDao_def.hpp"

ExcursionDaoFileImpl::ExcursionDaoFileImpl()
    : ExcursionDao()
    , mDateFilterFactory(std::make_unique<DateFilterFactory>())
    , mDao(new GenericFileDao<std::shared_ptr<Excursion>>(
          kFilePath,
          std::bind(&ExcursionDaoFileImpl::saveExcursionCallback, this, std::placeholders::_1),
          std::bind(&ExcursionDaoFileImpl::readExcursionCallback, this, std::placeholders::_1)))
{
}

std::string ExcursionDaoFileImpl::saveExcursionCallback(std::shared_ptr<Excursion> excursion)
{
    std::string saveExcursion = excursion->getId() + GenericFileDao<Excursion>::kSeparator
        + excursion->getDescription() + GenericFileDao<Excursion>::kSeparator + excursion->getDate()
        + GenericFileDao<Excursion>::kSeparator + std::to_string(excursion->getPrice())
        + GenericFileDao<Excursion>::kSeparator + std::to_string(excursion->getDurationDays())
        + GenericFileDao<Excursion>::kSeparator;
    return saveExcursion;
}

std::shared_ptr<Excursion> ExcursionDaoFileImpl::readExcursionCallback(
    std::vector<std::string> data)
{
    return std::make_shared<Excursion>(
        data.at(0), data.at(1), data.at(2), std::stol(data.at(3)), std::stoi(data.at(4)));
}

std::vector<std::shared_ptr<Excursion>> ExcursionDaoFileImpl::getByDates(
    std::string startDate,
    std::string endDate)
{
    auto* dateFilterFactory = mDateFilterFactory->getFilter(startDate, endDate);
    std::vector<std::shared_ptr<Excursion>> excursionFiltered;

    for (auto excursion : mDao->data())
    {
        if (dateFilterFactory->filter(excursion->getDate()))
        {
            excursionFiltered.push_back(excursion);
        }
    }

    delete dateFilterFactory;
    return excursionFiltered;
}

void ExcursionDaoFileImpl::add(std::shared_ptr<Excursion> excursion)
{
    mDao->save(excursion);
}

void ExcursionDaoFileImpl::remove(std::shared_ptr<Excursion> excursion)
{
    mDao->remove(excursion);
}

std::optional<std::shared_ptr<Excursion>> ExcursionDaoFileImpl::findById(std::string id)
{
    return mDao->findBy([&id](std::shared_ptr<Excursion> excursion)
                        { return excursion->getId().compare(id) == 0; });
}
