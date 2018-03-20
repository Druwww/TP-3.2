#include "Sommet.h"

Sommet::Sommet(): m_teteNoeud(NULL), m_puissance(0), m_poidCumule(INFINI_MAX), m_marque(false)
{
    m_teteNoeud = new Noeud();
}

Sommet::Sommet(int numero): m_numero(numero), m_teteNoeud(NULL), m_puissance(0),m_poidCumule(INFINI_MAX), m_marque(false){

    m_teteNoeud = new Noeud();
}

Sommet::~Sommet()
{
    /*
    Noeud* pNoeud = m_teteNoeud;
    Noeud* pNoeudTemp;

    for(int i = 0; i < m_puissance; i++){
        pNoeudTemp = pNoeud;
        delete pNoeud;
        pNoeud = pNoeudTemp->GetpNext();
        std::cout << "\n\nBanane\n\n";
    }
    */
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

    if(m_teteNoeud == NULL){
        m_teteNoeud->SetpNext(new Noeud(sommetA, poid));
    }
    else{
        while(pNoeudEtude->GetpNext() != NULL){
            pNoeudEtude = pNoeudEtude->GetpNext();
        }
        pNoeudEtude->SetpNext(new Noeud(sommetA, poid));
    }

    m_puissance++;

}


int Sommet::poidLiaisonAvec(int sommetD){

    Noeud* pNoeudEtude = m_teteNoeud;

    while(pNoeudEtude->GetpNext() != NULL){
        pNoeudEtude = pNoeudEtude->GetpNext();
        if(pNoeudEtude->GetNumeroPrecedent() == sommetD){
            return pNoeudEtude->Getpoid();
        }
    }
    return INFINI_MAX;
}

void Sommet::affichageLiaisons(){

    Noeud* pNoeudEtude = m_teteNoeud;

    std::cout << "Le sommet " << m_numero << " est lier avec : \n";

    while(pNoeudEtude->GetpNext() != NULL){
        pNoeudEtude = pNoeudEtude->GetpNext();
        std::cout << "\tLiee avec le sommet : " << pNoeudEtude->GetNumeroPrecedent() << "\t avec un poid de : " << pNoeudEtude->Getpoid() <<"\n";
    }
}
