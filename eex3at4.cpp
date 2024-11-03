#include <iostream>
#include <string>
using namespace std;

// Classe Personne
class Personne {
private:
    string nom;
    string prenom;
    string date_naissance;
public:
    // Constructeur
    Personne(const string& n, const string& p, const string& dn){
        nom=n;
        prenom=p;
        date_naissance=dn;
    }
    // Méthode polymorphe Afficher
    virtual void Afficher() const {
        cout << "Nom: " << nom << ", Prenom: " << prenom << ", Date de naissance: " << date_naissance << endl;
    }
    virtual ~Personne() {} // Destructeur virtuel
};
// Classe Employe dérivant de Personne
class Employe : public Personne {
private:
    double salaire;

public:
    // Constructeur
   Employe(const string& n, const string& p, const string& dn, double s)
        : Personne(n, p, dn), salaire(s) {}
    // Redéfinition de la méthode Afficher
    void Afficher() const override {
        Personne::Afficher(); // Appel à la méthode de la classe mère
        cout << "Salaire: " << salaire <<  endl;
    }
};
// Classe Chef dérivant de Employe
class Chef : public Employe {
private:
    string service;

public:
    // Constructeur
    Chef(const string& n, const string& p, const string& dn, double s, const string& svc)
        : Employe(n, p, dn, s), service(svc) {}

    // Redéfinition de la méthode Afficher
    void Afficher() const override {
        Employe::Afficher(); // Appel à la méthode de la classe mère
        cout << "Service: " << service << endl;
    }
};

// Classe Directeur dérivant de Chef
class Directeur : public Chef {
private:
    string societe;

public:
    // Constructeur
    Directeur(const string& n, const string& p, const string& dn, double s, const string& svc, const string& soc)
        : Chef(n, p, dn, s, svc), societe(soc) {}

    // Redéfinition de la méthode Afficher
    void Afficher() const override {
        Chef::Afficher(); // Appel à la méthode de la classe mère
        cout << "Societe: " << societe << endl;
    }
};
int main() {
    // Création d'un Employé
    Employe employe("Durand", "Sophie", "10/10/1990", 50000);
    employe.Afficher();

    cout << endl;
    // Création d'un Chef
    Chef chef("Martin", "Alice", "15/05/1985", 75000, "Ressources Humaines");
    chef.Afficher();
    cout << endl;
// Création d'un Directeur
    Directeur directeur("Dupont", "Jean", "01/01/1980", 100000, "Informatique", "TechCorp");
    directeur.Afficher();
    return 0;
}

