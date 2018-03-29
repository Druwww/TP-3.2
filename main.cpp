#include <iostream>

#include "Graphe.h"
#include "GrapheArete.h"

int main()
{
    std::cout << "Hello Correcteur\n";


    std::cout << "\n########################################################################\n\tDJISKRA\n\n";

    Graphe g1("sauvegarde.txt");

    g1.chargementFichier();

    for(auto elem : g1.GetvecSommet()){

        elem->affichageLiaisons();
    }

    std::cout << "\n\n";

    g1.algorithmeArbrePetitDji();

     std::cout << "\n########################################################################\n\tKRUSKA\n\n";

    GrapheArete g2(std::string("sauvegarde2.txt"));

    g2.chargementFichier();

    g2.trieVecteurArete();

    g2.affichageAretes();


    g2.algoKruskal();

    return 0;
}
