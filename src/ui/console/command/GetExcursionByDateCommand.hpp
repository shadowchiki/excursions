#pragma once

#include <memory>
#include "controller/excursioncontroller.h"
#include "ui/Command.hpp"
#include "ui/console/Console.hpp"

namespace ui::console::command
{
class GetExcursionByDateCommand : public Command
{
public:
    GetExcursionByDateCommand(
        std::shared_ptr<controller::excursion::ExcursionController> controller);
    virtual ~GetExcursionByDateCommand() = default;

    virtual Execution execute() override;

private:
    std::shared_ptr<controller::excursion::ExcursionController> mController;
    Console mConsole;
};
}  // namespace ui::console::command
