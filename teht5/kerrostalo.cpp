#include "kerrostalo.h"

Asunto::Asunto() {
    std::cout << "Asunto luotu" << std::endl;
}

void Asunto::maarita(int asukkaat, int pintaAla) {
    asukasMaara = asukkaat;
    neliot = pintaAla;
    std::cout << "Asunto maaritetty asukkaita= " << asukasMaara << " nelioita= " << neliot << std::endl;
}

double Asunto::laskeKulutus(double perusKulutus) {
    return perusKulutus * neliot;
}

Asunto::~Asunto() {}

Kerros::Kerros() {
    std::cout << "Kerros luotu" << std::endl;
    as1 = new Asunto();
    as2 = new Asunto();
    as3 = new Asunto();
    as4 = new Asunto();
}

Kerros::~Kerros() {
    delete as1;
    delete as2;
    delete as3;
    delete as4;
}

void Kerros::maaritaAsunnot() {
    as1->maarita(2, 100);
    as2->maarita(2, 100);
    as3->maarita(2, 100);
    as4->maarita(2, 100);
    std::cout << "Kerros maaritettu" << std::endl;
}

double Kerros::laskeKulutus(double perusKulutus) {
    return as1->laskeKulutus(perusKulutus) + as2->laskeKulutus(perusKulutus) +
           as3->laskeKulutus(perusKulutus) + as4->laskeKulutus(perusKulutus);
}

Katutaso::Katutaso() {
    std::cout << "Katutaso luotu" << std::endl;
}

void Katutaso::maaritaAsunnot() {
    as1->maarita(2, 100);
    as2->maarita(2, 100);
    std::cout << "Katutaso maaritettu" << std::endl;
}

double Katutaso::laskeKulutus(double perusKulutus) {
    return as1->laskeKulutus(perusKulutus) + as2->laskeKulutus(perusKulutus);
}

Katutaso::~Katutaso() {}

Kerrostalo::Kerrostalo() {
    std::cout << "Kerrostalo luotu" << std::endl;
    eka = new Katutaso();
    toka = new Kerros();
    kolmas = new Kerros();
}

Kerrostalo::~Kerrostalo() {
    delete eka;
    delete toka;
    delete kolmas;
}

void Kerrostalo::kokoKerrostalonMaarittely() {
    std::cout << "Maaritellaan koko kerrostalon kaikki asunnot" << std::endl;
    eka->maaritaAsunnot();
    toka->maaritaAsunnot();
    kolmas->maaritaAsunnot();
    std::cout << "Kerrostalo maaritettu" << std::endl;
}

double Kerrostalo::laskeKulutus(double perusKulutus) {
    return eka->laskeKulutus(perusKulutus) + toka->laskeKulutus(perusKulutus) +
           kolmas->laskeKulutus(perusKulutus);
}
