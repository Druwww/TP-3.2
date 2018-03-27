#include "GrapheArete.h"

GrapheArete::GrapheArete() : m_nbSommet(0), m_nomFichier("")
{
    //ctor
}

GrapheArete::~GrapheArete()
{
    for(auto pArete : m_vecArete){
        delete pArete;
    }
}

GrapheArete::GrapheArete(std::string nomFichier): m_nomFichier(nomFichier), m_nbSommet(0){
    //ctor
}

void GrapheArete::chargementFichier(){

    try{

    if(m_nomFichier == ""){
        throw std::string("Pas de nom de fichier");
    }

        std::ifstream fichierSauvegarde(m_nomFichier, std::ios::in);

        if(fichierSauvegarde == NULL){
            throw std::string("Echec ouverture fichier");
        }

        fichierSauvegarde >> m_nbSommet;

        fichierSauvegarde >> m_nbArete;

        int sommetD, sommetA, poid;

        for(int i = 0; i < m_nbArete; i++){
            fichierSauvegarde >> sommetD;
            fichierSauvegarde >> sommetA;
            fichierSauvegarde >> poid;

            m_vecArete.push_back(new Arete(sommetD, sommetA, poid));
        }

        fichierSauvegarde.close();
    }
    catch(std::string nameError){
        std::cout << "\n\nEROR\n\n" << nameError << "\n";
    }
    catch(...){
        std::cout << "\n\nUnexpeted error ... sorry bro \n";
    }

}


void GrapheArete::affichageAretes(){

    for(auto elem : m_vecArete){
        elem->affichage();
    }
}

void GrapheArete::affichageAretesMarque(){

    for(auto elem : m_vecArete){
        if(elem->Getmarque()){
            elem->affichage();
        }
    }
}

void GrapheArete::trieVecteurArete(){

    Arete* pTempo;

    for(int i = 0; i < m_nbArete; i++){

        for(int j = 0; j < m_nbArete - 1; j++){
            if(m_vecArete[j]->Getpoid() > m_vecArete[j+1]->Getpoid()){
                pTempo = m_vecArete[j];
                m_vecArete[j] = m_vecArete[j+1];
                m_vecArete[j+1] = pTempo;
            }
        }
    }
}


void GrapheArete::resetMarque(){

    for(auto elem : m_vecArete){
        elem->Setmarque(false);
    }
}

void GrapheArete::algoKruskal(){


    std::cout << "\n\n\nDEBUT KRUSKAL\n\n";

    trieVecteurArete();



    int nbAreteSelec = 0;

    int cumulePoid = 0;

    std::vector<int> vecCycle;

    for(int i = 0; i < m_nbSommet; i++){
        vecCycle.push_back(i);

    }


    for(int i = 0; i < m_nbArete; i++){

        if(vecCycle[m_vecArete[i]->GetsommetD()] != vecCycle[m_vecArete[i]->GetsommetA()]){

            m_vecArete[i]->Setmarque(true);
            nbAreteSelec++;
            cumulePoid += m_vecArete[i]->Getpoid();

            int numeroChangement = vecCycle[m_vecArete[i]->GetsommetA()];

            for(int j = 0; j < m_nbSommet; j++){
                if(vecCycle[j] == numeroChangement){
                    vecCycle[j] = m_vecArete[i]->GetsommetD();
                }
            }

        }
        if(nbAreteSelec == m_nbSommet - 1){
            break;
        }
    }

    affichageAretesMarque();

    std::cout << "\n\n\tPoid de l arbre : " << cumulePoid << "\n\n";

    resetMarque();
}
