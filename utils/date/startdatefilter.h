#ifndef STARTDATEFILTER_H
#define STARTDATEFILTER_H
#include "datefilter.h"

class StartDateFilter : public DateFilter
{
public:
    StartDateFilter(std::string date,
                    std::string startDate);
    virtual bool filter(std::string date);
};

#endif // STARTDATEFILTER_H
