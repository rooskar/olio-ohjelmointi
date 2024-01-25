#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

class ItalianChef : public Chef {
private:
    int water;
    int flour;

public:
    ItalianChef(string chefName, int waterAmount, int flourAmount);
    void makePasta(int waterAmount, int flourAmount);
    string getName() const;
};

#endif // ITALIANCHEF_H
