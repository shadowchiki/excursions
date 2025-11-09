#pragma once

#include <dao/ExcursionDao.h>
#include <memory>
#include <optional>
#include "GenericFileDao.hpp"
#include "utils/date/datefilterfactory.h"

class ExcursionDaoFileImpl : public ExcursionDao
{
public:
    ExcursionDaoFileImpl();
    virtual ~ExcursionDaoFileImpl() = default;

    virtual std::vector<std::shared_ptr<Excursion>> getByDates(
        std::string startDate,
        std::string endDate) override;

    virtual void add(std::shared_ptr<Excursion> excursion) override;
    virtual void remove(std::shared_ptr<Excursion> excursion);
    virtual std::optional<std::shared_ptr<Excursion>> findById(std::string id);

private:
    std::string saveExcursionCallback(std::shared_ptr<Excursion> excursion);
    std::shared_ptr<Excursion> readExcursionCallback(std::vector<std::string> data);

private:
    const std::string kFilePath = "/home/alejandro/workspace/excursions/src/filedb/excursions.txt";
    std::unique_ptr<DateFilterFactory> mDateFilterFactory;
    std::unique_ptr<GenericFileDao<std::shared_ptr<Excursion>>> mDao;
};
