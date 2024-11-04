#include <iostream>
template < typename T>
using namespace std
class NombreComplexe {
private:
    T re;
    T im;

public:
    NombreComplexe():re(0),im(0){}
     NombreComplexe(T r,T i): re(r), im(i){}
     NombreComplexe(const NombreComplexe<T>& autre)
        : re(autre.re), im(autre.im) {}
    void afficher() const {
        cout << reel << ((im >= 0) ? " + " : " - ")
                  << ((im >= 0) ? im : -im) << "i" << endl;
    }
    NombreComplexe<T> operator+(const NombreComplexe<T>& autre) const {
        return NombreComplexe<T>(re + autre.re, im + autre.im);
    }
    NombreComplexe<T> operator-(const NombreComplexe<T>& autre) const {
        return NombreComplexe<T>(re - autre.re, im - autre.im);
    }
NombreComplexe<T> operator*(const NombreComplexe<T>& autre) const {
        T newReel = re * autre.re - im * autre.im;
        T newImaginaire = re * autre.im + im * autre.re;
        return NombreComplexe<T>(newReel, newImaginaire);
    }
    NombreComplexe<T> operator/(const NombreComplexe<T>& autre) const {
        T denominateur = autre.reel * autre.reel + autre.imaginaire * autre.imaginaire;
        if (denominateur == 0) {
   NombreComplexe <T> operator/ (const NombreComplexe<T>& autre) const {
   T denominateur =autre.re * autre.re + autre.im*autre.im;
   if(denominateur==0){
    throw runtime_error("Division par zéro!");
        }
        T newReel = (reel * autre.reel + imaginaire * autre.imaginaire) / denominateur;
        T newImaginaire = (imaginaire * autre.reel - reel * autre.imaginaire) / denominateur;
        return NombreComplexe<T>(newReel, newImaginaire);
    }

