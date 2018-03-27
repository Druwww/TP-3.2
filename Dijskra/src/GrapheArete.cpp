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
