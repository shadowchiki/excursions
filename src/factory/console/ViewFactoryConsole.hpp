#pragma once

#include <factory/ViewFactory.hpp>

namespace factory::console
{
class ViewFactoryConsole : public ViewFactory
{
public:
    virtual ~ViewFactoryConsole() = default;

    virtual std::shared_ptr<ui::View> view() override;

private:
    std::shared_ptr<ui::View> mConsoleView;
};
}  // namespace factory::console
