#pragma once

#include <dao/excursiondao.h>
#include <memory>
#include <vector>

namespace controller::excursion{

class ExcursionController
{
public:
    ExcursionController();
    virtual ~ExcursionController() = default;

    void add(std::shared_ptr<Excursion> excursion);
    std::vector<std::shared_ptr<Excursion>> getByDates(std::string startDate, std::string endDate);

private:
    std::shared_ptr<ExcursionDao> mDao;
};
}
