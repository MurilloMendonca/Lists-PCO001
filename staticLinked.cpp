#include <iostream>

using namespace std;

#define TAM 10
struct No
{
    char Info;
    int Lig;
};

struct ListaEstaticaEncadeada
{
    int Com;
    int Dispo;
    No Dados[TAM];
};

void IniciaLista (ListaEstaticaEncadeada& L)
{
    for (int i=0; i<TAM; i++)
        L.Dados[i].Lig = i+1;
    L.Dados[TAM-1].Lig = -1;
    L.Dispo = 0;
    L.Com = -1;
}
bool InsereLista (ListaEstaticaEncadeada& L, char Novo)
{
    if (L.Dispo == -1)return false;
    else
    {
        if (L.Com == -1)
        {
            L.Com = L.Dispo;
            L.Dispo = L.Dados[L.Dispo].Lig;
            L.Dados[L.Com].Info = Novo;
            L.Dados[L.Com].Lig = -1;
        }
        else
        {
            int Ant = -1;
            int Aux = L.Com;
            while ((Aux != -1) && (L.Dados[Aux].Info < Novo))
            {
                Ant = Aux;
                Aux = L.Dados[Aux].Lig;
            }
            Aux = L.Dispo;
            L.Dispo = L.Dados[L.Dispo].Lig;
            L.Dados[Aux].Info = Novo;
            if (Ant == -1)
            {
                L.Dados[Aux].Lig = L.Com;
                L.Com = Aux;
            }
            else
            {
                L.Dados[Aux].Lig = L.Dados[Ant].Lig;
                L.Dados[Ant].Lig = Aux;
            }
        }
        return true;
    }
}

bool RetiraLista (ListaEstaticaEncadeada& L, char Novo)
{
    int Ant = -1;
    int Aux = L.Com;
    while ((Aux != -1) && (L.Dados[Aux].Info != Novo))
    {
        Ant = Aux;
        Aux = L.Dados[Aux].Lig;
    }
    if (Aux == -1)return false;
    if (Aux == L.Com)L.Com = L.Dados[L.Com].Lig;
    else L.Dados[Ant].Lig = L.Dados[Aux].Lig;
    L.Dados[Aux].Lig = L.Dispo;
    L.Dispo = Aux;
    return true;
}

void mostraLista(ListaEstaticaEncadeada L){
    int prox = L.Com;
    while(prox!=-1)
    {
        printf("\nL(%i) = %c ; -> %i",prox, L.Dados[prox].Info, L.Dados[prox].Lig);
        prox=L.Dados[prox].Lig;
    }
}

int contaNos(ListaEstaticaEncadeada L){
    int prox = L.Com, cont=0;
    while(prox!=-1)
    {
        cont++;
        prox=L.Dados[prox].Lig;
    }
    return cont;
}

int main(){
    ListaEstaticaEncadeada L;
    IniciaLista(L);
    InsereLista(L,'F');InsereLista(L,'A');InsereLista(L,'B');
    printf("\nA Lista tem %i elementos.", contaNos(L));
    mostraLista(L);
    return 0;
}
