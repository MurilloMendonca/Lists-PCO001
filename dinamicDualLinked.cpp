#include<iostream>

struct No
{
    char Info;
    No * Ant;
    No * Pos;
};

void InsereLista (No*& L, char Novo)
{
    if (L == NULL)
    {
        L = new No;
        L->Info = Novo;
        L->Ant = L->Pos = NULL;
    }
    else
    {
        No* Aux = L;
        No* Ant = NULL;
        while ((Aux != NULL) && (Aux->Info < Novo))
        {
            Ant = Aux;
            Aux = Aux->Pos;
        }
        Aux = new No;
        Aux->Info = Novo;
        if (Ant == NULL)
        {
            Aux->Pos = L;
            Aux->Ant = NULL;
            L->Ant = Aux;
            L = Aux;
        }
        else
        {
            Aux->Pos = Ant->Pos;
            Aux->Ant = Ant;
            if (Ant->Pos != NULL)Aux->Pos->Ant = Aux;
            Ant->Pos = Aux;
        }
    }
}

void IniciaLista(No*&L)
{
    L=NULL;
}
void MostraLista(No* L)
{
    while (L->Pos != NULL)
    {
        printf("%c <-> ", L->Info);
        L = L->Pos;
    }
    printf("%c -> NULL\n", L->Info);
}

void Cocatena(No*&L1, No*&L2)
{
    No* aux = L1;
    while(aux->Pos!=NULL)
        aux=aux->Pos;
    aux->Pos = L2;
    L2->Ant=aux;
}

int main()
{
    No* L;
    IniciaLista(L);
    InsereLista(L,'c');
    InsereLista(L,'a');
    InsereLista(L,'b');
    MostraLista(L);
    No* L2;
    IniciaLista(L2);
    InsereLista(L2,'k');
    InsereLista(L2,'g');
    InsereLista(L2,'p');
    MostraLista(L2);
    Cocatena(L, L2);
    MostraLista(L);
}
