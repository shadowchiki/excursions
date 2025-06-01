#include "ExcursionMenu.hpp"
#include <memory>
#include "controller/excursioncontroller.h"
#include "ui/console/command/ExitMenuCommand.hpp"
#include "ui/console/command/GetExcursionByDateCommand.hpp"
#include "ui/console/command/MenuCommand.hpp"

namespace ui::console
{

ExcursionMenu::ExcursionMenu(std::string tittle)
    : command::MenuCommand(tittle)
    , mController(std::make_shared<controller::excursion::ExcursionController>())
{
    command::MenuCommand::addAction(std::make_shared<command::ExitMenuCommand>());
    command::MenuCommand::addAction(
        std::make_shared<command::GetExcursionByDateCommand>(mController));
}

Execution ExcursionMenu::execute()
{
    return command::MenuCommand::execute();
}

Execution ExcursionMenu::run()
{
    return command::MenuCommand::run();
}

void ExcursionMenu::addAction(std::shared_ptr<Command> newCommand)
{
    command::MenuCommand::addAction(newCommand);
}

}  // namespace ui::console
