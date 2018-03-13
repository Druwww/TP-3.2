#include "Sommet.h"

Sommet::Sommet(): m_teteNoeud(NULL), m_puissance(0)
{
    //ctor
}

Sommet::Sommet(int numero): m_numero(numero), m_teteNoeud(NULL), m_puissance(0){

    //ctor
}

Sommet::~Sommet()
{
    Noeud* pNoeud = m_teteNoeud;
    Noeud* pNoeudTemp;

    while(pNoeud != NULL){
        pNoeudTemp = pNoeud;
        delete pNoeud;
        pNoeud = pNoeudTemp->GetpNext();
    }
}
