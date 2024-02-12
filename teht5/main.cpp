#include "kerrostalo.h"

int main() {
    Kerrostalo* kerrostalo = new Kerrostalo();
    kerrostalo->kokoKerrostalonMaarittely();

    std::cout << "Kerrostalon kulutus = " << kerrostalo->laskeKulutus(3) << std::endl;

    delete kerrostalo;
    return 0;
}

