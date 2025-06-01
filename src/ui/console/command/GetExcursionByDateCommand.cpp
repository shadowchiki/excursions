#include "GetExcursionByDateCommand.hpp"
#include <string>
#include "ui/Execution.hpp"
#include "utils/date/dateutils.h"

namespace ui::console::command
{

GetExcursionByDateCommand::GetExcursionByDateCommand(
    std::shared_ptr<controller::excursion::ExcursionController> controller)
    : Command("Get Excursion By Date")
    , mController(controller)
    , mConsole()
{
}

Execution GetExcursionByDateCommand::execute()
{
    auto startDate = mConsole.read("Insert the start date " + DateUtils::kDateFormat);
    auto endDate = mConsole.read("Insert the end Date " + DateUtils::kDateFormat);

    auto excursions = mController->getByDates(startDate, endDate);
    for (int i = 0; i < excursions.size(); i++)
    {
        mConsole.write(
            std::to_string(i + 1) + "- " + "Description " + excursions.at(i)->getDescription());
    }
    return Execution::CONTINUE;
}

}  // namespace ui::console::command
