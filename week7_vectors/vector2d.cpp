#include "vector2d.h"
#include <cmath>
#include <iostream>

v2d::v2d(double a, double b) {
    // Construct a vector with x = a and y = b
    x = a;
    y = b;
}

v2d::v2d(const v2d & v) {
    // Construct a vector similar to v
    x = v.x;
    y = v.y;
}

// Destructor
v2d::~v2d() {}

/// @brief Method to update a vector to be exactly as v
v2d & v2d::operator=(const v2d &v) {
    x = v.x;
    y = v.y;
    return *this;
}

/// @brief Method to update a vector by adding v to it
v2d & v2d::operator+(const v2d &v) {
    x = x + v.x;
    y = y + v.y;
    return *this;
}

/// @brief Method to update the vector by multiplying it by k
v2d & v2d::operator*(double k) {
    x = x * k;
    y = y * k;
    return *this;
}

/// @brief Method to compute the scalar product of the two vectors, not updating the vectors
double v2d::operator*(const v2d &v) {
    double u = x * v.x;
    double t = y * v.y;
    double scalar_product = u + t;
    return scalar_product;
}

/// @brief Method to compute the length of the vector 
double v2d::length() {
    double length = sqrt(x*x + y*y);
    return length;
}

/// @brief Method to display the vector
// void v2d::disp() {
//     std::cout << "(" << x << "," << y << ")" << std::endl;
// }