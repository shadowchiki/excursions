#include "startdatefilter.h"

StartDateFilter::StartDateFilter()
{

}

bool StartDateFilter::filter(std::string date){
    return dateUtils.after(date, startDate);
}
