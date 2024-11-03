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
        elements = new int[capacite]; // Allouer la mémoire pour les éléments
    }
    // Destructeur
    ~Pile() {
        delete[] elements; // Libérer la mémoire allouée
    }
    // Empiler un élément
    void push(int valeur) {
        if (sommet < capacite - 1) {
            elements[++sommet] = valeur; // Incrémenter sommet et ajouter l'élément
        } else {
            cout << "Erreur : La pile est pleine." << endl;
        }
    }
    // Dépiler un élément
    int pop() {
        if (sommet >= 0) {
            return elements[sommet--]; // Retourner l'élément du sommet et le supprimer
        } else {
            cout << "Erreur : La pile est vide." << endl;
            return -1; // Valeur de retour en cas de pile vide
        }
    }

    // Vérifier si la pile est vide
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
    // Dépiler les valeurs de p1
    cout << "Depiler p1 : " << p1.pop() << endl;
    cout << "Depiler p1 : " << p1.pop() << endl;
    cout << "Depiler p1 : " << p1.pop() << endl;
    cout << "Depiler p1 : " << p1.pop() << endl;
    // Dépiler les valeurs de p2
    cout << "Depiler p2 : " << p2.pop() << endl;
    cout << "Depiler p2 : " << p2.pop() << endl;
    cout << "Depiler p2 : " << p2.pop() << endl;
    return 0;
}
