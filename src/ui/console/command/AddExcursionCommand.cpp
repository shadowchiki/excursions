#include "AddExcursionCommand.hpp"
#include <utils/date/dateutils.h>
#include <memory>

namespace ui::console::command
{

AddExcursionCommand::AddExcursionCommand(
    std::shared_ptr<controller::excursion::ExcursionController> controller)
    : Command("Add Excursion")
    , mController(controller)
    , mConsole()
{
}

Execution AddExcursionCommand::execute()
{
    std::string id = mConsole.read("Insert Id");
    std::string description = mConsole.read("Insert Description");
    std::string date = mConsole.read("Insert Date " + DateUtils::kDateFormat);
    long price = mConsole.readInt("Insert price");
    int durationDays = mConsole.readInt("Insert duration");
    std::shared_ptr<Excursion> excursion =
        std::make_shared<Excursion>(id, description, date, price, durationDays);
    mController->add(excursion);
    return Execution::CONTINUE;
}
}  // namespace ui::console::command
