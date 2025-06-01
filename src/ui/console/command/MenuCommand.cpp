#include "MenuCommand.hpp"
#include <string>
#include "ui/Execution.hpp"
#include "ui/console/command/ExitCommand.hpp"

namespace ui::console::command
{

MenuCommand::MenuCommand(std::string tittle)
    : Menu()
    , Command(tittle)
{
    this->mCommands.push_back(std::make_shared<ExitCommand>());
}

Execution MenuCommand::execute()
{
    return this->run();
}

Execution MenuCommand::run()
{
    if (this->mCommands.size() <= 0)
    {
        return Execution::EXIT;
    }

    bool error = true;
    int option;
    Execution execution = Execution::CONTINUE;
    do
    {
        this->mConsole.write(this->getTittle() + " Menu");

        for (int i = 0; i < this->mCommands.size(); i++)
        {
            this->mConsole.write(std::to_string(i + 1) + ". " + this->mCommands.at(i)->getTittle());
        }
        option = this->mConsole.readInt("");
        option = option - 1;
        if (option >= 0 && option < this->mCommands.size())
        {
            execution = mCommands.at(option)->execute();
            error = false;
        }

    } while (error || execution == Execution::CONTINUE);
    if (Execution::EXIT_MENU == execution)
    {
        execution = Execution::CONTINUE;
    }
    return execution;
}

void MenuCommand::addAction(std::shared_ptr<Command> newCommand)
{
    this->mCommands.insert(mCommands.begin(), newCommand);
}

}  // namespace ui::console::command
