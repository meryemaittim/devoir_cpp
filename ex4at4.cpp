#include <iostream>
#include <cmath>
using namespace std;
class vecteur3d {
private:
    float x, y, z;
public:
    // Constructeur avec valeurs par défaut
    vecteur3d(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    // Fonction d'affichage des composantes
    void afficher() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
    // Fonction pour obtenir la somme de 2 vecteurs
    vecteur3d somme(const vecteur3d& v) const {
        return vecteur3d(x + v.x, y + v.y, z + v.z);
    }
    // Fonction pour obtenir le produit scalaire de 2 vecteurs
    float produitScalaire(const vecteur3d& v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    // Fonction pour vérifier si 2 vecteurs ont les mêmes composantes
    bool coincide(const vecteur3d& v) const {
        return (x == v.x && y == v.y && z == v.z);
    }
    // Fonction pour renvoyer la norme du vecteur
    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Fonction pour obtenir le vecteur avec la plus grande norme
    static vecteur3d* normax(const vecteur3d& v1, const vecteur3d& v2) {
        return (v1.norme() > v2.norme()) ? new vecteur3d(v1) : new vecteur3d(v2);
    }

    // Fonction pour obtenir le vecteur avec la plus grande norme (par référence)
    static vecteur3d& normaxRef(vecteur3d& v1, vecteur3d& v2) {
        return (v1.norme() > v2.norme()) ? v1 : v2;
    }
    // Fonction pour obtenir le vecteur avec la plus grande norme (par adresse)
    static vecteur3d* normaxAdr(vecteur3d* v1, vecteur3d* v2) {
        return (v1->norme() > v2->norme()) ? v1 : v2;
    }
};
int main() {
    vecteur3d v1(1.0, 2.0, 3.0);
    vecteur3d v2(1.0, 2.0, 3.0);
    cout << "V1: ";
    v1.afficher();
    cout << "V2: ";
    v2.afficher();
    vecteur3d v3 = v1.somme(v2);
    cout << "Somme de V1 et V2: ";
    v3.afficher();
    float produit = v1.produitScalaire(v2);
    cout << "Produit scalaire de V1 et V2: " << produit << endl;
    cout << "V1 coincide avec V2? " << (v1.coincide(v2) ? "Oui" : "Non") << endl;
    cout << "Norme de V1: " << v1.norme() << endl;
    cout << "Norme de V2: " << v2.norme() << endl;
    vecteur3d* maxNormeAdr = vecteur3d::normaxAdr(&v1, &v2);
    cout << "Vecteur avec la plus grande norme (par adresse): ";
    maxNormeAdr->afficher();
    delete maxNormeAdr; // Libération de la mémoire
    vecteur3d& maxNormeRef = vecteur3d::normaxRef(v1, v2);
    cout << "Vecteur avec la plus grande norme (par référence): ";
    maxNormeRef.afficher();
    return 0;
}
