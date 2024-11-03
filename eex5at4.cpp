#include <iostream>
using namespace std;

class Test {
    private:
    static int c; // Déclaration de la variable statique
    public:
    // Méthode qui compte le nombre d'appels
      void call() {
        // Incrémenter le compteur statique à chaque appel
        c++;
        cout << "La methode call() a ete appelee " << c << " fois." << endl;
    }
    // Méthode statique pour obtenir le nombre total d'appels
      static int get_c() {
        return c;
    }

};
// Initialisation de la variable statique
int Test::c = 0;
int main() {
    Test test1;
    Test test2;

    // Appels de la méthode call()
    test1.call();
    test1.call();
    test2.call();

    // Affichage du nombre total d'appels
    cout << "Nombre total d'appels de la methode call()est: " << Test::get_c() << endl;

    return 0;
}
