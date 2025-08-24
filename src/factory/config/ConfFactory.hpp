
#pragma once

#include <memory>
#include "factory/ViewFactory.hpp"
namespace factory
{
class ConfFactory
{
public:
    ConfFactory() = default;
    virtual ~ConfFactory() = default;

    virtual std::shared_ptr<ViewFactory> viewFactory();
};
}  // namespace factory
