#include "excursioncontroller.h"
#include "dao/impl/excursiondaofileimpl.h"

ExcursionController::ExcursionController()
{
    this->dao = new ExcursionDaoFileImpl();
}

ExcursionController::~ExcursionController(){
    delete dao;
}

void ExcursionController::add(Excursion* excursion){
    Excursion* finded = this->dao->getById(excursion->getId());

    if(finded != nullptr){
        this->dao->add(excursion);
    }
}

std::vector<Excursion *> ExcursionController::getByDates(std::string startDate, std::string endDate)
{
    return this->dao->getByDates(startDate, endDate);
}
