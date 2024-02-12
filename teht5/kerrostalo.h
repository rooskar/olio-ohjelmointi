#ifndef KERROSTALO_H
#define KERROSTALO_H
#include <iostream>

class Asunto {
public:
    int asukasMaara;
    int neliot;

    Asunto();
    void maarita(int asukkaat, int pintaAla);
    virtual double laskeKulutus(double perusKulutus);
    virtual ~Asunto();
};

class Kerros {
public:
    Asunto* as1;
    Asunto* as2;
    Asunto* as3;
    Asunto* as4;

    Kerros();
    virtual ~Kerros();
    void maaritaAsunnot();
    virtual double laskeKulutus(double perusKulutus);
};

class Katutaso : public Kerros {
public:
    Katutaso();
    void maaritaAsunnot();
    double laskeKulutus(double perusKulutus) override;
    virtual ~Katutaso();
};

class Kerrostalo {
private:
    Katutaso* eka;
    Kerros* toka;
    Kerros* kolmas;

public:
    Kerrostalo();
    ~Kerrostalo();
    void kokoKerrostalonMaarittely();
    double laskeKulutus(double perusKulutus);
};
#endif // KERROSTALO_H
