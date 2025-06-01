#ifndef DATEFILTERFACTORY_H
#define DATEFILTERFACTORY_H
#include <string>
#include "datefilter.h"

class DateFilterFactory
{
public:
    DateFilterFactory() = default;
    virtual ~DateFilterFactory() = default;
    DateFilter* getFilter(std::string startDate, std::string endDate);
};

#endif  // DATEFILTERFACTORY_H
