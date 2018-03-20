#ifndef SOMMET_H
#define SOMMET_H

#include "../headers.h"
#include "Noeud.h"

#define INFINI_MAX 100000

class Sommet
{
    private:
        int m_numero;
        Noeud* m_teteNoeud;
        int m_puissance;

        int m_antecedantGraphe;
        int m_poidCumule;

        bool m_marque;


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

        int GetAntecedantGraphe() { return m_antecedantGraphe; }
        void SetAntecedantGraphe(int val) { m_antecedantGraphe = val; }

        int GetPoidCumule() { return m_poidCumule; }
        void SetPoidCumule(int val) { m_poidCumule = val; }

        bool GetMarque(){return m_marque;}
        void SetMarque(bool val){m_marque = val;}

        ///Methode
        void remplissagePuissance();

        void ajoutLiaison(int sommetA, int poid);

        void affichageLiaisons();

        int poidLiaisonAvec(int sommetD);
};

#endif // SOMMET_H
