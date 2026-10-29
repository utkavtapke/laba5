#include "../include/Bumaga.h"
#include <iostream>

Bumaga::Bumaga(const std::string& _nazvanie, double _cena, int _plotnost)
    : Kancelyariya(_nazvanie, _cena), plotnost(_plotnost) {}

void Bumaga::show() const {
    Kancelyariya::show();
    std::cout << " | Плотность: " << plotnost << " г/м² [Бумага]" << std::endl;
}

void Bumaga::setPlotnost(int _plotnost) { plotnost = _plotnost; }
