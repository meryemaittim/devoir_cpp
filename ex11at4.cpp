#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Traitement {
private:
    vector<int> nombres; // Attribut pour stocker les entiers

public:
    // Méthode pour initialiser le vecteur
    void Initialise() {
        int saisie;
        while (nombres.size() < 10) {
            cout << "Entrez un entier pair et non nul : ";
            cin >> saisie;

            // Vérifier si la saisie est un entier et si c'est un entier pair non nul
            if (cin.fail() || saisie == 0 || saisie % 2 != 0) {
                cin.clear(); // Réinitialiser l'état d'erreur
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorer l'entrée invalide
                cout << "Valeur invalide. Veuillez réessayer." << endl;
            } else {
                nombres.push_back(saisie); // Ajouter l'entier au vecteur
            }
        }
    }

    // Méthode récursive pour afficher les éléments du vecteur
    void show() {
        showRecursive(0);
    }

private:
    void showRecursive(int index) {
        if (index < nombres.size()) {
            cout << nombres[index] << " "; // Afficher l'élément actuel
            showRecursive(index + 1); // Appel récursif pour l'élément suivant
        }
    }

    // Méthode amie pour calculer la moyenne
    friend double moyenne(const Traitement& t);

    // Méthode amie pour calculer la médiane
    friend double median(const Traitement& t);
};

// Méthode amie pour calculer la moyenne
double moyenne(const Traitement& t) {
    if (t.nombres.empty()) return 0.0;
    double somme = 0.0;
    for (int nombre : t.nombres) {
        somme += nombre;
    }
    return somme / t.nombres.size();
}

// Méthode amie pour calculer la médiane
double median(const Traitement& t) {
    if (t.nombres.empty()) return 0.0;
    vector<int> copie = t.nombres; // Créer une copie pour trier
    sort(copie.begin(), copie.end()); // Trier la copie

    size_t taille = copie.size();
    if (taille % 2 == 0) {
        // Si la taille est paire, la médiane est la moyenne des deux éléments du milieu
        return (copie[taille / 2 - 1] + copie[taille / 2]) / 2.0;
    } else {
        // Si la taille est impaire, la médiane est l'élément du milieu
        return copie[taille / 2];
    }
}

int main() {
    Traitement t;
    t.Initialise();

    cout << "Les nombres saisis sont : ";
    t.show();
    cout << endl;

    cout << "Moyenne : " << moyenne(t) << endl;
    cout << "Mediane : " << median(t) << endl;

    return 0;
}
