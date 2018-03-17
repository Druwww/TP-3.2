#include <iostream>

#include "Graphe.h"

int main()
{
    std::cout << "Hello Correcteur\n";


    Graphe g1("lol");

    g1.ajoutSommet(1);
    g1.ajoutSommet(2);

    g1.ajoutLiaisonDeuxSommet(1,2,3);

    return 0;
}
