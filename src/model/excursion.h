#pragma once

#include <string>

class Excursion
{
public:
    Excursion();
    Excursion(
        std::string id,
        std::string description,
        std::string date,
        long price,
        int durationDays);

    virtual ~Excursion() = default;

    std::string getId();
    std::string getDate();

private:
    std::string id;
    std::string description;
    std::string date;
    long price;
    int durationDays;
};
