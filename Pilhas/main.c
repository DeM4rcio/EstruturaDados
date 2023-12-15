#include <stdio.h>


typedef struct  no
{
    int data;
    struct no *proximo;    
}No;

No* empilhar(No *topo)
{
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->data = 1;
        novo->proximo = topo;
        return novo;
    }else{
        printf("Erro ao alocar a memória");
    }return NULL;
}

No* desempilhar(No **topo)
{
    if(*topo != NULL)
    {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }else{
        printf("Não tem nó nesta pilha");
    }return NULL;
}

void ImprimirPilha(No *topo)
{
    printf("\n ----------------PILHA-----------\n");
    while (topo)
    {
        printf("&d", &topo->data);
        topo = topo->proximo;
    }
    
    printf("\n ----------------PILHA-----------\n");
    
}

int main()
{
    No *remover, *topo = NULL;
    int opcao;
    do
    {
        printf("\n0 - Sair\n1 - Empilhar \n2 - Desempilhar\n3 - Imprimir");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover)
            {
                printf("Elemento Removido");
            }else
            {
                printf("\nSem nó para remover");
            }
            break;
        case 3:
            ImprimirPilha(topo);
        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);
    
    return 0;
}