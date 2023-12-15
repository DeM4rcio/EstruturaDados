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
    if(topo)
    {
        novo->caracter = x;
        novo->proximo = topo ;
    }else{
        printf("A pilha não tem topo");
    }return NULL;
    
}

int indendifica_formacao(char x[])
{

}


int main()
{
    char exp[50];

    printf("\nDigite uma expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\nRetorno: %d\n",exp, indendifica_formacao(exp));

    return 0;
}