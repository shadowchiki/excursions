#include "excursion.h"

Excursion::Excursion(
    std::string id,
    std::string description,
    std::string date,
    long price,
    int durationDays)
    : mId(id)
    , mDescription(description)
    , mDate(date)
    , mPrice(price)
    , mDurationDays(durationDays)
{
}

std::string Excursion::getId()
{
    return mId;
}

std::string Excursion::getDescription()
{
    return mDescription;
}
std::string Excursion::getDate()
{
    return mDate;
}
long Excursion::getPrice()
{
    return mPrice;
}
int Excursion::getDurationDays()
{
    return mDurationDays;
}
