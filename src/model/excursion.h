#pragma once

#include <string>

class Excursion
{
public:
    Excursion(
        std::string id,
        std::string description,
        std::string date,
        long price,
        int durationDays);

    virtual ~Excursion() = default;

    std::string getId();
    std::string getDescription();
    std::string getDate();
    long getPrice();
    int getDurationDays();

private:
    std::string mId;
    std::string mDescription;
    std::string mDate;
    long mPrice;
    int mDurationDays;
};
