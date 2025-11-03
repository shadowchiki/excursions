#include <factory/ViewFactory.hpp>
#include <factory/config/ConfFactory.hpp>
#include <memory>

int main(int argc, char **argv) {
  factory::ConfFactory confFactory;
  std::shared_ptr<factory::ViewFactory> viewFactory = confFactory.viewFactory();
  std::shared_ptr<ui::View> view = viewFactory->view();
  view->init(argc, argv);
  return 0;
}
