#ifndef SOMMET_H
#define SOMMET_H

#include "../headers.h"
#include "Noeud.h"

class Sommet
{
    private:
        int m_numero;
        Noeud* m_teteNoeud;
        int m_puissance;


    public:
        Sommet();
        Sommet(int numero);
        virtual ~Sommet();

        int GetNumero() { return m_numero; }
        void SetNumero(int val) { m_numero = val; }

        Noeud* GetteteNoeud() { return m_teteNoeud; }
        void SetteteNoeud(Noeud* val) { m_teteNoeud = val; }

        int Getpuissance() { return m_puissance; }
        void Setpuissance(int val) { m_puissance = val; }

        ///Methode
        void remplissagePuissance();

        void ajoutLiaison(int sommetA, int poid);

        void affichageLiaisons();
};

#endif // SOMMET_H
