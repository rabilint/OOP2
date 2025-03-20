#include <iostream>
#include "AIP.h"
#include <vector>

int main() {
    std::vector<Point> v1;
    Point a, b, c;
    bool end = false;
    std::cout << "Введіть вершини трикутників: \nКоординати першої вершини: ";
    std::cin >> a.x >> a.y;
    std::cout << "\nКоординати другої вершини: "; std::cin>> b.x >> b.y;
    std::cout << "\nКоординати третьої вершини: "; std::cin >> c.x >> c.y;

    do {
        Point point;
        std::cout << "Введіть х та у точки: ";
        std::cin >> point.x >> point.y;
        v1.push_back(point);
        std::cout << "end? >0 - yes; <0 - no" << std::endl;
        std::cin >> end;
    } while (!end);

    if (v1.empty()) { //перевірка чи ввів щось користувач.
        std::cout << "В масиві точки не було знайдено!";
        return 0;
    }

    for (int i = 0; i < v1.size(); i++) {
        contain(a, b, c, v1.at(i));
    }
    std::cout <<"Перевірка альтернативним меодом (методом векторного добутку): \n" << std::endl;
    for (int i = 0; i < v1.size(); i++) {
        checkPointInTriangle(a, b, c, v1.at(i));
    }



    return 0;
}