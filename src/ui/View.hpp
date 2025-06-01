#pragma once

#include "ui/Execution.hpp"

namespace ui
{
class View
{
public:
    View() = default;
    virtual ~View() = default;

    virtual Execution init(int argc, char* argv[]) = 0;

private:
};
}  // namespace ui
