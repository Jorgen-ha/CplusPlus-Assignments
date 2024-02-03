#ifndef __shape__
#define __shape__

class Shape{
public:
    // Standard constructor: constructs a shape with height a and width b
    // Shape(double a, double b);

    // Destructor
    ~Shape(void) {};

    // Returns the area of the shape
    virtual double area();

    // Returns perimeter of the shape
    virtual double perimeter();

    // Return height of the shape
    virtual double height();

    // Return width of the shape
    virtual double width();

    // Rotate 90 degrees
    virtual void rotate();

// private:
    double h, w;

};

class Rectangle : public Shape{
public:
    // Standard constructor: constructs a rectangle with height a and width b
    Rectangle(double a, double b);
};

class Square : public Rectangle{
public:
    Square(double a);
};

class Circle : public Shape{
public:
    // Standard constructor: constructs a circle with radius a
    Circle(double a);

    // Returns area of the circle
    double area() override;
    
    // Returns perimeter of the circle
    double perimeter() override;

    // Return height of the circle
    double height() override;

    // Return width of the circle
    double width() override;

    // Do nothing (circles cannot be rotated)
    void rotate() override;

private:
    double radius;
};

#endif

