#pragma once

#include <memory>
#include <ui/View.hpp>

namespace factory
{

class ViewFactory
{
public:
    ViewFactory() = default;
    virtual ~ViewFactory() = default;

    virtual std::shared_ptr<ui::View> view() = 0;
};

}  // namespace factory
