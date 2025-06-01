#pragma once

#include <memory>
#include "ui/Execution.hpp"
#include "ui/View.hpp"
#include "ui/Menu.hpp"

namespace ui::console
{
class ConsoleView : public View
{
public:
    ConsoleView();
    virtual ~ConsoleView() = default;

    virtual Execution init(int argc, char* argv[]) override;

private:
    std::unique_ptr<Menu> mMenu;
};
}  // namespace ui::console
