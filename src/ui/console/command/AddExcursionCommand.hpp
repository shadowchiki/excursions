/**
 * @par Copyright:
 *   This source code is covered by intellectual property rights and its
 *   distribution is limited to Indra. Other disclosure requests for this
 *   information are subject to the prior written approval of the parties
 *   listed above.
 */
#pragma once

#include <memory>
#include "controller/excursioncontroller.h"
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
