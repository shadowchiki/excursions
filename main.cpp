#include <factory/ViewFactory.hpp>
#include <factory/config/ConfFactory.hpp>
#include <memory>
#include "dao/file/ExcursionDaoFileImpl.h"
#include "model/excursion.h"

int main(int argc, char** argv)
{
    // factory::ConfFactory confFactory;
    // std::shared_ptr<factory::ViewFactory> viewFactory = confFactory.viewFactory();
    // std::shared_ptr<ui::View> view = viewFactory->view();
    // view->init(argc, argv);
    ExcursionDaoFileImpl dao;
    // dao.add(std::make_shared<Excursion>("", "", "", 10, 1));

    auto excursions = dao.getByDates("2024-01-01", "2028-01-30");
    std::cout << "Lee excursions " << excursions.size() << std::endl;
    auto excursion = dao.findById("001");
    if (excursion.has_value())
    {
        std::cout << "Excursion with id " << excursion->get()->getId() << " finded" << std::endl;
    }

    return 0;
}
