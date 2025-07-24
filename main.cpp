#include "ui/console/ConsoleView.hpp"
#include "ui/qt/QtView.hpp"

int main(int argc, char** argv)
{
    // ui::console::ConsoleView console;
    // console.init(argc, argv);
    ui::qt::QtView qt;
    qt.init(argc, argv);
    return 0;
}
