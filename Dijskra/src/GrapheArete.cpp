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

    //Creation et initialisation du tableau de liaison pour l algo
    std::vector<int> vecCycle;
    for(int i = 0; i < m_nbSommet; i++){
        vecCycle.push_back(i);
    }

    //On parcour toutes les aretes
    for(int i = 0; i < m_nbArete; i++){

        //Si dans une arete, le sommet de depart et d arriver n ont pas le meme numero de liaison : ne vont pas creer de cycle
        if(vecCycle[m_vecArete[i]->GetsommetD()] != vecCycle[m_vecArete[i]->GetsommetA()]){

            //On marque, affiche, augmente le nombre d arrete selectionee
            m_vecArete[i]->Setmarque(true);
            nbAreteSelec++;
            cumulePoid += m_vecArete[i]->Getpoid();

            //On prend le numero de liaison du sommet d arriver : c est celui qu on va remplacer dans le tableau de liaison
            int numeroChangement = vecCycle[m_vecArete[i]->GetsommetA()];

            //On parcour tout le tableau de liaison
            for(int j = 0; j < m_nbSommet; j++){
                //Si le numero de liaison correspond au numero a changer
                if(vecCycle[j] == numeroChangement){
                    //On le remplace par le numero de liaison du sommet de depart
                    vecCycle[j] = vecCycle[m_vecArete[i]->GetsommetD()];
                }
            }
        }

        //Si on a notre nombre d arete correspondant
        if(nbAreteSelec == m_nbSommet - 1){
            //on sort de la boucle for
            break;
        }
    }

    //on affiche nos aretes marque (notre sous arbre)
    affichageAretesMarque();

    std::cout << "\n\n\tPoid de l arbre : " << cumulePoid << "\n\n";

    resetMarque();
}
