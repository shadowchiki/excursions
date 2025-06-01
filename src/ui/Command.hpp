#pragma once

#include <string>
#include "ui/Execution.hpp"
namespace ui
{
class Command
{
public:
    Command(std::string tittle);
    virtual ~Command() = default;

    virtual Execution execute() = 0;
    virtual std::string getTittle();

private:
    std::string mTittle;
};
}  // namespace ui
