#include <iostream>
#include "AIP.h"

int main() {
    // double points[];
    Point point, a, b, c;
    std::cout << "Введіть вершини трикутників: \nКоординати першої вершини: ";
    std::cin >> a.x >> a.y;
    std::cout << "\nКоординати другої вершини: "; std::cin>> b.x >> b.y;
    std::cout << "\nКоординати третьої вершини: "; std::cin >> c.x >> c.y;

    std::cout << "Введіть х та у точки: ";
    std::cin >> point.x >> point.y;
    contain(a, b, c, point);

    std::cout <<"Перевірка альтернативним меодом (методом векторного добутку): \n" << std::endl;
    checkPointInTriangle(a, b, c, point);


    return 0;
}