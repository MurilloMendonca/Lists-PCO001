#include<iostream>
#include<cmath>
struct No
{
    int exp;
    float coef;
    No* lig;
};
void InsereLista (No*& L, float C, int E)
{
    if (L == NULL)
    {
        L = new No;
        L->coef = C;
        L->exp=E;
        L->lig = NULL;
    }
    else
    {
        No* Ant = NULL;
        No* Aux = L;
        while ((Aux != NULL) && (Aux->exp < E))
        {
            Ant = Aux;
            Aux = Aux->lig;
        }
        Aux = new No;
        Aux->coef=C;
        Aux->exp=E;
        if (Ant == NULL)
        {
            Aux->lig = L;
            L = Aux;
        }
        else
        {
            Aux->lig = Ant->lig;
            Ant->lig = Aux;
        }
    }
}
bool RetiraLista (No*& L, int E)
{
    No* Ant = NULL;
    No* Aux = L;
    while ((Aux != NULL) && (Aux->exp != E))
    {
        Ant = Aux;
        Aux = Aux->lig;
    }
    if (Aux == NULL)return false;
    if (Aux == L)L = L->lig;
    else Ant->lig = Aux->lig;
    delete Aux;
    return true;
}
void MostraLista(No* L)
{
    while (L->lig != NULL)
    {
        printf("%f*x^%i + ", L->coef, L->exp);
        L = L->lig;
    }
    printf("%f*x^%i\n\n", L->coef, L->exp);
}
void iniciaLista(No*&L)
{
    L=NULL;
}
bool Consulta(No* L, No& N)
{
    while (L != NULL)
    {
        if(L->exp==N.exp)
        {
            N = *L;
            return true;
        }
        L = L->lig;
    }
    return false;
}
bool Altera(No*& L, No ant, No novo)
{
    RetiraLista(L, ant.exp);
    InsereLista(L, novo.coef, novo.exp);
}
No* SomaPoli(No*P1, No*P2)
{
    No aux, novo;
    No* soma;
    iniciaLista(soma);
    No* auxp;
    auxp = P1;
    while(auxp!=NULL)
    {
        InsereLista(soma, auxp->coef, auxp->exp);
        auxp = auxp->lig;
    }
    while(P2!=NULL)
    {
        aux = *P2;
        if(Consulta(soma, aux))
        {
            novo.exp= aux.exp;
            novo.coef = P2->coef + aux.coef;
            Altera(soma, aux, novo);
        }
        else InsereLista(soma, aux.coef, aux.exp);
        P2 = P2->lig;
    }
    return soma;
}

No* prodPoli(No* P1, No* P2)
{
    No aux, novo;
    No* aux1, *aux2, *prod;
    iniciaLista(prod);
    aux1=P1;
    aux2=P2;
    while(aux1!=NULL)
    {
        aux2 = P2;
        while(aux2!=NULL)
        {
            aux.exp = aux1->exp+aux2->exp;
            if(Consulta(prod, aux))
            {
                novo.exp= aux.exp;
                novo.coef =aux1->coef*aux2->coef + aux.coef;
                Altera(prod, aux, novo);
            }
            else InsereLista(prod, aux1->coef*aux2->coef, aux.exp);
            aux2 = aux2->lig;
        }
        aux1=aux1->lig;
    }
    return prod;
}

float CalculaPoli(No*P, float x)
{
    float Px = 0;
    while(P!=NULL)
    {
        Px+=pow(x,P->exp)*P->coef;
        P=P->lig;
    }
    return Px;
}
int main()
{
    No* L;
    iniciaLista(L);
    InsereLista(L, 5.341, 0);
    InsereLista(L, 3, 1);
    InsereLista(L, -2, 2);
    MostraLista(L);

    No* L2;
    iniciaLista(L2);
    InsereLista(L2, 1, 0);
    InsereLista(L2, 1, 4);
    InsereLista(L2, 1, 2);
    MostraLista(L2);

    No* soma = SomaPoli(L, L2);
    MostraLista(soma);
    MostraLista(prodPoli(L,L2));
    for(int i=0;i<10;i++)
    {
        printf("\nP(%i) = %f", i, CalculaPoli(L, i));
    }


}
