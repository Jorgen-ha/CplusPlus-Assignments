#include "shapes.h"
#include <cmath>

///////////////////////////////////SHAPE///////////////////////////////////////
// Returns the area of the shape
double Shape::area(){
    return h * w;
}

// Returns perimeter of the shape
double Shape::perimeter(){
    return 2 * (h + w);
}

// Return height of the shape
double Shape::height(){
    return h;
}

// Return width of the shape
double Shape::width(){
    return w;
}

// Rotate 90 degrees
void Shape::rotate(){
    double temp = h;
    h = w;
    w = temp;
}

///////////////////////////////////RECTANGLE///////////////////////////////////
// Constructor
Rectangle::Rectangle(double a, double b){
    h = a;
    w = b;
}

/////////////////////////////////SQUARE////////////////////////////////////////
// Constructor
Square::Square(double a) : Rectangle(a, a){
    Rectangle(a, a);
}
/////////////////////////////////CIRCLE////////////////////////////////////////
// Constructor
Circle::Circle(double a){
    radius = a;
}

// Returns area of the circle
double Circle::area(){
    return M_PI * radius * radius;
}

// Returns perimeter of the circle
double Circle::perimeter(){
    return 2 * M_PI * radius;
}

// Returns height of the circle
double Circle::height(){
    return 2 * radius;
}

// Returns width of the circle
double Circle::width(){
    return 2 * radius;
}

// Rotate 90 degrees
void Circle::rotate() {} // Do nothing
