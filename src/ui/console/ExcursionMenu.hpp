#pragma once

#include "controller/excursioncontroller.h"
#include "ui/Execution.hpp"
#include "ui/console/command/MenuCommand.hpp"

namespace ui::console
{
class ExcursionMenu : public command::MenuCommand
{
public:
    ExcursionMenu(std::string tittle);
    virtual ~ExcursionMenu() = default;

    virtual Execution execute() override;
    virtual Execution run() override;
    virtual void addAction(std::shared_ptr<Command> newCommand) override;

private:
  std::shared_ptr<controller::excursion::ExcursionController> mController;

};
}  // namespace ui::console
