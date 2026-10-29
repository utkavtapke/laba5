#include "../include/Kancelyariya.h"
#include <iostream>

Kancelyariya::Kancelyariya(const std::string& _nazvanie, double _cena) : nazvanie(_nazvanie), cena(_cena) {}

double Kancelyariya::getCena() const { return cena; }

void Kancelyariya::setCena(double _cena) { cena = _cena; }

void Kancelyariya::show() const {
    std::cout << "Наименование: " << nazvanie << " | Цена: " << cena << " руб.";
}
