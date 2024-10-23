#include <iostream>
#include <string>
class Voiture {
private:
    std::string marque;
    std::string modele;
    int annee;
    float kilometrage;
    float vitesse;
public:
    // constructeur par défaut
    Voiture() {
        marque = "Inconnu";
        modele = "Inconnu";
        annee = 2000;
        kilometrage = 0;
        vitesse = 0;
    }
    // constructeur avec parametres
    Voiture(const std::string& m, const std::string& mod, int a, float km, float v)
        {
        marque=m;
        modele=mod;
        annee=a;
        kilometrage=km;
        vitesse=v;
        }
    void accelerer(float valeur) {
        vitesse += valeur;
        std::cout << "La voiture accelere de " << valeur << " km/h\t Vitesse actuelle: " << vitesse << " km/h" << std::endl;
    }

    void freiner(float valeur) {
        if (vitesse - valeur < 0) {
            vitesse = 0;
        } else {
            vitesse -= valeur;
        }
        std::cout << "La voiture freine de " << valeur << " km/h\t Vitesse actuelle: " << vitesse << " km/h" << std::endl;
    }
    void afficherInfo() const {
        std::cout << "Marque : " << marque << std::endl;
        std::cout << "Modele : " << modele << std::endl;
        std::cout << "Annee : " << annee << std::endl;
        std::cout << "Kilometrage : " << kilometrage << " km" << std::endl;
        std::cout << "Vitesse : " << vitesse << " km/h" << std::endl;
    }
    void avancer(float distance) {
        kilometrage += distance;
        std::cout << "La voiture avance de " << distance << " km\t Kilometrage actuel: " << kilometrage << " km" << std::endl;
    }
    // destructeur
    ~Voiture() {
        std::cout << "\t La voiture " << marque << " " << modele << " est detruite \t" << std::endl;
    }
};
int main() {
    // creation d'une voiture avec le constructeur par defaut
    Voiture voiture1;
    voiture1.afficherInfo();
    // creation d'une voiture avec le constructeur avec parametres
    Voiture voiture2("renault", "clio", 2020, 15000, 120);
    voiture2.afficherInfo();
    //les méthodes de comportement
    voiture2.accelerer(30);
    voiture2.freiner(50);
    voiture2.avancer(100);
    return 0;
}
