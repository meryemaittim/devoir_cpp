#include <iostream>
using namespace std;
// Fonction qui prend un tableau dynamique et sa taille
void testFunction(int* params, size_t size) {
    cout << "Function called with " << size << " parameters." << endl;
}
int main() {
    try { // surveiller pour génerer une exception
        for (size_t i = 1; ; i*=3) {
            // allocation dynamique d'un tableau de taille i
            int* params = new int[i];
            //initialiser chaque élément du tableau avec 1
            for (size_t j = 0; j < i; ++j) {
                params[j] = 1;
            }
            // Appeler la fonction avec le tableau et sa taille
            testFunction(params, i);
            // Libérer la mémoire allouée
            delete[] params;
        }
    } catch (...) {
        cout << "erreur d'allocation de memoire" << endl;
    }
    return 0;
}

