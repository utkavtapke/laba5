#include "../include/Ruchka.h"
#include <iostream>

Ruchka::Ruchka(const std::string& _nazvanie, double _cena, const std::string& _cvetChernil)
    : Kancelyariya(_nazvanie, _cena), cvetChernil(_cvetChernil) {}

void Ruchka::show() const {
    Kancelyariya::show();
    std::cout << " | Цвет чернил: " << cvetChernil << " [Авторучка]" << std::endl;
}

void Ruchka::setCvetChernil(const std::string& _cvetChernil) { cvetChernil = _cvetChernil; }
