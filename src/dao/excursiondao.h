#ifndef EXCURSIONDAO_H
#define EXCURSIONDAO_H

#include <string>
#include <vector>
#include "model/excursion.h"

class ExcursionDao
{
public:
    virtual ~ExcursionDao() = default;

    virtual Excursion* getById(std::string id) = 0;
    virtual std::vector<Excursion*> getByDates(std::string startDate, std::string endDate) = 0;
    virtual void add(Excursion* excursion) = 0;
};

#endif  // EXCURSIONDAO_H
