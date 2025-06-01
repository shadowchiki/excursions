#pragma once

#include "ui/Command.hpp"

namespace ui::console::command
{
class ExitCommand : public Command
{
public:
    ExitCommand();
    virtual ~ExitCommand() = default;

    virtual Execution execute() override;
};
}  // namespace ui::console
