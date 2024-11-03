#include <iostream>
using namespace std;

class Pile {
private:
    int* elements;
    int capacite;
    int sommet;

public:
    // Constructeur
    Pile(int capacite) : capacite(capacite), sommet(-1) {
        elements = new int[capacite]; // Allouer la m�moire pour les �l�ments
    }
    // Destructeur
    ~Pile() {
        delete[] elements; // Lib�rer la m�moire allou�e
    }
    // Empiler un �l�ment
    void push(int valeur) {
        if (sommet < capacite - 1) {
            elements[++sommet] = valeur; // Incr�menter sommet et ajouter l'�l�ment
        } else {
            cout << "Erreur : La pile est pleine." << endl;
        }
    }
    // D�piler un �l�ment
    int pop() {
        if (sommet >= 0) {
            return elements[sommet--]; // Retourner l'�l�ment du sommet et le supprimer
        } else {
            cout << "Erreur : La pile est vide." << endl;
            return -1; // Valeur de retour en cas de pile vide
        }
    }

    // V�rifier si la pile est vide
    bool estVide() {
        return sommet == -1;
    }
};

int main() {
    Pile p1(5);
    Pile p2(5);
    // Empiler des valeurs dans p1
    p1.push(10);
    p1.push(20);
    p1.push(30);
    // Empiler des valeurs dans p2
    p2.push(40);
    p2.push(50);
    // D�piler les valeurs de p1
    cout << "Depiler p1 : " << p1.pop() << endl;
    cout << "Depiler p1 : " << p1.pop() << endl;
    cout << "Depiler p1 : " << p1.pop() << endl;
    cout << "Depiler p1 : " << p1.pop() << endl;
    // D�piler les valeurs de p2
    cout << "Depiler p2 : " << p2.pop() << endl;
    cout << "Depiler p2 : " << p2.pop() << endl;
    cout << "Depiler p2 : " << p2.pop() << endl;
    return 0;
}
