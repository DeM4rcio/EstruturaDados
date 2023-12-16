#include <stdio.h>


typedef struct no{
    char caracter;
    struct no *proximo;
}No;

No* desempilhar(No **topo)
{
    if(*topo != NULL)
    {
        No *remover = *topo;
        topo = remover->proximo;
        return topo;
    }else{
        printf("Nao tem nó nesta pilha");
    }return NULL;
}

No* empilhar(No *topo, char x)
{
    No *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->caracter = x;
        novo->proximo = topo ;
        return novo;
    }else{
        printf("A pilha nao tem topo");
    }return NULL;
    
}

int indendifica_formacao(char x[])
{   
    No *topo = NULL;
    
    
    int tamanho = sizeof(x) / sizeof(x[0]);
    for(int i = 0; i <= tamanho;i++)
    {
        printf("%c", x[i]);
        topo = empilhar(topo,x[i]);
    }
    ImprimirPilha(topo);
    return 0;
}

void ImprimirPilha(No *topo)
{
    printf("\n ----------------PILHA-----------\n");
    while (topo)
    {
        printf("%c", &topo->caracter);
        topo = topo->proximo;
    }
    printf("\n ----------------PILHA-----------\n");
}


int main()
{
    char exp[50];
    printf("\nDigite uma expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n",exp, indendifica_formacao(exp));

    

    return 0;
}