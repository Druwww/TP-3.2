#ifndef GRAPHE_H
#define GRAPHE_H

#include "../headers.h"
#include "Sommet.h"

class Graphe
{

    private:
        std::string m_nomFichier;
        int m_ordreGraphe;
        std::vector<Sommet*> m_vecSommet;

    public:
        Graphe();
        Graphe(std::string nom);
        virtual ~Graphe();

        std::string GetnomFichier() { return m_nomFichier; }
        void SetnomFichier(std::string val) { m_nomFichier = val; }

        int GetordreGraphe() { return m_ordreGraphe; }
        void SetordreGraphe(int val) { m_ordreGraphe = val; }

        std::vector<Sommet*> GetvecSommet() { return m_vecSommet; }
        void SetvecSommet(std::vector<Sommet*> val) { m_vecSommet = val; }

        ///Methodes

        void ajoutSommet(int numero);

        void ajoutLiaisonDeuxSommet(int numeroD, int numeroA, int poid);

};

#endif // GRAPHE_H
