#include <iostream>

using namespace std;

#define TAM 10
struct No
{
    char Chave;
    int Valor;
};
struct ListaSequencial
{
    No Dados[TAM];
    int Fim;
};

bool InsereListaSeq (ListaSequencial &L, No Novo)
{
    if (L.Fim == TAM - 1)
        return false;
    int i = 0, p;
    while ((i <= L.Fim) && (L.Dados[i].Chave < Novo.Chave))
        i++;
    p = i;
    i = L.Fim;
    while (i > p-1)
    {
        L.Dados[i+1] = L.Dados[i];
        i--;
    }
    L.Dados[p] = Novo;
    L.Fim++;
    return true;
}

bool RetiraListaSeq (ListaSequencial& L, No& N)
{
    int i = 0;
    while ((i <= L.Fim) && (L.Dados[i].Chave != N.Chave))
        i++;
    if (i > L.Fim)
        return false;
    N = L.Dados[i];
    while (i < L.Fim)
    {
        L.Dados[i] = L.Dados[i+1];
        i++;
    }
    L.Fim--;
    return true;
}
void iniciaLista(ListaSequencial& L)
{
    L.Fim=-1;
}
bool buscaBin(ListaSequencial L, char chave)
{
    if(L.Fim<0)
        return false;
    int inicio=0, fim=L.Fim, m;
    while(true){
        m = (inicio+fim)/2;
        if(inicio==fim && L.Dados[m].Chave!=chave)
            return false;
        if(chave>L.Dados[m].Chave)
            inicio=m+1;
        else if(chave<L.Dados[m].Chave)
            fim = m;
        else
            return true;
    }
}

bool buscaBin(ListaSequencial L, char chave, int& pos)
{
    if(L.Fim<0)
        return false;
    int inicio=0, fim=L.Fim, m;
    while(true){
        m = (inicio+fim)/2;
        if(inicio==fim && L.Dados[m].Chave!=chave)
            return false;
        if(chave>L.Dados[m].Chave)
            inicio=m+1;
        else if(chave<L.Dados[m].Chave)
            fim = m;
        else{
            pos = m;
            return true;
        }
    }
}


void mostraLista(ListaSequencial L)
{
    for(int i=0;i<=L.Fim;i++)
        printf("\nL(%i) = %i ; %c", i, L.Dados[i].Valor, L.Dados[i].Chave);
}

bool alteraNo(ListaSequencial& L, No& N){
    int pos;
    if(!buscaBin(L,N.Chave, pos))
        return false;
    int aux = N.Valor;
    N= L.Dados[pos];
    L.Dados[pos].Valor = aux;
    return true;

}
int consultaNo(ListaSequencial L, char chave){
    int pos;
    if(!buscaBin(L,chave, pos))
        return -1;
    return L.Dados[pos].Valor;
}
int main()
{
    ListaSequencial L;
    No no1, no2, no3;
    no1.Chave='F';no1.Valor=1;
    no2.Chave='A';no2.Valor=2;
    no3.Chave='B';no3.Valor=3;
    iniciaLista(L);
    InsereListaSeq(L,no1);
    InsereListaSeq(L,no2);
    InsereListaSeq(L,no3);
    mostraLista(L);
    if(buscaBin(L,'F'))
        printf("\nAchei F!!");
    else
        printf("\nNao achei F");
        no1.Valor=7;
    if(alteraNo(L, no1))
        printf("\nL(%c) foi alterado de %i para %i", no1.Chave, no1.Valor ,consultaNo(L, no1.Chave) );
    return 0;
}
