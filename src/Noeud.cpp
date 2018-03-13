#include "Noeud.h"

Noeud::Noeud()
{
    //ctor
}

Noeud::Noeud(int numeroPrecedent, int poid): m_pNext(NULL) ,m_numeroPrecedent(numeroPrecedent), m_poid(poid){
    //ctor
}

Noeud::~Noeud()
{
    //dtor
}
