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
    // M�thode polymorphe Afficher
    virtual void Afficher() const {
        cout << "Nom: " << nom << ", Prenom: " << prenom << ", Date de naissance: " << date_naissance << endl;
    }
    virtual ~Personne() {} // Destructeur virtuel
};
// Classe Employe d�rivant de Personne
class Employe : public Personne {
private:
    double salaire;

public:
    // Constructeur
   Employe(const string& n, const string& p, const string& dn, double s)
        : Personne(n, p, dn), salaire(s) {}
    // Red�finition de la m�thode Afficher
    void Afficher() const override {
        Personne::Afficher(); // Appel � la m�thode de la classe m�re
        cout << "Salaire: " << salaire <<  endl;
    }
};
// Classe Chef d�rivant de Employe
class Chef : public Employe {
private:
    string service;

public:
    // Constructeur
    Chef(const string& n, const string& p, const string& dn, double s, const string& svc)
        : Employe(n, p, dn, s), service(svc) {}

    // Red�finition de la m�thode Afficher
    void Afficher() const override {
        Employe::Afficher(); // Appel � la m�thode de la classe m�re
        cout << "Service: " << service << endl;
    }
};

// Classe Directeur d�rivant de Chef
class Directeur : public Chef {
private:
    string societe;

public:
    // Constructeur
    Directeur(const string& n, const string& p, const string& dn, double s, const string& svc, const string& soc)
        : Chef(n, p, dn, s, svc), societe(soc) {}

    // Red�finition de la m�thode Afficher
    void Afficher() const override {
        Chef::Afficher(); // Appel � la m�thode de la classe m�re
        cout << "Societe: " << societe << endl;
    }
};
int main() {
    // Cr�ation d'un Employ�
    Employe employe("Durand", "Sophie", "10/10/1990", 50000);
    employe.Afficher();

    cout << endl;
    // Cr�ation d'un Chef
    Chef chef("Martin", "Alice", "15/05/1985", 75000, "Ressources Humaines");
    chef.Afficher();
    cout << endl;
// Cr�ation d'un Directeur
    Directeur directeur("Dupont", "Jean", "01/01/1980", 100000, "Informatique", "TechCorp");
    directeur.Afficher();
    return 0;
}

