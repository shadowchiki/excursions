#pragma once

#include <memory>
#include "ui/Menu.hpp"
#include "ui/console/Console.hpp"

namespace ui::console::command

{
class MenuCommand
    : public Menu
    , public Command
{
public:
    MenuCommand(std::string tittle);
    virtual ~MenuCommand() = default;

    virtual Execution execute() override;
    virtual Execution run() override;
    virtual void addAction(std::shared_ptr<Command> newCommand) override;

protected:
    console::Console mConsole;
};
}  // namespace ui::command
