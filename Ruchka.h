#ifndef RUCHKA_H
#define RUCHKA_H

#include "Kancelyariya.h"

class Ruchka : public Kancelyariya {
private:
    std::string cvetChernil;

public:
    Ruchka(const std::string& _nazvanie, double _cena, const std::string& _cvetChernil);

    void show() const override;
    void setCvetChernil(const std::string& _cvetChernil);
};

#endif
