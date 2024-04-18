#include "datefilterfactory.h"
#include "startdatefilter.h"
#include "enddatefilter.h"
#include "betweendatefilter.h"

DateFilterFactory::DateFilterFactory()
{

}

DateFilter DateFilterFactory::getFilter(std::string startDate,
                     std::string endDate){

    if(!startDate.empty() && !endDate.empty()){
        return BetweenDateFilter(startDate, endDate);
    } else if(!startDate.empty() && endDate.empty()){
        return StartDateFilter(startDate);
    } else if(!endDate.empty && startDate.empty()){
        return EndDateFilter(endDate);
    }

    return null_ptr;

}
