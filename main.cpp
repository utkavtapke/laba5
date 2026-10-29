#include <iostream>
#include <clocale>
#include "include/Kancelyariya.h"
#include "include/Bumaga.h"
#include "include/Ruchka.h"

void printMenu() {
    std::cout << "\n=== МЕНЮ УПРАВЛЕНИЯ ===" << std::endl;
    std::cout << "1. Просмотр всех канцелярских товаров" << std::endl;
    std::cout << "2. Изменить цену товара по номеру" << std::endl;
    std::cout << "3. Вычислить среднюю цену по категориям" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    const int SIZE = 4;
    Kancelyariya* inventory[SIZE];

    inventory[0] = new Bumaga("SvetoCopy A4", 450.0, 80);
    inventory[1] = new Ruchka("ErichKrause Ultra", 85.0, "Синий");
    inventory[2] = new Bumaga("Бумага для акварели", 320.0, 200);
    inventory[3] = new Ruchka("Parker Jotter", 2500.0, "Черный");

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\n--- Список товаров на складе ---" << std::endl;
                for (int i = 0; i < SIZE; i++) {
                    std::cout << "[" << i << "] ";
                    inventory[i]->show();
                }
                break;
            }
            case 2: {
                int index;
                double newPrice;
                std::cout << "Введите номер элемента (0-" << SIZE - 1 << "): ";
                std::cin >> index;
                if (index >= 0 && index < SIZE) {
                    std::cout << "Текущая цена: " << inventory[index]->getCena() << " руб." << std::endl;
                    std::cout << "Введите новую цену: ";
                    std::cin >> newPrice;
                    inventory[index]->setCena(newPrice);
                    std::cout << "Цена успешно изменена!" << std::endl;
                } else {
                    std::cout << "Неверный номер!" << std::endl;
                }
                break;
            }
            case 3: {
                double totalBumaga = 0, totalRuchka = 0;
                int countBumaga = 0, countRuchka = 0;

                for (int i = 0; i < SIZE; i++) {
                    // Проверяем, является ли товар бумагой
                    if (dynamic_cast<Bumaga*>(inventory[i]) != nullptr) {
                        totalBumaga += inventory[i]->getCena();
                        countBumaga++;
                    }
                    // Проверяем, является ли товар ручкой
                    else if (dynamic_cast<Ruchka*>(inventory[i]) != nullptr) {
                        totalRuchka += inventory[i]->getCena();
                        countRuchka++;
                    }
                }

                std::cout << "\n--- Средняя цена по категориям ---" << std::endl;
                if (countBumaga > 0) {
                    std::cout << "Категория [Бумага]: " << totalBumaga / countBumaga << " руб." << std::endl;
                } else {
                    std::cout << "Категория [Бумага]: товаров нет" << std::endl;
                }

                if (countRuchka > 0) {
                    std::cout << "Категория [Авторучка]: " << totalRuchka / countRuchka << " руб." << std::endl;
                } else {
                    std::cout << "Категория [Авторучка]: товаров нет" << std::endl;
                }
                break;
            }
        }
    } while (choice != 0);

    for (int i = 0; i < SIZE; i++) {
        delete inventory[i];
    }

    return 0;
}
