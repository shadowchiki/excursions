#pragma once

#include <string>
namespace ui::console
{
class Console
{
public:
    virtual ~Console() = default;

    virtual void write(std::string prompt);
    virtual std::string read(std::string prompt);
    virtual int readInt(std::string prompt);
};
}  // namespace ui::console
