
#pragma once

#include "ui/Command.hpp"

namespace ui::console::command
{
class ExitMenuCommand : public Command
{
public:
    ExitMenuCommand();
    virtual ~ExitMenuCommand() = default;

    virtual Execution execute() override;
};
}  // namespace ui::console
