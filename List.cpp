#include "List.h"

List::List()
{
    head = NULL;
}

void List::add(int l , string t , string lex)
{
    if (head == NULL)
    {
        head = new Nodo(l,t,lex);
        head->next = NULL;
    }
    else
    {
        Nodo *tmp = head;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = new Nodo(l,t,lex);
    }
}

void List::print()
{
    Nodo *tmp = head;
    if (tmp)
    {
        while (tmp->next)
        {
            tmp->print();
            tmp = tmp->next;
        }
        tmp->print();
    }
}

List::~List()
{
    //dtor
}
