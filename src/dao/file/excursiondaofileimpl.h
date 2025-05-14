#ifndef EXCURSIONDAOFILEIMPL_H
#define EXCURSIONDAOFILEIMPL_H

#include <dao/excursiondao.h>

class ExcursionDaoFileImpl : public ExcursionDao
{
private:
    const std::string FILE_ROUTE = "../../../filedb/excursions.txt";
    Excursion* map(std::string line);
    std::vector<Excursion*> filterByDate(std::string startDate, std::string endDate);

public:
    ExcursionDaoFileImpl();
    virtual Excursion* getById(std::string id);
    virtual std::vector<Excursion*> getByDates(std::string startDate, std::string endDate);
    virtual void add(Excursion* excursion);
};

#endif  // EXCURSIONDAOFILEIMPL_H
