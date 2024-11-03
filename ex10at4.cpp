#include <iostream>
#include <string>

using namespace std;

int main() {
    // Chaîne de caractères contenant la date et l'heure
    string dateHeure;

    cout << "Entrez la date et l'heure au format JJMMAAAAHHNN : ";
    cin >> dateHeure;

    // Vérifier que la chaîne a la bonne longueur
    if (dateHeure.length() != 12) {
        cout << "Format invalide. Assurez-vous d'utiliser 12 chiffres." << endl;
        return 1;
    }
    string jour = dateHeure.substr(0, 2);
    string mois = dateHeure.substr(2, 2);
    string annee = dateHeure.substr(4, 4);
    string heure = dateHeure.substr(8, 2);
    string minute = dateHeure.substr(10, 2);
    cout << "Jour : " << jour << endl;
    cout << "Mois : " << mois << endl;
    cout << "Année : " << annee << endl;
    cout << "Heure : " << heure << endl;
    cout << "Minute : " << minute << endl;

    return 0;
}

