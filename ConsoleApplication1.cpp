#include <iostream>
#include <windows.h>

using namespace std;

class Massiv {
private:
    int* data;
    int length;

public:
    // Конструктор
    Massiv(int size) : length(size) {
        data = new int[length];
        for (int i = 0; i < length; ++i)
            data[i] = 0; // Ініціалізація нулями
    }

    // Деструктор
    ~Massiv() {
        delete[] data;
    }

    // Копіювальний конструктор
    Massiv(const Massiv& other) : length(other.length) {
        data = new int[length];
        for (int i = 0; i < length; ++i)
            data[i] = other.data[i];
    }

    // Оператор копіювального присвоєння з перевіркою на самоприсвоєння
    Massiv& operator=(const Massiv& other) {
        if (this == &other)
            return *this;

        delete[] data;

        length = other.length;
        data = new int[length];
        for (int i = 0; i < length; ++i)
            data[i] = other.data[i];

        return *this;
    }

    // Метод для зміни розміру масиву
    void resize(int newLength) {
        int* newData = new int[newLength];

        int minLength = (newLength < length) ? newLength : length;
        for (int i = 0; i < minLength; ++i)
            newData[i] = data[i];

        for (int i = minLength; i < newLength; ++i)
            newData[i] = 0; // Ініціалізація нових елементів

        delete[] data;
        data = newData;
        length = newLength;
    }

    // Метод для виведення вмісту масиву
    void print() const {
        for (int i = 0; i < length; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    // Метод для зміни значення елемента
    void set(int index, int value) {
        if (index >= 0 && index < length)
            data[index] = value;
    }

    // Метод для отримання довжини
    int size() const {
        return length;
    }
};

// Тестування
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Massiv a(5);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);
    cout << "Початковий масив: ";
    a.print();

    Massiv b = a; // Виклик копіювального конструктора
    cout << "Копія масиву: ";
    b.print();

    a.resize(7);
    cout << "Масив після resize: ";
    a.print();

    Massiv c(3);
    c = a; // Виклик оператора присвоєння
    cout << "Масив після присвоєння: ";
    c.print();

    return 0;
}
