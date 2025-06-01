#include "ConsoleView.hpp"
#include <memory>
#include "ui/console/ExcursionMenu.hpp"
#include "ui/console/command/MenuCommand.hpp"

namespace ui::console
{

ConsoleView::ConsoleView()
    : View()
    , mMenu(std::make_unique<command::MenuCommand>("Main"))
{
    auto excursionMenu = std::make_shared<ExcursionMenu>("Excursion management");
    this->mMenu->addAction(excursionMenu);
}

Execution ConsoleView::init(int argc, char* argv[])
{
    return this->mMenu->run();
}

}  // namespace ui::console
