#pragma once

#include "ui/View.hpp"

namespace ui::qt
{
class QtView : public View
{
public: 
    QtView() = default;
    virtual ~QtView() = default;

    virtual Execution init(int argc, char* argv[]) override;
};
}  // namespace ui::qt
