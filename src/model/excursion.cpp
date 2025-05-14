#include "excursion.h"

Excursion::Excursion()
{
}

Excursion::Excursion(
    std::string id,
    std::string description,
    std::string date,
    long price,
    int durationDays)
{
    this->id = id;
    this->description = description;
    this->date = date;
    this->price = price;
    this->durationDays = durationDays;
}

std::string Excursion::getId()
{
    return this->getId();
}

std::string Excursion::getDate()
{
    return this->getDate();
}
