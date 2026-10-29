#ifndef BUMAGA_H
#define BUMAGA_H

#include "Kancelyariya.h"

class Bumaga : public Kancelyariya {
private:
    int plotnost;

public:
    Bumaga(const std::string& _nazvanie, double _cena, int _plotnost);

    void show() const override;
    void setPlotnost(int _plotnost);
};

#endif
