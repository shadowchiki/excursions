#include "excursiondaofileimpl.h"
#include <fstream>
#include <sstream>
#include "utils/date/datefilterfactory.h"

ExcursionDaoFileImpl::ExcursionDaoFileImpl()
{
    std::ofstream file(this->FILE_ROUTE);
}

Excursion* ExcursionDaoFileImpl::getById(std::string id)
{
    std::ifstream file(this->FILE_ROUTE);
    std::string line;
    Excursion* excursion;
    bool finded = false;
    if (file.is_open())
    {
        while (file || !finded)
        {
            getline(file, line);
            excursion = map(line);
            if (excursion->getId() == id)
            {
                finded = true;
            }
        }
    }
    return excursion;
}

Excursion* ExcursionDaoFileImpl::map(std::string line)
{
    std::stringstream stream(line);
    std::vector<std::string> excursionData;
    std::string value;
    while (getline(stream, value, ';'))
    {
        excursionData.push_back(value);
    }
    Excursion* excursion = new Excursion(
        excursionData.at(0),
        excursionData.at(1),
        excursionData.at(2),
        stol(excursionData.at(3)),
        stoi(excursionData.at(4)));
    return excursion;
}

std::vector<Excursion*> ExcursionDaoFileImpl::getByDates(std::string startDate, std::string endDate)
{
    std::ifstream file("/home/alejandro/workspace/cpp/excursions/src/filedb/excursions.txt");

    std::string line;
    std::vector<Excursion*> excursions;
    if (!file.is_open())
    {
        return excursions;
    }

    while (file)
    {
        getline(file, line);
        excursions.push_back(map(line));
    }
    DateFilterFactory factory;
    DateFilter* filter = factory.getFilter(startDate, endDate);
    if (filter == nullptr)
    {
        return excursions;
    }

    std::vector<Excursion*> excursionsFilter;
    for (Excursion* excursion : excursions)
    {
        if (filter->filter(excursion->getDate()))
        {
            excursionsFilter.push_back(excursion);
        }
    }

    return excursionsFilter;
}

std::vector<Excursion*> ExcursionDaoFileImpl::filterByDate(
    std::string startDate,
    std::string endDate)
{
    return std::vector<Excursion*> {};
}

void ExcursionDaoFileImpl::add(Excursion* excursion)
{
}
