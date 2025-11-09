#include "ExcursionMenu.hpp"
#include <memory>
#include "controller/ExcursionController.h"
#include "ui/console/command/AddExcursionCommand.hpp"
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
    command::MenuCommand::addAction(std::make_shared<command::AddExcursionCommand>(mController));
}

}  // namespace ui::console
