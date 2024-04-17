#include "excursiondaofileimpl.h"
#include <iostream>
#include <fstream>

ExcursionDaoFileImpl::ExcursionDaoFileImpl(){
    std::ofstream file("excursions.txt");
}

Excursion* ExcursionDaoFileImpl::getById(std::string){



}

std::vector<Excursion*> ExcursionDaoFileImpl::getByDates(std::string startDate, std::string endDate){

}

void ExcursionDaoFileImpl::add(Excursion* excursion){

}
