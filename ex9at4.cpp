#include <iostream>

using namespace std;

// Structure représentant un élément de la liste
struct Element {
    int valeur;         // Valeur de l'élément
    Element* suivant;   // Pointeur vers l'élément suivant

    // Constructeur
    Element(int v) : valeur(v), suivant(nullptr) {}
};

// Classe représentant la liste simplement chaînée
class Liste {
private:
    Element* tete;  // Pointeur vers le premier élément de la liste

public:
    // Constructeur
    Liste() : tete(nullptr) {} // nulptr c'est a dire pointeur nul qui ne pointe vers aucune adresse memoire

    // Destructeur pour libérer la mémoire
    ~Liste() {
        while (tete != nullptr) {
            supprimerDebut();
        }
    }

    // Méthode pour ajouter un élément au début de la liste
    void ajouterDebut(int valeur) {
        Element* nouvelElement = new Element(valeur);
        nouvelElement->suivant = tete;
        tete = nouvelElement;
    }

    // Méthode pour supprimer un élément au début de la liste
    void supprimerDebut() {
        if (tete != nullptr) {
            Element* elementASupprimer = tete;
            tete = tete->suivant;  // Met à jour le pointeur de tête
            delete elementASupprimer;  // Libère la mémoire
        }
    }

    // Méthode pour afficher la liste
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

