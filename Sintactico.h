#ifndef SINTACTICO_H
#define SINTACTICO_H
#include "Lexico.h"
#include <vector>
#include <stack>
#include <iostream>
#include <string>

using namespace std;


class Sintactico
{
    public:
        Sintactico(char *nom);
        bool buscar();
        bool terminal(string n);
        void agregar_pila(string n);
        string acceder(string n , string m);
        bool analizar();
        virtual ~Sintactico();
    protected:
        string tabla[25][30];
        stack<string> errores;
        Lexico lex;
        stack<string> pila;
};

#endif // SINTACTICO_H
