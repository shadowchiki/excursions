#include "ExcursionDaoFileImpl.h"
#include <memory>
#include <string>
#include <vector>
#include "model/excursion.h"
#include "utils/date/datefilterfactory.h"

ExcursionDaoFileImpl::ExcursionDaoFileImpl()
    : ExcursionDao()
    , FileDao()
    , mExcursions()
    , mDateFilterFactory(std::make_unique<DateFilterFactory>())
{
    readFile();
}

std::vector<std::shared_ptr<Excursion>> ExcursionDaoFileImpl::getByDates(
    std::string startDate,
    std::string endDate)
{
    auto* dateFilterFactory = mDateFilterFactory->getFilter(startDate, endDate);
    std::vector<std::shared_ptr<Excursion>> excursionFiltered;
    for (auto excursion : mExcursions)
    {
        if (dateFilterFactory->filter(excursion->getDate()))
        {
            excursionFiltered.push_back(excursion);
        }
    }

    return excursionFiltered;
}

void ExcursionDaoFileImpl::add(std::shared_ptr<Excursion> excursion)
{
    clear();
    mData.push_back(excursion->getId());
    mData.push_back(excursion->getDescription());
    mData.push_back(excursion->getDate());
    mData.push_back(std::to_string(excursion->getPrice()));
    mData.push_back(std::to_string(excursion->getDurationDays()));
    this->saveOnFile();
    mExcursions.clear();
    readFile();
}

void ExcursionDaoFileImpl::map()
{
    std::shared_ptr<Excursion> excursion = std::make_shared<Excursion>(
        mData.at(0), mData.at(1), mData.at(2), stol(mData.at(3)), stoi(mData.at(4)));
    mExcursions.push_back(excursion);
}

std::string ExcursionDaoFileImpl::filePath()
{
    return kFilePath;
}
