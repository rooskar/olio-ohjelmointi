#include "italianchef.h"

ItalianChef::ItalianChef(string chefName, int waterAmount, int flourAmount) : Chef(chefName), water(waterAmount), flour(flourAmount) {}

void ItalianChef::makePasta(int waterAmount, int flourAmount) {
    cout << "Chef " << name << " makes pasta with special recipe" << endl;
    cout << "Chef " << name << " uses jauhot = " << flourAmount << endl;
    cout << "Chef " << name << " uses vesi = " << waterAmount << endl;
}

string ItalianChef::getName() const {
    return name;
}
