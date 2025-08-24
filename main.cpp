#include <factory/config/ConfFactory.hpp>

int main(int argc, char** argv)
{
    factory::ConfFactory confFactory;
    auto viewFactory = confFactory.viewFactory();
    std::shared_ptr<ui::View> view = viewFactory->view();
    view->init(argc, argv);
    return 0;
}
