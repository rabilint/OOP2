// AIP == Point In Area
// Created by rabilint on 14.03.25.
//

#ifndef AIP_H
#define AIP_H

struct Point {
    double x;
    double y;

};

double crossProduct(Point A, Point B, Point P);
double laysOnBorder(Point a, Point b, Point point);
double len(Point a, Point b);
double area(Point a, Point b, Point c);
double contain(Point a, Point b, Point c, Point point);
void checkPointInTriangle(Point A, Point B, Point C, Point P);

#endif //AIP_H
