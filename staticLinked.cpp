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

No ultimo(ListaEstaticaEncadeada L)
{
    int prox = L.Com, cont=0;
    while(true)
    {
        if(L.Dados[prox].Lig==-1) return L.Dados[prox];
        prox=L.Dados[prox].Lig;
    }
}

void inverte(ListaEstaticaEncadeada &L){
    int atual, prox=L.Com, ant=-1;
    while(prox!=-1)
    {
        atual = prox;
        prox = L.Dados[atual].Lig;
        L.Dados[atual].Lig = ant;
        ant = atual;
    }
    L.Com=ant;
}

bool compara(ListaEstaticaEncadeada L1, ListaEstaticaEncadeada L2)
{
    if(contaNos(L1)!=contaNos(L2))
        return false;
    ListaEstaticaEncadeada L2inv = L2; inverte(L2inv);
    int prox1=L1.Com, prox2 = L2.Com, prox2inv = L2inv.Com;
    while(prox1!=-1)
    {
        if((L1.Dados[prox1].Info!=L2.Dados[prox2].Info)&&(L1.Dados[prox1].Info!=L2inv.Dados[prox2inv].Info))
            return false;
        prox1 = L1.Dados[prox1].Lig;
        prox2 = L2.Dados[prox2].Lig;
        prox2inv=L2inv.Dados[prox2inv].Lig;
    }
    return true;
}
int main(){
    ListaEstaticaEncadeada L;
    IniciaLista(L);
    InsereLista(L,'F');InsereLista(L,'A');InsereLista(L,'B');
    printf("A Lista tem %i elementos.", contaNos(L));
    printf("\nO ultimo elemento eh: %c", ultimo(L).Info);
    mostraLista(L);
    ListaEstaticaEncadeada L2=L;
    inverte(L2);
    printf("\n\nLista Invertida:");
    mostraLista(L2);

    if(compara(L,L2)) printf("\n\nAs duas listas tem o mesmo conteudo");
    else printf("\nAs listas nao tem o mesmo conteudo");
    return 0;
}
