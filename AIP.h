// AIP == Point In Area
// Created by rabilint on 14.03.25.
//

#ifndef AIP_H
#define AIP_H
#include <cmath>
#include <math.h>
#include <bits/ranges_base.h>

struct Point {
    double x;
    double y;

};

struct Triangle {
    Point A, B, C;
    double area() const;
    bool contains(const Point& P) const {
        Triangle T1 = {A, B, P};
        Triangle T2 = {C, B, P};
        Triangle T3 = {C, A, P};

        double S_main = area();
        double S_sum = T1.area() + T2.area() + T3.area();
        return fabs(S_main - S_sum) < 1e-6;
    }
};

double distance(const Point& P1, const Point& P2) {
    return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
}
double heronArea(const Triangle& T) {
    double a = distance(T.A, T.B);
    double b = distance(T.B, T.C);
    double c = distance(T.C, T.A);
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
double Triangle::area() const {
    return heronArea(*this);
}



double crossProduct(Point A, Point B, Point P);
double laysOnBorder(Point a, Point b, Point point);
double len(Point a, Point b);
double area(Point a, Point b, Point c);
double contain(Point a, Point b, Point c, Point point);
void checkPointInTriangle(Point A, Point B, Point C, Point P);

#endif //AIP_H
