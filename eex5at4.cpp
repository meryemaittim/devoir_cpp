#include <iostream>
using namespace std;

class Test {
    private:
    static int c; // D�claration de la variable statique
    public:
    // M�thode qui compte le nombre d'appels
      void call() {
        // Incr�menter le compteur statique � chaque appel
        c++;
        cout << "La methode call() a ete appelee " << c << " fois." << endl;
    }
    // M�thode statique pour obtenir le nombre total d'appels
      static int get_c() {
        return c;
    }

};
// Initialisation de la variable statique
int Test::c = 0;
int main() {
    Test test1;
    Test test2;

    // Appels de la m�thode call()
    test1.call();
    test1.call();
    test2.call();

    // Affichage du nombre total d'appels
    cout << "Nombre total d'appels de la methode call()est: " << Test::get_c() << endl;

    return 0;
}
