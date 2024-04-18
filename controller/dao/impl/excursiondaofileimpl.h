#ifndef EXCURSIONDAOFILEIMPL_H
#define EXCURSIONDAOFILEIMPL_H

#include "../excursiondao.h"

class ExcursionDaoFileImpl : ExcursionDao
{
private:
    const std::string FILE_ROUTE = "../../../filedb/excursions.txt";
    Excursion* map(string line);
    std::vector<Excursion*> filterByDate(std::string startDate, std::string endDate);
public:
    ExcursionDaoFileImpl();
    virtual Excursion* getById(std::string id);
    virtual std::vector<Excursion*> getByDates(std::string startDate, std::string endDate);
    virtual void add(Excursion* excursion);
};

#endif // EXCURSIONDAOFILEIMPL_H
