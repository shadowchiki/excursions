#pragma once

#include <factory/ViewFactory.hpp>

namespace factory::qt
{
class ViewFactoryQt : public ViewFactory
{
public:
    virtual ~ViewFactoryQt() = default;

    virtual std::shared_ptr<ui::View> view() override;

private:
    std::shared_ptr<ui::View> mView;
};
}  // namespace factory::console
