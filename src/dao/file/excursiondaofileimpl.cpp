#include "excursiondaofileimpl.h"
#include <memory>
#include <string>

ExcursionDaoFileImpl::ExcursionDaoFileImpl()
    : ExcursionDao()
    , FileDao()
    , mExcursions()
{
    readFile();
}

std::vector<std::shared_ptr<Excursion>> ExcursionDaoFileImpl::getByDates(
    std::string startDate,
    std::string endDate)
{
    return mExcursions;
}

void ExcursionDaoFileImpl::add(std::shared_ptr<Excursion> excursion)
{
    mExcursions.push_back(excursion);
    mData.push_back(excursion->getId());
    mData.push_back(excursion->getDescription());
    mData.push_back(excursion->getDate());
    mData.push_back(std::to_string(excursion->getPrice()));
    mData.push_back(std::to_string(excursion->getDurationDays()));
    this->saveOnFile();
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
