#ifndef ARETE_H
#define ARETE_H

#include "../headers.h"

class Arete
{
    private:
        int m_sommetD;
        int m_sommetA;
        int m_poid;
        bool m_marque;

    public:
        Arete();
        Arete(int sommetD, int sommetA, int poid);
        virtual ~Arete();

        int GetsommetD() { return m_sommetD; }
        void SetsommetD(int val) { m_sommetD = val; }

        int GetsommetA() { return m_sommetA; }
        void SetsommetA(int val) { m_sommetA = val; }

        int Getpoid() { return m_poid; }
        void Setpoid(int val) { m_poid = val; }

        bool Getmarque() { return m_marque; }
        void Setmarque(bool val) { m_marque = val; }

        void affichage();
};

#endif // ARETE_H
