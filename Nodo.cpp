#include "Nodo.h"

Nodo::Nodo()
{
    linea = 0;
    tk = "";
    lx = "";
    next = NULL;
}

Nodo::Nodo(int l, string t, string lex)
{
    linea = l;
    tk = t;
    lx = lex;
    next = NULL;
}

string Nodo::get_token()
{
    return tk;
}

int Nodo::get_linea()
{
    return linea;
}

string Nodo::get_lexema()
{
    return lx;
}

void Nodo::print()
{
    cout << "Token: " << tk << ", Lexema: " << lx << ", Nro. linea: " << linea << endl;
}

Nodo::~Nodo()
{
    //dtor
}
