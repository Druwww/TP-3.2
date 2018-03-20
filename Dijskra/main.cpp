#include <iostream>

#include "Graphe.h"

int main()
{
    std::cout << "Hello Correcteur\n";


    Graphe g1("sauvegarde.txt");

    g1.chargementFichier();

    for(auto elem : g1.GetvecSommet()){

        elem->affichageLiaisons();
    }

    std::cout << "\n\n";

    g1.algorithmeArbrePetitDji();

    return 0;
}
