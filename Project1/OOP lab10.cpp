#include <iostream>
#include <cmath>

class Triangle {
protected:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double s1, double s2) : Triangle(s1, s2, sqrt(s1* s1 + s2 * s2)) {}

    double getArea() const override {
        return 0.5 * side1 * side2;
    }

    double getPerimeter() const override {
        return side1 + side2 + side3;
    }

    double getInscribedRadius() const {
        return (side1 + side2 - side3) / 2.0;
    }

    double getCircumscribedRadius() const {
        return side3 / 2.0;
    }
};

int main() {
    // Приклад використання
    RightTriangle rt(3.0, 4.0);

    std::cout << "Area: " << rt.getArea() << std::endl;
    std::cout << "Perimeter: " << rt.getPerimeter() << std::endl;
    std::cout << "Inscribed Radius: " << rt.getInscribedRadius() << std::endl;
    std::cout << "Circumscribed Radius: " << rt.getCircumscribedRadius() << std::endl;

    return 0;
}
