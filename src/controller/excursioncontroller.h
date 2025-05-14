#ifndef EXCURSIONCONTROLLER_H
#define EXCURSIONCONTROLLER_H
#include <dao/excursiondao.h>
#include <vector>

class ExcursionController
{
public:
    ExcursionController();
    ~ExcursionController();

    void add(Excursion* excursion);
    std::vector<Excursion*> getByDates(std::string startDate, std::string endDate);

private:
    ExcursionDao* dao;
};

#endif  // EXCURSIONCONTROLLER_H
