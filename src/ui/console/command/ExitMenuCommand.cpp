#include "ExitMenuCommand.hpp"
#include "ui/Execution.hpp"
#include "ui/console/Console.hpp"

namespace ui::console::command
{

ExitMenuCommand::ExitMenuCommand()
    : Command("Exit Menu")
{
}

Execution ExitMenuCommand::execute()
{
    Console console;
    console.write("Exiting " + this->getTittle() + " menu");
    return Execution::EXIT_MENU;
}
}  // namespace ui::console::command
