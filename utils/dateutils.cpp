#include "dateutils.h"
using namespace std;

DateUtils::DateUtils()
{}

time_t DateUtils::convert(string date){
    istringstream stream(startDate);
    tm tm{};
    stream >> get_time(&tm, "%Y-%m-%d");
    time_t start = mktime(&tm);
    return start;
}

bool DateUtils::equals(string date, string dateCompare){
    time_t dateParsed = convert(date);
    time_t dateCompareParsed = conver(dateCompare);
    return equals(date, dateCompareParsed);
}

bool DateUtils::equals(time_t date, time_t dateCompare){
    return date == dateCompare;
}

bool DateUtils::before(string date, string dateCompare){
    time_t dateParsed = convert(date);
    time_t dateCompareParsed = conver(dateCompare);
    return before(dateParsed, dateCompareParsed);
}

bool DateUtils::before(time_t date, time_t dateCompare){
    return date < dateCompare;
}

bool DateUtils::after(string date, string dateCompare){
    time_t dateParsed = convert(date);
    time_t dateCompareParsed = conver(dateCompare);
    return after(dateParsed, dateCompareParsed);
}

bool DateUtils::after(time_t date, time_t dateCompare){
    return !before(date, dateCompare);
}

bool DateUtils::between(std::string date, std::string startDate, std::string endDate){
    time_t dateParsed = convert(date);
    time_t startDateParsed = conver(startDate);
    time_t endDateParsed = conver(endDate);
    return between(dateParsed, startDateParsed, endDateParsed);
}

bool DateUtils::between(std::time_t date, std::time_t startDate, std::time_t endDate){
    return date > startDate && dateParsed < endDate;
}
