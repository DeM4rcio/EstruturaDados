#include <stdio.h>

typedef struct no
{
    int data;
    struct no *proximo;
}No;

void enfilerar(No **fila, int num)
{
    No *aux,*novo = malloc(sizeof(No));
    if(novo)
    {
        novo->proximo = NULL; // Final de fila
        novo->data = num;
        if(*fila == NULL)
        {
            *fila = novo;
        }else
        {
            aux = *fila;
            while(aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }else{
        printf("Erro na alocacao");
    }
}

No* desenfilerar(No **fila)
{
    No *remover = NULL;
    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }else
        printf("Fila vazia");
    return remover;
}

void ImprimirFila(No *fila)
{
    printf("\t-------FILA------\n\t");
    while (fila)
    {
        printf("%d", fila->data);
        fila = fila->proximo;
    }
    
    printf("\n------ FIM FILA ----- \n");
}
int main()
{
    int opcao, valor;
    No *r,*fila = NULL;
    do{
        printf("\n------CENTRAL-------\n");
        printf("\n0-Sair, 1-Enfilerar, 2-Desenfilerar, 3-Imprimir\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nInsira um numero\n");
            scanf("%d",&valor);
            enfilerar(&fila, valor);
            break;
        case 2:
            printf("\nRemovendo\n");
            r=desenfilerar(&fila);
            if(r)
                printf("Removido com sucesso");
        case 3:
            ImprimirFila(fila);
        default:
            if(opcao !=0)
                printf("opcao invalida");
        }
    }while (opcao !=0);
    
    return 0;
}