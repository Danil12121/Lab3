/*
 * Создать базовый класс «вектор на плоскости».
 * Элементы класса: поля, задающие координаты точки
 * (статус доступа protected), определяющей конец вектора
 * (начало вектора находится в точке с координатами 0, 0);
 * конструктор для инициализации полей; функция для печати
 * координат вектора. Создать производный класс «вектор в
 * трехмерном пространстве». Элементы класса: дополнительное поле,
 * задающее дополнительную координату; конструктор для инициализации
 * полей; переопределенная функция для печати координат вектора
 * (внутри переопределенной функции должна вызываться функция из
 * базового класса). Создать по 1 объекту каждого из классов.
 * Показать вызов созданных функций. При переопределении функций
 * обеспечить и продемонстрировать два варианта: статический полиморфизм и динамический полиморфизм.
 */

#include <iostream>
using namespace std;

class PlaneVector {
protected:
    double x, y;
public:
    PlaneVector(double x1, double y1){
        this -> x = x1;
        this -> y = y1;
    }

    virtual void print() const {
        cout << "2D (" << x << ", " << y << ")" << endl;
    }

    virtual ~PlaneVector() = default;
};

class SpaceVector : public PlaneVector {
protected:
    double z;
public:
    SpaceVector(double x_val, double y_val, double z_val)
            : PlaneVector(x_val, y_val), z(z_val) {}

    void print() const override {
        PlaneVector::print();
        cout << "3D (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    cout << "\nStatic" << endl;
    PlaneVector v1(1.0, 2.0);
    SpaceVector v2(3.0, 4.0, 5.0);

    v1.print();
    v2.print();

    cout << "\nDinamic" << endl;
    PlaneVector* ptr;

    ptr = &v1;
    ptr->print();

    ptr = &v2;
    ptr->print();

    return 0;
}
