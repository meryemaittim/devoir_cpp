#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Traitement {
private:
    vector<int> nombres; // Attribut pour stocker les entiers

public:
    // M�thode pour initialiser le vecteur
    void Initialise() {
        int saisie;
        while (nombres.size() < 10) {
            cout << "Entrez un entier pair et non nul : ";
            cin >> saisie;

            // V�rifier si la saisie est un entier et si c'est un entier pair non nul
            if (cin.fail() || saisie == 0 || saisie % 2 != 0) {
                cin.clear(); // R�initialiser l'�tat d'erreur
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorer l'entr�e invalide
                cout << "Valeur invalide. Veuillez r�essayer." << endl;
            } else {
                nombres.push_back(saisie); // Ajouter l'entier au vecteur
            }
        }
    }

    // M�thode r�cursive pour afficher les �l�ments du vecteur
    void show() {
        showRecursive(0);
    }

private:
    void showRecursive(int index) {
        if (index < nombres.size()) {
            cout << nombres[index] << " "; // Afficher l'�l�ment actuel
            showRecursive(index + 1); // Appel r�cursif pour l'�l�ment suivant
        }
    }

    // M�thode amie pour calculer la moyenne
    friend double moyenne(const Traitement& t);

    // M�thode amie pour calculer la m�diane
    friend double median(const Traitement& t);
};

// M�thode amie pour calculer la moyenne
double moyenne(const Traitement& t) {
    if (t.nombres.empty()) return 0.0;
    double somme = 0.0;
    for (int nombre : t.nombres) {
        somme += nombre;
    }
    return somme / t.nombres.size();
}

// M�thode amie pour calculer la m�diane
double median(const Traitement& t) {
    if (t.nombres.empty()) return 0.0;
    vector<int> copie = t.nombres; // Cr�er une copie pour trier
    sort(copie.begin(), copie.end()); // Trier la copie

    size_t taille = copie.size();
    if (taille % 2 == 0) {
        // Si la taille est paire, la m�diane est la moyenne des deux �l�ments du milieu
        return (copie[taille / 2 - 1] + copie[taille / 2]) / 2.0;
    } else {
        // Si la taille est impaire, la m�diane est l'�l�ment du milieu
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
