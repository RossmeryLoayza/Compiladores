#ifndef NODO_H
#define NODO_H

#include<string>
#include <iostream>

using namespace std;


class Nodo
{
    protected:
        int linea;
        string tk;
        string lx;
    public:
        Nodo *next;
        Nodo();
        Nodo(int l, string t, string lex);
        void print();
        string get_token();
        int get_linea();
        string get_lexema();
        virtual ~Nodo();
};

#endif // NODO_H
