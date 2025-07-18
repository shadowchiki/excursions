#pragma once

#include <memory>
#include "controller/ExcursionController.h"
#include "ui/Command.hpp"
#include "ui/console/Console.hpp"
namespace ui::console::command
{
class AddExcursionCommand : public Command
{
public:
    AddExcursionCommand(std::shared_ptr<controller::excursion::ExcursionController> controller);
    virtual ~AddExcursionCommand() = default;

    virtual Execution execute() override;

private:
    std::shared_ptr<controller::excursion::ExcursionController> mController;
    Console mConsole;
};
}  // namespace ui::console::command
