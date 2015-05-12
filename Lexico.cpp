#include "Lexico.h"

Lexico::Lexico()
{
	tokens["int"] = "TIPO_INT";
    tokens["char"] = "TIPO_CHAR";
    tokens["float"] = "TIPO_FLOAT";
    tokens["if"] = "IF";
    tokens["else"] = "ELSE";
    tokens["while"] = "WHILE";
    tokens["for"] = "FOR";
    tokens["return"] = "RETURN";
    tokens[","] = "COMA";
    tokens[";"] = "P_COMA";
    tokens["{"] = "LLAVE_A";
    tokens["}"] = "LLAVE_C";
    tokens["["] = "CORCH_A";
    tokens["]"] = "CORCH_C";
    tokens["("] = "PARENT_A";
    tokens[")"] = "PARENT_C";
    tokens["="] = "IGUAL";
    tokens["&"] = "AND_L";
    tokens["|"] = "OR_L";
    tokens["<"] = "MENOR";
    tokens[">"] = "MAYOR";
    tokens["!"] = "DIFERENTE";
    tokens["-"] = "MENOS";
    tokens["+"] = "MAS";
    tokens["*"] = "POR";
    tokens["/"] = "DIVISION";
	n_linea = 1;
	tipo = 2;
	next_t = "";
	lexema = "";
}

bool Lexico::buscar_token(string n)
{
    next_t = tokens[n];
    if (next_t.size() > 0)
    {
        return true;
    }
    next_t = "ID";
    return false;

}

bool Lexico::c_especial(char car)
{
    char tmp[18] = {',',';','{','}','[',']','(',')','=','/','*','-','+','&','|','>','<','!'};
    for (int  i = 0 ; i < 18 ; i++)
    {
        if (car == tmp[i] || c == ' ' || c == '\t' || c == '\n' )
            return false;
    }
    return true;
}

bool Lexico::es_id()
{
    if(isdigit(lexema[0]))
        return false;
    for (int i = 1 ; i < lexema.size() ; i++)
    {
        if (isdigit(lexema[i]) == 0 && isalpha(lexema[i]) == 0)
            return false;
    }
    return true;
}

bool Lexico::es_float()
{
    int cont = 0;
    for (int i = 1 ; i < lexema.size() ; i++)
    {
        if (isalpha(lexema[i]) || cont >= 2)
        {
            next_t = "ERROR";
            return false;
        }
        if (lexema[i] == '.')
            cont++;
    }
    next_t = "NUM_FLOAT";
    return true;
}

bool Lexico::es_num()
{
    for (int i = 1 ; i < lexema.size() ; i++)
    {
        if (isalpha(lexema[i]) || !isdigit(lexema[i]))
        {
            next_t = "ERROR";
            return false;
        }
    }
    next_t = "NUM";
    return true;
}

void Lexico::agregar_c()
{
    lexema = lexema + c;
}

void Lexico::siguiente_c()
{
    c = getc(entrada);
    if(c != EOF)
    {
        if( isalpha(c) )
        {
            tipo = 0;
        }
        else
        {
            if( isdigit(c) || c == '.')
                tipo = 1;
            else
            {
                if (c_especial(c))
                    tipo = 3;
                else
                    tipo = 2;
            }
        }
    }
    else
        tipo = EOF;
}

void Lexico::espacios()
{
    while (c == ' ' || c == '\t' || c == '\n')
    {
        if(c == '\n')
        {
            n_linea++;
        }
        c = getc(entrada);
    }
    if(isalpha(c))
        tipo = 0;
    if(isdigit(c))
        tipo = 1;
}

void Lexico::analizar()
{
    espacios();
    if(tipo == 0)
    {
        agregar_c();
        siguiente_c();
        while (tipo == 0 || tipo == 1 || tipo == 3)
        {
            agregar_c();
            siguiente_c();
        }
        if (buscar_token(lexema) == false)
        {
            if (es_id() == false)
            {
                next_t = "ERROR";
                errores.add(n_linea, next_t,lexema);
            }
            else
                next_t = "ID";
        }
        salida.add(n_linea, next_t,lexema);
        cout << lexema << "     " << next_t << endl;
        lexema = "";
        next_t = "";
    }
    else
    {
        if (tipo == 1)
        {
            agregar_c();
            siguiente_c();
            while (tipo == 1 || tipo == 0 || tipo == 3)
            {
                agregar_c();
                siguiente_c();
            }
            if (es_num() == true)
                salida.add(n_linea, next_t,lexema);
            else
            {
                if (es_float() == true)
                    salida.add(n_linea, next_t,lexema);
                else
                    errores.add(n_linea, next_t,lexema);
            }
            cout << lexema << "     " << next_t << endl;
            //salida.add(n_linea, next_t,lexema);
            lexema = "";
            next_t = "";
        }
        else
        {
            agregar_c();
            siguiente_c();
            if (buscar_token(lexema) == false)
                next_t = "ID";
            cout << lexema << "     " << next_t << endl;
            salida.add(n_linea, next_t,lexema);
            lexema = "";
            next_t = "";
        }
    }
}

void Lexico::analizador(char *nom)
{
    if ((entrada = fopen(nom, "r")) == NULL)
        cout << "Error, no se pudo abrir el archivo" << endl;
    else
    {
        siguiente_c();
        while (c != EOF)
        {
            analizar();
        }
    }
    salida.print();
    cout << "\n \n \t \t TABLA DE ERRORES" << endl;
    errores.print();
}

Lexico::~Lexico()
{
	fclose(entrada);
}
