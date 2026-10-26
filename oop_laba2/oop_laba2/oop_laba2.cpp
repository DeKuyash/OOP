#include <iostream>
#include <format>
using namespace std;

const int Pi = 3.14;

class Circle {
protected:
    int squareRadius = -1;

public:
    int radius = 0;
    int x = 0, y = 0;

    Circle() {
        cout << "\nСоздается Circle конструктором по умолчанию.";
    }

    Circle(int x, int y, int radius) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        cout << format("\nСоздается Circle: x = {}, y = {}, r = {}", this->x, this->y, this->radius);
    }

    Circle(int x, int y) {
        this->x = x;
        this->y = y;
        cout << format("\nСоздается Circle: x = {}, y = {}, r = {}", this->x, this->y, this->radius);
    }


    void setArea(int area) {
        this->squareRadius = area / Pi;
        cout << "Была изменена площадь Circle.";
    }

    int getArea() {
        cout << "\nПолучаем площадь Circle.";
        if (squareRadius > 0) return this->squareRadius * Pi;
        return this->radius * this->radius * Pi;
    }

    void spin() {
        cout << "\nCircle прокрутили.";
    }
    
    virtual string isA() { return "Circle"; }


    ~Circle() {
        cout << "\nУдаляется Circle.";
    }
};




int main() {
    setlocale(LC_ALL, "Russian");

    return 0;
}
