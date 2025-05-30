#pragma once

#include <dao/excursiondao.h>
#include <memory>
#include "dao/file/FileDao.h"

class ExcursionDaoFileImpl
    : public ExcursionDao
    , public FileDao
{
public:
    ExcursionDaoFileImpl();

    virtual std::vector<std::shared_ptr<Excursion>> getByDates(
        std::string startDate,
        std::string endDate) override;
    virtual void add(std::shared_ptr<Excursion> excursion) override;

protected:
    virtual void map() override;
    virtual std::string filePath() override;

private:
    const std::string kFilePath = "/home/alejandro/workspace/excursions/src/filedb/excursions.txt";
    std::vector<std::shared_ptr<Excursion>> mExcursions;
};
