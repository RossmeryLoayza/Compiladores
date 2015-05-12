#include "Sintactico.h"

Sintactico::Sintactico(char *nom)
{
    lex.analizador(nom);
    for(int i = 0 ; i < 25 ; i++)
    {
        for(int j = 0 ; j < 31 ; j++)
        {
            tabla[i][j] = "";
        }
    }
    char c;
    int k = 65;
    for (int i = 1 ; i < 25 ; i++)
    {
        c = k;
        tabla[i][0] = tabla[i][0] + c;
        k++;
    }
    tabla[2][1] = "TIPO_INT ID C";
    tabla[2][35] = "NULL";
    tabla[3][3] = "P_COMA B";
    tabla[3][6] = "CORCH_A NUM CORCH_C P_COMA B";
    tabla[4][8] = "PARENT_A D PARENT_C LLAVE_A F LLAVE_C";
    tabla[4][1] = "TIPO_INT ID E";
    tabla[5][13] = "COMA D";
    tabla[5][14] = "IGUAL NUM";
    tabla[6][1] = "G F";
    tabla[6][16] = "I";
    tabla[6][17] = "I";
    tabla[6][18] = "I";
    tabla[7][1] = "TIPO_INT ID H";
    tabla[8][3] = "P_COMA G";
    tabla[8][4] = "CORCH_A NUM CORCH_C P_COMA G";
    tabla[8][14] = "IGUAL NUM P_COMA G";
    tabla[9][16] = "I";
    tabla[9][18] = "I";
    tabla[9][15] = "I";
    tabla[10][17] = "IF PARENT_A N PARENT_C LLAVE_A F LLAVE_C K";
}

bool Sintactico::terminal(string n)
{
    if(n.size() > 1)
        return false;
    return true;
}

void Sintactico::agregar_pila(string n)
{
    string tmp = "";
    for(int i = 0 ; i < n.size() ; i++)
    {
        while (n[i] != ' ')
        {
            tmp = tmp + n[i];
        }
        pila.push(tmp);
        tmp = "";
    }
}

string Sintactico::acceder(string n , string m)
{
    int i;
    int j;
    for(int k = 0 ; i < 25 ; i++)
    {
        if (tabla[i][0] == n)
            i = k;
    }
    for(int k = 0 ; i < 30 ; i++)
    {
        if (tabla[i][0] == m)
            j = k;
    }
    return tabla[i][j];
}

bool Sintactico::analizar()
{
    string t;
    Nodo *tmp = (lex.salida).head;
    agregar_pila("A");
    while(tmp)
    {
        if(terminal(pila.top()))
        {
            if(t == tmp->get_token())
            {
                pila.pop();
                tmp = tmp->next;
            }
            else
            {
                string l = tmp->get_lexema();
                int n = tmp->get_linea();
                char k[3];
                itoa(n,k,10);
                string m = "Error token no esperado " + l + " en linea ";
                m.append(k);
                errores.push(m);
            }
        }
        else
        {
            string k = acceder(pila.top(), tmp->get_token());
            pila.pop();
            agregar_pila(k);
        }
    }
    if(!pila.empty())
        return false;
    return true;
}

Sintactico::~Sintactico()
{
    //dtor
}

/*tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";
    tabla[][] = "";*/
