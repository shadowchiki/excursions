#pragma once

#include <memory>
#include <vector>
#include "Command.hpp"
#include "ui/Execution.hpp"

namespace ui
{
class Menu
{
public:
    Menu() = default;
    virtual ~Menu() = default;

    virtual Execution run() = 0;
    virtual void addAction(std::shared_ptr<Command> newAction) = 0;

protected:
    std::vector<std::shared_ptr<Command>> mCommands;
};
}  // namespace ui
