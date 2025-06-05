#include "ui/console/ConsoleView.hpp"

int main(int argc, char** argv)
{
    ui::console::ConsoleView console;
    console.init(argc, argv);
    return 0;
}
