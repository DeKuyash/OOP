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



class AlphaCircle : public Circle {
public:
    unsigned char alpha = 0;

    AlphaCircle() {
        cout << "\nСоздается AlphaCircle конструктором по умолчанию.";
    }

    AlphaCircle(int x, int y, int radius, char alpha) : Circle(x, y, radius) {
        this->alpha = alpha;
        cout << format("\nСоздается AlphaCircle: x = {}, y = {}, r = {}, alpha = {}", this->x, this->y, this->radius, this->alpha);
    }


    string isA() override { return "AlphaCircle"; }


    ~AlphaCircle() {
        cout << "\nУдаляется AlphaCircle.";
    }
};



class ColorCircle : public Circle {
public:
    string color = "without";

    ColorCircle() {
        cout << "\nСоздается ColorCircle конструктором по умолчанию.";
    }

    ColorCircle(int x, int y, int radius, string color) : Circle(x, y, radius) {
        this->color = color;
        cout << format("\nСоздается ColorCircle: x = {}, y = {}, r = {}, color = {}", this->x, this->y, this->radius, this->color);
    }

    ColorCircle(int x, int y) : Circle(x, y) {
        cout << format("\nСоздается ColorCircle: x = {}, y = {}, r = {}, color = {}", this->x, this->y, this->radius, this->color);
    }


    void spin() {
        // Circle::spin();
        cout << "\nColorCircle прокрутили.";
    }


    string isA() override { return "ColorCircle"; }


    ~ColorCircle() {
        cout << "\nУдаляется ColorCircle.";
    }
};



class Spinner {
public:
    Circle obj1;
    Circle* obj2;

    Spinner() {
        cout << "\nСоздается Spinner конструктором по умолчанию.";
    }

    Spinner(Circle& obj1, Circle* obj2) {
        this->obj1 = obj1;
        this->obj2 = obj2;
        cout << format("\nСоздается Spinner: первый круг на нем - {}, второй круг на нем - {}", this->obj1.isA(), this->obj2->isA());
    }


    void spin() {
        this->obj1.spin();
        this->obj2->spin();
    }
};



int main() {
    setlocale(LC_ALL, "Russian");

    ColorCircle obj1;
    AlphaCircle* obj2 = new AlphaCircle();

    Spinner* spinrs = new Spinner(obj1, obj2);

    spinrs->spin();

    delete(obj2);

    return 0;
}
