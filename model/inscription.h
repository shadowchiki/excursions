#ifndef INSCRIPTION_H
#define INSCRIPTION_H
#include "partner/partner.h"
#include "excursion.h"

class Inscription
{
private:
    int id;
    Partner* partner;
    Excursion* excursion;

public:
    Inscription();
};

#endif // INSCRIPTION_H
