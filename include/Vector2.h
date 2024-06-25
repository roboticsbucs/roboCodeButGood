#pragma once
#include <cmath>
using namespace std;
class Vector2
{
private:
    /* data */
    double x, y;
public:
    enum DegreeUnit
    {
        DEGREES,
        RADIANS
    };
    Vector2();
    Vector2(double x, double y);
    Vector2(double radius, double theta, DegreeUnit thetaUnit);

    bool equals(Vector2 other) { this->x == other.x && this->y == other.y; }

    double getX() const { return x; }
    double getY() const { return y; }
    double getRadius() const; 
    double getThetaRadians() const; 
    double getThetaDegrees() const; 

    Vector2 add(Vector2 other);
    Vector2 subtract(Vector2 other);
    Vector2 difference(Vector2 other);
    Vector2 scale(double scalar);
    Vector2 dotProduct(Vector2 other);


    Vector2 add(double otherX, double otherY);
    Vector2 subtract(double otherX, double otherY);
    Vector2 difference(double otherX, double otherY);
    Vector2 dotProduct(double otherX, double otherY);
};
