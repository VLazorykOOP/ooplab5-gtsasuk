#include <iostream>

using namespace std;

class Pair {
public:
    Pair(int num1, int num2) : num1(num1), num2(num2) {}
    void SetPair(int newnum1, int newnum2) {
        num1 = newnum1;
        num2 = newnum2;
    }
    void display() {
        cout << "Pair: (" << num1 << ", " << num2 << ")" << endl;
    }
    int Sum() {
        return num1 + num2;
    }

protected:
    int num1;
    int num2;
};

class Rectangle : public Pair {
public:
    Rectangle(int length, int width) : Pair(length, width) {}
    int Perimeter() {
        return 2 * (num1 + num2);
    }
    int Area() {
        return num1 * num2;
    }
};

int main() {
    Rectangle MyRectangle(5, 8);
    MyRectangle.display();
    cout << "Perimeter: " << MyRectangle.Perimeter() << endl;
    cout << "Area: " << MyRectangle.Area() << endl;
    MyRectangle.SetPair(3, 6);
    MyRectangle.display();
    return 0;
}
