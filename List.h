#ifndef LIST_H
#define LIST_H

#include "Nodo.h"

class List
{
    public:
        Nodo *head;
        List();
        void add(int l , string t , string lex);
        void print();
        virtual ~List();
};

#endif // LIST_H
