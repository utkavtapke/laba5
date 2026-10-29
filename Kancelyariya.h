#ifndef KANCELYARIYA_H
#define KANCELYARIYA_H

#include <string>

class Kancelyariya {
protected:
    std::string nazvanie;
    double cena;

public:
    Kancelyariya(const std::string& _nazvanie, double _cena);
    virtual ~Kancelyariya() {}

    double getCena() const;
    void setCena(double _cena);

    virtual void show() const;
};

#endif
