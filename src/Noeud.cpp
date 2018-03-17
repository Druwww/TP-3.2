#include "Noeud.h"

Noeud::Noeud(): m_pNext(NULL)
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
