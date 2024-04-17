#ifndef EXCURSIONDAOFILEIMPL_H
#define EXCURSIONDAOFILEIMPL_H

#include "../excursiondao.h"

class ExcursionDaoFileImpl : ExcursionDao
{
public:
    ExcursionDaoFileImpl();
    virtual Excursion* getById(std::string);
    virtual std::vector<Excursion*> getByDates(std::string startDate, std::string endDate);
    virtual void add(Excursion* excursion);
};

#endif // EXCURSIONDAOFILEIMPL_H
