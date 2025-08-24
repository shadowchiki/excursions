#include "ViewFactoryConsole.hpp"
#include <ui/console/ConsoleView.hpp>

namespace factory::console
{

std::shared_ptr<ui::View> ViewFactoryConsole::view()
{
    if (not mConsoleView)
    {
        mConsoleView = std::make_shared<ui::console::ConsoleView>();
    }
    return mConsoleView;
}

}  // namespace factory::console
