#ifndef EXCURSIONDAO_H
#define EXCURSIONDAO_H

#include <memory>
#include <string>
#include <vector>
#include "model/excursion.h"

class ExcursionDao
{
public:
    virtual ~ExcursionDao() = default;

    virtual std::vector<std::shared_ptr<Excursion>> getByDates(
        std::string startDate,
        std::string endDate) = 0;
    virtual void add(std::shared_ptr<Excursion> excursion) = 0;
};

#endif  // EXCURSIONDAO_H
