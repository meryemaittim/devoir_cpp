#include <iostream>

using namespace std;

// Structure repr�sentant un �l�ment de la liste
struct Element {
    int valeur;         // Valeur de l'�l�ment
    Element* suivant;   // Pointeur vers l'�l�ment suivant

    // Constructeur
    Element(int v) : valeur(v), suivant(nullptr) {}
};

// Classe repr�sentant la liste simplement cha�n�e
class Liste {
private:
    Element* tete;  // Pointeur vers le premier �l�ment de la liste

public:
    // Constructeur
    Liste() : tete(nullptr) {} // nulptr c'est a dire pointeur nul qui ne pointe vers aucune adresse memoire

    // Destructeur pour lib�rer la m�moire
    ~Liste() {
        while (tete != nullptr) {
            supprimerDebut();
        }
    }

    // M�thode pour ajouter un �l�ment au d�but de la liste
    void ajouterDebut(int valeur) {
        Element* nouvelElement = new Element(valeur);
        nouvelElement->suivant = tete;
        tete = nouvelElement;
    }

    // M�thode pour supprimer un �l�ment au d�but de la liste
    void supprimerDebut() {
        if (tete != nullptr) {
            Element* elementASupprimer = tete;
            tete = tete->suivant;  // Met � jour le pointeur de t�te
            delete elementASupprimer;  // Lib�re la m�moire
        }
    }

    // M�thode pour afficher la liste
    void afficher() const {
        Element* courant = tete;
        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }
        cout << "nullptr" << endl;  // Indique la fin de la liste
    }
};

// Exemple d'utilisation
int main() {
    Liste liste;
    liste.ajouterDebut(10);
    liste.ajouterDebut(20);
    liste.ajouterDebut(30);

    cout << "Liste actuelle : ";
    liste.afficher();

    liste.supprimerDebut();
    cout << "Liste apres suppression : ";
    liste.afficher();

    return 0;
}

