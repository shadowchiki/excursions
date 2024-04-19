#include "excursiondaofileimpl.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../utils/date/datefilterfactory.h"
using namespace std;

ExcursionDaoFileImpl::ExcursionDaoFileImpl() {
    std::ofstream file(this->FILE_ROUTE);
}

Excursion* ExcursionDaoFileImpl::getById(string id){
    std::ifstream file(this->FILE_ROUTE);
    string line;
    Excursion* excursion;
    bool finded = false;
    if(file.is_open()){
        while(file || !finded){
            getline(file, line);
            excursion = map(line);
            if(excursion->getId() == id){
                finded = true;
            }
        }
    }
    return excursion;
}

Excursion* ExcursionDaoFileImpl::map(string line){
    stringstream stream(line);
    vector<string> excursionData;
    string value;
    while(getline(stream, value, ';')){
        excursionData.push_back(value);
    }
    Excursion* excursion = new Excursion(excursionData.at(0), excursionData.at(1), excursionData.at(2), stol(excursionData.at(3)), stoi(excursionData.at(4)));
    return excursion;
}

vector<Excursion*> ExcursionDaoFileImpl::getByDates(string startDate, string endDate){
    ifstream file(this->FILE_ROUTE);
    string line;
    vector<Excursion*> excursions;
    if(!file.is_open()){
        return excursions;
    }

    while(file){
        getline(file, line);
        excursions.push_back(map(line));
    }
    DateFilterFactory factory;
    DateFilter* filter = factory.getFilter(startDate, endDate);
    if(filter == nullptr){
        return excursions;
    }

    vector<Excursion*> excursionsFilter;
    for(Excursion* excursion: excursions){
        if(filter->filter(excursion->getDate())){
            excursionsFilter.push_back(excursion);
        }
    }

    return excursionsFilter;
}

vector<Excursion*> ExcursionDaoFileImpl::filterByDate(std::string startDate, std::string endDate){
    return vector<Excursion*> {};
}

void ExcursionDaoFileImpl::add(Excursion* excursion){

}
