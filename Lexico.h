#ifndef LEXICO_H
#define LEXICO_H

#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string>
#include <map>
#include <fstream>
#include "List.h"

#define TAM_BUFFER 100

using namespace std;

class Lexico
{
    protected:
        char *nombreFichero;
        FILE* entrada;
        map<string,string> tokens;
        int n_linea;
        string next_t;
        int tipo; //letra = 0 , numero = 1 , otros = 2
        char c;
        string lexema;

    public:
        List salida;
        List errores;
        Lexico();
        bool buscar_token(string n);
        bool c_especial(char car);
        bool es_id();
        bool es_float();
        bool es_num();
        void agregar_c();
        void siguiente_c();
        void espacios();
        void analizar();
        void analizador(char *nom);
        virtual ~Lexico();
};

#endif // LEXICO_H
