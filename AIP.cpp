//
// Created by rabilint on 14.03.25.
//

#include "AIP.h"
#include <iostream>
#include <cmath>

double len(Point a, Point b) { // підрахунок довжини трк.
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
};

double area(Point a, Point b, Point c) { //підрахунок площи
    double ab = len(a, b);
    double bc = len(b, c);
    double ca = len(c, a);
    double p =( ab + bc + ca ) / 2;
    return sqrt(p * (p - ab) * (p - bc) * (p - ca));
}

double crossProduct(Point a, Point b, Point point) {
    return (b.x - a.x) * (point.y - a.y) - (b.y - a.y) * (point.x - a.x);
}

void checkPointInTriangle(Point a, Point b, Point c, Point point) { //перевірка іншим метод(векторним)
    double cross1 = crossProduct(a, b, point);
    double cross2 = crossProduct(b, c, point);
    double cross3 = crossProduct(c, a, point);
    double totalArea = area(a, b, c);
    bool allPositive = (cross1 > 0 && cross2 > 0 && cross3 > 0);
    bool allNegative = (cross1 < 0 && cross2 < 0 && cross3 < 0);
    if (totalArea < 1e-6) {std::cout << "Трикутник не вироджений!\n";}
    else if (allPositive || allNegative)
        std::cout << "Точка x:" << point.x << " y:" << point.y <<" — належить трикутнику.\n";

    else if (cross1 == 0 || cross2 == 0 || cross3 == 0)
        std::cout << "Точка x:" << point.x << " y:" << point.y <<" — лежить на межі трикутника.\n";
    else std::cout << "Точка x:" << point.x << " y:" << point.y <<" — не належить трикутнику.\n";
};

double laysOnBorder(Point a, Point b, Point point) {//випадків, коли точка лежить на межі трикутника.
    if ((b.x - a.x) * (point.y - a.y) - (b.y - a.y) * (point.x - a.x) == 0) {return true;} else {return false;}
}

double contain(Point a, Point b, Point c, Point point) { //чи належить точка до трикутника
    double total_area = area(a, b, c);
    if (laysOnBorder(a,b,point) || laysOnBorder(b,c,point) || laysOnBorder(c,a,point)) {std::cout << "Точка х:" << point.x << " у:" << point.y << " — лежить на границі трикутника\n"; return 0; }
    else {
        if (total_area < 1e-6) {std::cout << "Трикутник не вироджений!\n";  return false;}
        double tmp = (area(point, b, c) + area(a, point, c) + area(a, b, point)) / total_area;
        (fabs(tmp - 1.0) < 1e-6 ? std::cout << "Точка: х:" << point.x << " y:" << point.y << " — належить трикутнику." : std::cout << "Точка: х:" << point.x << " у:" << point.y << " — не належить трикутнику") << std::endl;
        return 0;
    }
}