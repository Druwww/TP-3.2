#include "Graphe.h"

Graphe::Graphe(): m_nomFichier(""), m_ordreGraphe(0)
{
    //ctor
}

Graphe::Graphe(std::string nom): m_nomFichier(nom), m_ordreGraphe(0){
    //ctor
}

Graphe::~Graphe()
{
    for(auto pSommet : m_vecSommet){
        pSommet->~Sommet();
        delete pSommet;
    }
}
