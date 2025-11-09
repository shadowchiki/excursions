#pragma once

#include "controller/ExcursionController.h"
#include "ui/console/command/MenuCommand.hpp"

namespace ui::console
{
class ExcursionMenu : public command::MenuCommand
{
public:
    ExcursionMenu(std::string tittle);
    virtual ~ExcursionMenu() = default;

private:
  std::shared_ptr<controller::excursion::ExcursionController> mController;

};
}  // namespace ui::console
