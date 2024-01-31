#include <iostream>

class Asunto {

public:
    int asukasMaara;
    int neliot;

    Asunto() {
        std::cout << "Asunto luotu" << std::endl;
    }

    void maarita(int asukkaat, int pintaAla) {
        asukasMaara = asukkaat;
        neliot = pintaAla;
        std::cout << "Asunto maaritetty asukkaita= " << asukasMaara << " nelioita= " << neliot << std::endl;
    }

    virtual double laskeKulutus(double perusKulutus) {
        return perusKulutus * neliot;
    }
};

class Kerros {

public:
    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;

    Kerros() {
        std::cout << "Kerros luotu" << std::endl;
    }

    void maaritaAsunnot() {
        as1.maarita(2, 100);
        as2.maarita(2, 100);
        as3.maarita(2, 100);
        as4.maarita(2, 100);
        std::cout << "Kerros maaritettu" << std::endl;
    }

    virtual double laskeKulutus(double perusKulutus) {
        return as1.laskeKulutus(perusKulutus) + as2.laskeKulutus(perusKulutus) +
               as3.laskeKulutus(perusKulutus) + as4.laskeKulutus(perusKulutus);
    }
};

class Katutaso : public Kerros {

public:
    Katutaso() {
        std::cout << "Katutaso luotu" << std::endl;
    }

    void maaritaAsunnot() {
        as1.maarita(2, 100);
        as2.maarita(2, 100);
        std::cout << "Katutaso maaritettu" << std::endl;
    }

    double laskeKulutus(double perusKulutus) override {
        return as1.laskeKulutus(perusKulutus) + as2.laskeKulutus(perusKulutus);
    }
};

class Kerrostalo {

private:
    Katutaso eka;
    Kerros toka;
    Kerros kolmas;

public:
    Kerrostalo() {
        std::cout << "Kerrostalo luotu" << std::endl;
    }

    void kokoKerrostalonMaarittely() {

        std::cout << "Maaritellaan koko kerrostalon kaikki asunnot" << std::endl;
        eka.maaritaAsunnot();
        toka.maaritaAsunnot();
        kolmas.maaritaAsunnot();
        std::cout << "Kerrostalo maaritettu" << std::endl;
    }

    double laskeKulutus(double perusKulutus) {
        return eka.laskeKulutus(perusKulutus) + toka.laskeKulutus(perusKulutus) +
               kolmas.laskeKulutus(perusKulutus);
    }
};

int main() {

    Kerrostalo kerrostalo;
    kerrostalo.kokoKerrostalonMaarittely();

    std::cout << "Kerrostalon kulutus = " << kerrostalo.laskeKulutus(3) << std::endl;

    return 0;
}
