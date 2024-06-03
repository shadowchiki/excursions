#ifndef EXCURSIONCONTROLLER_H
#define EXCURSIONCONTROLLER_H
#include <vector>
#include "dao/excursiondao.h"

class ExcursionController
{
private:
    ExcursionDao* dao;

public:
    ExcursionController();
    ~ExcursionController();

    void add(Excursion* excursion);
    std::vector<Excursion*> getByDates(std::string startDate, std::string endDate);
};

#endif // EXCURSIONCONTROLLER_H
