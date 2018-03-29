#ifndef NOEUD_H
#define NOEUD_H

#include "../headers.h"

class Noeud
{
    private:
        Noeud* m_pNext;
        int m_numeroPrecedent;
        int m_poid;


    public:

        Noeud();
        Noeud(int numeroPrecedent, int poid);
        virtual ~Noeud();

        Noeud* GetpNext() { return m_pNext; }
        void SetpNext(Noeud* val) { m_pNext = val; }

        int GetNumeroPrecedent() { return m_numeroPrecedent; }
        void SetNumeroPrecedent(int val) { m_numeroPrecedent = val; }

        int Getpoid() { return m_poid; }
        void Setpoid(int val) { m_poid = val; }


};

#endif // NOEUD_H
