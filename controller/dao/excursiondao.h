#ifndef EXCURSIONDAO_H
#define EXCURSIONDAO_H
#include "../../model/excursion.h"
#include <string>
#include <vector>

class ExcursionDao
{
public:
    ExcursionDao();
    virtual Excursion* getById(std::string id) = 0;
    virtual std::vector<Excursion*> getByDates(std::string startDate, std::string endDate) = 0;
    virtual void add(Excursion* excursion) = 0;
};

#endif // EXCURSIONDAO_H
