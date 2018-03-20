#include "Sommet.h"

Sommet::Sommet(): m_teteNoeud(NULL), m_puissance(0)
{
    m_teteNoeud = new Noeud();
}

Sommet::Sommet(int numero): m_numero(numero), m_teteNoeud(NULL), m_puissance(0){

    m_teteNoeud = new Noeud();
}

Sommet::~Sommet()
{
    Noeud* pNoeud = m_teteNoeud;
    Noeud* pNoeudTemp;

    for(int i = 0; i < m_puissance; i++){
        pNoeudTemp = pNoeud;
        delete pNoeud;
        pNoeud = pNoeudTemp->GetpNext();
    }
}

void Sommet::remplissagePuissance(){

    Noeud* pNoeud = m_teteNoeud;
    while(pNoeud != NULL){
        m_puissance++;
        pNoeud = pNoeud->GetpNext();
    }
}

void Sommet::ajoutLiaison(int sommetA, int poid){

    Noeud* pNoeudEtude = m_teteNoeud;

    while(pNoeudEtude->GetpNext() != NULL){
        pNoeudEtude = pNoeudEtude->GetpNext();
    }

    pNoeudEtude->SetpNext(new Noeud(sommetA, poid));
    m_puissance++;

}

void Sommet::affichageLiaisons(){

    Noeud* pNoeudEtude = m_teteNoeud;

    std::cout << "Le sommet " << m_numero << " est lier avec : \n";

    while(pNoeudEtude->GetpNext() != NULL){
        std::cout << "\tLiee avec le sommet : " << pNoeudEtude->GetNumeroPrecedent() << "\t avec un poid de : " << pNoeudEtude->Getpoid() <<"\n";
        pNoeudEtude = pNoeudEtude->GetpNext();
    }

}
