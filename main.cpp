#include <iostream>
#include "controller/dao/impl/excursiondaofileimpl.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    ExcursionDao* dao = new ExcursionDaoFileImpl();
    std::vector<Excursion*> excursions = dao->getByDates("2023-10-15","");

    for(Excursion* excursion : excursions){
        cout << excursion;
        cout << "\n";
    }

    return 0;
}
