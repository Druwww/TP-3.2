#include "Graphe.h"

Graphe::Graphe(): m_nomFichier(""), m_ordreGraphe(0)
{
    //ctor
}

Graphe::Graphe(std::string nom): m_nomFichier(nom), m_ordreGraphe(0){
    //ctor
}

Graphe::~Graphe()
{

    for(auto pSommet : m_vecSommet){
        delete pSommet;
    }
}

 void Graphe::ajoutSommet(int numero){

    m_vecSommet.push_back(new Sommet(numero));
    m_ordreGraphe++;
 }

 void Graphe::ajoutLiaisonDeuxSommet(int numeroD, int numeroA, int poid){

     if(numeroD >= m_ordreGraphe || numeroA >= m_ordreGraphe){
        std::cout << "Erreur creation Liaison : sommet Depart n est pas dans le vecteur\n\n";
     }
     else{

        m_vecSommet[numeroD]->ajoutLiaison(numeroA, poid);
     }
 }


 void Graphe::chargementFichier(){



     if(m_nomFichier == ""){
        std::cout << "Pas de nom de fichier a charger dsl \n";
     }
     else{

        std::ifstream fichierSauvegarde(m_nomFichier, std::ios::in);

        if(!fichierSauvegarde == NULL){

            int ordre;
            fichierSauvegarde >> ordre;

            for(int i = 0; i < ordre; i++){
                ajoutSommet(i);
            }

            int poid;



            for(int x = 0; x < m_ordreGraphe; x++){
                for(int y = 0; y < m_ordreGraphe; y++){
                    fichierSauvegarde >> poid;
                    if(poid != 0){
                        ajoutLiaisonDeuxSommet(x,y,poid);
                    }
                }
            }
            fichierSauvegarde.close();
        }
        else{
            std::cout << "Erreur ouvertue fichier sauvegarde\n";
        }
     }
 }


 bool Graphe::verificationMarquageGraphe(){

    for(auto elem : m_vecSommet){
        if(!elem->GetMarque()){
            return true;
        }
    }

    return false;
 }


 void Graphe::algorithmeArbrePetitDji(){

    std::cout << "\n\nDEBUT\n\n";

    m_vecSommet[0]->SetPoidCumule(0);

    int sommetEtude = 0;
    int cumuleArbre = 0;

    for(int j = 0; j < m_ordreGraphe; j++){
        m_vecSommet[sommetEtude]->SetMarque(true);

        if(sommetEtude != 0){
            std::cout << "Liaison : " << sommetEtude << " & " << m_vecSommet[sommetEtude]->GetAntecedantGraphe() << "\t\t pour poid cumul : " << m_vecSommet[sommetEtude]->GetPoidCumule() << "\n";
            cumuleArbre += m_vecSommet[sommetEtude]->poidLiaisonAvec(m_vecSommet[sommetEtude]->GetAntecedantGraphe());
        }

        Noeud* pNoeudEtude = m_vecSommet[sommetEtude]->GetteteNoeud();

        for(int i = 0; i < m_vecSommet[sommetEtude]->Getpuissance(); i++){

            pNoeudEtude = pNoeudEtude->GetpNext();

            if(m_vecSommet[pNoeudEtude->GetNumeroPrecedent()]->GetPoidCumule() > m_vecSommet[sommetEtude]->GetPoidCumule() + pNoeudEtude->Getpoid() && !m_vecSommet[pNoeudEtude->GetNumeroPrecedent()]->GetMarque()){
                m_vecSommet[pNoeudEtude->GetNumeroPrecedent()]->SetPoidCumule(m_vecSommet[sommetEtude]->GetPoidCumule() + pNoeudEtude->Getpoid());
                m_vecSommet[pNoeudEtude->GetNumeroPrecedent()]->SetAntecedantGraphe(sommetEtude);
            }
        }


        int cumuleBas = INFINI_MAX;

        for(int i = 0; i < m_ordreGraphe; i++){
            if(!m_vecSommet[i]->GetMarque() && m_vecSommet[i]->GetPoidCumule() < cumuleBas){
                sommetEtude = i;
                cumuleBas = m_vecSommet[i]->GetPoidCumule();
            }
        }

    }

    std::cout << "\n Poid total de l arbre : " << cumuleArbre;

    std::cout << "\n\nFIN\n\n";
 }
