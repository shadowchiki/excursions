#include <dao/file/federationdaofileimpl.h>
#include <iostream>
#include <memory>
#include "dao/excursiondao.h"
#include "dao/file/excursiondaofileimpl.h"

int main()
{
    std::unique_ptr<FederationDao> federationDao = std::make_unique<FederationDaoFileImpl>();
    for (auto federation : federationDao->getAllFederations())
    {
        std::cout << federation->getName() << std::endl;
    }

    std::unique_ptr<ExcursionDao> excursionDao = std::make_unique<ExcursionDaoFileImpl>();
    auto var = excursionDao->getByDates("2023-10-15", "");
    std::cout << "Excursion Size " << var.size() << std::endl;
    for (auto federation : var)
    {
        std::cout << federation->getId() << std::endl;
    }
    std::shared_ptr<Excursion> excursion =
        std::make_shared<Excursion>("002", "Testing", "2023-10-15", 15.0, 3);
    excursionDao->add(excursion);

    return 0;
}
