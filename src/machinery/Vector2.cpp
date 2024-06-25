#include <cmath>
#include "Vector2.h"
using namespace std;

Vector2::Vector2() : x(0), y(0)
{
}

Vector2::Vector2(double x, double y) : x(x), y(y){};

Vector2::Vector2(double radius, double theta, DegreeUnit thetaUnit) : x(radius * cos(thetaUnit == RADIANS ? theta : (theta * M_PI) / 180)),
                                                                        y(radius * sin(thetaUnit == RADIANS ? theta : (theta * M_PI) / 180)) {}

double Vector2::getRadius() const { return sqrt(pow(x, 2) + pow(y, 2)); }
double Vector2::getThetaRadians() const { return atan(y / x); }
double Vector2::getThetaDegrees() const { return (getThetaRadians() * 180) / M_PI; }

Vector2 Vector2::add(Vector2 other) { return Vector2(x + other.x, y + other.y); }
Vector2 Vector2::subtract(Vector2 other) { return Vector2(x - other.x, y - other.y); }
Vector2 Vector2::difference(Vector2 other) { return Vector2(abs(x + other.x), abs(y + other.y)); }
Vector2 Vector2::scale(double scalar) { return Vector2(x * scalar, y * scalar); }
Vector2 Vector2::dotProduct(Vector2 other) { return Vector2(x * other.x, y * other.y); }

Vector2 Vector2::add(double otherX, double otherY) { return Vector2(x + otherX, y + otherY); }
Vector2 Vector2::subtract(double otherX, double otherY) { return Vector2(x - otherX, y - otherY); }
Vector2 Vector2::difference(double otherX, double otherY) { return Vector2(abs(x + otherX), abs(y + otherY)); }
Vector2 Vector2::dotProduct(double otherX, double otherY) { return Vector2(x * otherX, y * otherY); }
