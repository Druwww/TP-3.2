#include <iostream>

#include "Graphe.h"
#include "GrapheArete.h"

int main()
{
    std::cout << "Hello Correcteur\n";

    /*
    Graphe g1("sauvegarde.txt");

    g1.chargementFichier();

    for(auto elem : g1.GetvecSommet()){

        elem->affichageLiaisons();
    }

    std::cout << "\n\n";

    g1.algorithmeArbrePetitDji();
    */

    GrapheArete g2(std::string("sauvegarde2.txt"));

    g2.chargementFichier();

    g2.affichageAretes();

    return 0;
}
