#include "ExitCommand.hpp"
#include "ui/Execution.hpp"
#include "ui/console/Console.hpp"

namespace ui::console::command
{

ExitCommand::ExitCommand()
    : Command("Exit")
{
}

Execution ExitCommand::execute()
{
    Console console;
    console.write("Closing App");
    return Execution::EXIT;
}

}  // namespace ui::console
