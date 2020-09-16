#include<iostream>
struct No
{
    char Info;
    No * Lig;
};

void InsereLista (No*& L, char Novo)
{
    if (L == NULL)
    {
        L = new No;
        L->Info = Novo;
        L->Lig = NULL;
    }
    else
    {
        No* Ant = NULL;
        No* Aux = L;
        while ((Aux != NULL) && (Aux->Info < Novo))
        {
            Ant = Aux;
            Aux = Aux->Lig;
        }
        Aux = new No;
        Aux->Info = Novo;
        if (Ant == NULL)
        {
            Aux->Lig = L;
            L = Aux;
        }
        else
        {
            Aux->Lig = Ant->Lig;
            Ant->Lig = Aux;
        }
    }
}

bool RetiraLista (No*& L, char N)
{
    No* Ant = NULL;
    No* Aux = L;
    while ((Aux != NULL) && (Aux->Info != N))
    {
        Ant = Aux;
        Aux = Aux->Lig;
    }
    if (Aux == NULL)return false;
    if (Aux == L)L = L->Lig;
    else Ant->Lig = Aux->Lig;
    delete Aux;
    return true;
}
void MostraLista(No* L)
{
    while (L != NULL)
    {
        printf("%c -> ", L->Info);
        L = L->Lig;
    }
    printf("NULL\n");
}

void IniciaLista(No*&L)
{
    L=NULL;
}
int ContaNosItera(No*L)
{
    int cont =0;
    while (L != NULL)
    {
        cont++;
        L = L->Lig;
    }
    return cont;
}

int ContaNosRec(No* L)
{
    return(L==NULL)?(0):(ContaNosRec(L->Lig)+1);
}

No* Ultimo(No*L)
{
    return(L->Lig==NULL)?(L):(Ultimo(L->Lig));
}

bool Consulta(No* L, No& N)
{
    while (L != NULL)
    {
        if(L->Info==N.Info)
        {
            N = *L;
            return true;
        }
        L = L->Lig;
    }
    return false;
}

bool Altera(No*& L, char ant, char novo)
{
    No* Ant = NULL;
    No* Aux = L;
    while ((Aux != NULL) && (Aux->Info != ant))
    {
        Ant = Aux;
        Aux = Aux->Lig;
    }
    if (Aux == NULL)return false;
    if (Aux == L) L = L->Lig;
    else Ant->Lig = Aux->Lig;
    Aux->Info= novo;
    Aux->Lig=NULL;
    if (L == NULL)
    {
        L = Aux;
    }
    else
    {
        No* Ant = NULL;
        No* Aux2 = L;
        while ((Aux2 != NULL) && (Aux2->Info < novo))
        {
            Ant = Aux2;
            Aux2 = Aux2->Lig;
        }
        if (Ant == NULL)
        {
            Aux->Lig = L;
            L = Aux;
        }
        else
        {
            Aux->Lig = Ant->Lig;
            Ant->Lig = Aux;
        }
    }
    return true;

}
void Cocatena(No*&L1, No*&L2)
{
    No* aux = L1;
    while(aux->Lig!=NULL)
        aux=aux->Lig;
    aux->Lig = L2;
}
void inverte(No*&L){
    No* atual = L, *prox=NULL, *ant=NULL;
    while(atual!=NULL)
    {
        prox = atual->Lig;
        atual->Lig=ant;
        ant = atual;
        atual = prox;
    }
    L=ant;
}
int main ()
{
    No* L;
    IniciaLista(L);
    InsereLista(L,'c');
    InsereLista(L,'a');
    InsereLista(L,'b');
    MostraLista(L);
    inverte(L);
    MostraLista(L);
    return 0;
}
