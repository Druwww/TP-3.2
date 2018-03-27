#ifndef GRAPHEARETE_H
#define GRAPHEARETE_H

#include "../headers.h"
#include "Arete.h"

class GrapheArete
{
    private:
        std::string m_nomFichier;
        int m_nbArete;
        std::vector<Arete*> m_vecArete;

        int m_nbSommet;

    public:
        GrapheArete();
        GrapheArete(std::string nomFichier);
        virtual ~GrapheArete();

        std::string GetnomFichier() { return m_nomFichier; }
        void SetnomFichier(std::string val) { m_nomFichier = val; }

        int GetnbArete() { return m_nbArete; }
        void SetnbArete(int val) { m_nbArete = val; }

        std::vector<Arete*> GetvecArete() { return m_vecArete; }
        void SetvecArete(std::vector<Arete*> val) { m_vecArete = val; }

        int GetnbSommet() { return m_nbSommet; }
        void SetnbSommet(int val) { m_nbSommet = val; }

        void chargementFichier();

        void affichageAretes();

};

#endif // GRAPHEARETE_H
