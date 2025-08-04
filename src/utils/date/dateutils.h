#ifndef DATEUTILS_H
#define DATEUTILS_H
#include <ctime>
#include <string>

class DateUtils
{
public:
    DateUtils() = default;
    ~DateUtils() = default;

    std::time_t convert(std::string date);
    bool equals(std::string date, std::string dateCompare);
    bool equals(std::time_t date, std::time_t dateCompare);
    bool before(std::string date, std::string dateCompare);
    bool before(std::time_t date, std::time_t dateCompare);
    bool after(std::string date, std::string dateCompare);
    bool after(std::time_t date, std::time_t dateCompare);
    bool between(std::string date, std::string startDate, std::string endDate);
    bool between(std::time_t date, std::time_t startDate, std::time_t endDate);

    static const std::string kDateFormat;

private:
    const std::string kInternalDateFormat = "%Y-%m-%d";
};

#endif  // DATEUTILS_H
