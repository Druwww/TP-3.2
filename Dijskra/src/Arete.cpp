#include "Arete.h"

Arete::Arete(): m_marque(false)
{
    //ctor
}

Arete::~Arete()
{
    //dtor
}

Arete::Arete(int sommetD, int sommetA, int poid): m_sommetD(sommetD), m_sommetA(sommetA), m_poid(poid), m_marque(false){
    //ctor
}

void Arete::affichage(){
    std::cout << "\tDepart : " << m_sommetD << "\t Arriver : " << m_sommetA << "\tPoid : " << m_poid << "\n";
}
