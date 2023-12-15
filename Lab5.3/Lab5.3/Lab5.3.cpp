#include <iostream>
#include <string>

using namespace std;

class Point {
public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point& other) : x(other.x), y(other.y) {}
    Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }
    // Віртуальний деструктор
    virtual ~Point() {}
    // Віртуальна функція для виводу в потік
    virtual void print() const {
        cout << "Point: (" << x << ", " << y << ")";
    }
    // Віртуальна функція для введення з потоку
    virtual void input() {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }
protected:
    int x;
    int y;
};

class ColoredPoint : public Point {
public:
    ColoredPoint() : Point(), color("Black") {}
    ColoredPoint(int x, int y, const string& color) : Point(x, y), color(color) {}
    ColoredPoint(const ColoredPoint& other) : Point(other), color(other.color) {}
    ColoredPoint& operator=(const ColoredPoint& other) {
        if (this != &other) {
            Point::operator=(other);
            color = other.color;
        }
        return *this;
    }
    // Віртуальна функція для виводу в потік
    virtual void print() const override {
        cout << "Colored Point: (" << x << ", " << y << "), Color: " << color;
    }
    // Віртуальна функція для введення з потоку
    virtual void input() override {
        Point::input();
        cout << "Enter color: ";
        cin >> color;
    }

private:
    string color;
};

int main() {
    Point p1(1, 2);
    ColoredPoint cp1(3, 4, "Red");
    p1.print();
    cout << endl;
    cp1.print();
    cout << endl;
    ColoredPoint cp2;
    cp2.input();
    cp2.print();
    return 0;
}
