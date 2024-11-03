#include <iostream>
using namespace std;
class Complex {
private:
    double reelle;
    double imag;
public:
    Complex(double r = 0, double i = 0) : reelle(r), imag(i) {}
    void display() const {
        cout << "(" << reelle << ", " << imag << "i)";
    }
    Complex operator+(const Complex& other) const {
        return Complex(reelle + other.reelle, imag + other.imag);
    }
    Complex operator-(const Complex& other) const {
        return Complex(reelle - other.reelle, imag - other.imag);
    }
    Complex operator*(const Complex& other) const {
        return Complex(reelle * other.reelle - imag * other.imag, reelle * other.imag + imag * other.reelle);
    }
    Complex operator/(const Complex& other) const {
        double denom = other.reelle * other.reelle + other.imag * other.imag;
        if (denom == 0) {
            throw runtime_error("Division par zero");
        }
        return Complex((reelle * other.reelle + imag * other.imag) / denom, (imag * other.reelle - reelle * other.imag) / denom);
    }
    bool operator==(const Complex& other) const {
        return (reelle == other.reelle && imag == other.imag);
    }
};
int main() {
    double reelle1, imag1, reelle2, imag2;
    cout << "Entrez la partie reelle et imaginaire du premier nombre complexe : ";
    cin >> reelle1 >> imag1;
    cout << "Entrez la partie reelle et imaginaire du deuxieme nombre complexe : ";
    cin >> reelle2 >> imag2;
    Complex num1(reelle1, imag1);
    Complex num2(reelle2, imag2);

    int choix;
    cout << "\nChoisissez une operation :\n";
    cout << "1. Addition\n2. Soustraction\n3. Multiplication\n4. Division\n5. Egalite\n";
    cout << "Votre choix : ";
    cin >> choix;
    try {
        switch (choix) {
            case 1: {
                Complex result = num1 + num2;
                cout << "Resultat de l'addition : ";
                result.display();
                break;
            }
            case 2: {
                Complex result = num1 - num2;
                cout << "Resultat de la soustraction : ";
                result.display();
                break;
            }
            case 3: {
                Complex result = num1 * num2;
                cout << "Resultat de la multiplication : ";
                result.display();
                break;
            }
            case 4: {
                Complex result = num1 / num2;
                cout << "Resultat de la division : ";
                result.display();
                break;
            }
            case 5: {
                if (num1 == num2) {
                    cout << "Les nombres complexes sont egaux.";
                } else {
                    cout << "Les nombres complexes ne sont pas egaux.";
                }
                break;
            }
            default:
                cout << "Choix invalide.";
        }
    } catch (const runtime_error& e) {
        cout << "Erreur : " << e.what();
    }

    return 0;
}

