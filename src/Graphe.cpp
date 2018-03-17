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
        delete pSommet;
    }
}

 void Graphe::ajoutSommet(int numero){

    m_vecSommet.push_back(new Sommet(numero));
    m_ordreGraphe++;
 }

 void Graphe::ajoutLiaisonDeuxSommet(int numeroD, int numeroA, int poid){

     int i = 0;

     while(m_vecSommet[i]->GetNumero() != numeroD && i < m_ordreGraphe){
        i++;
     }



     if(i == m_ordreGraphe){
        std::cout << "Erreur creation Liaison : sommet Depart n est pas dans le vecteur\n\n";
     }
     else{

        m_vecSommet[i]->ajoutLiaison(numeroA, poid);
     }
 }
