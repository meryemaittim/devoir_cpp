#include <iostream>
using namespace std;
// Classe mère Animal
class Animal {
protected:
    string name;
    int age;
public:
    void set_value(const string& n, int a) {
        name = n;
        age = a;
    }
};
// Sous-classe Zebra
class Zebra : public Animal {
public:
    void display_info() {
        cout << "Zebra: " << name << ", Age: " << age << " years." << endl;
        cout << "Origin: Africa." << endl;
    }
};
// Sous-classe Dolphin
class Dolphin : public Animal {
public:
    void display_info() {
        cout << "Dolphin: " << name << ", Age: " << age << " years." << endl;
        cout << "Origin: Oceans worldwide." << endl;
    }
};
int main() {
    Zebra zebra;
    zebra.set_value("zebre", 5);
    zebra.display_info();
    Dolphin dolphin;
    dolphin.set_value("dauphine", 3);
    dolphin.display_info();
    return 0;
}

