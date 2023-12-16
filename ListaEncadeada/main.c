#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
}No;

void InserirInicio(No **lista,int num)
{
    No *novo = malloc(sizeof(No));
    if(novo)
    {
        novo->dado = num;
        novo->proximo = *lista;
        *lista = novo;
    }else
        printf("Erro na alocação");
}

void InserirFim(No **lista, int num)
{
    No *aux,*novo = malloc(sizeof(No));
    if(novo)
    {
        novo->dado = num;
        novo->proximo = NULL;
        if(*lista ==NULL)
            *lista = novo;
        else{
            aux = *lista;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }else
        printf("Erro na alocação");
}

void InserirMeio(No **lista, int num, int ant)
{
    No *aux,*novo = malloc(sizeof(No));
    if(novo)
    {
        novo->dado = num;
        if(*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
        }else
        {
            aux = *lista;
            while (aux->dado != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;    
        }
    }else
        printf("Erro na alocação");
}

void Imprimir(No *no)
{
    printf("\nLista: \n");
    while (no)
    {
        printf("%d", no->dado);
        no = no->proximo;
    }
    printf("\n\n");
}

No* Remover(No **lista, int num)
{
    No *aux,*remover = NULL;
    if(*lista)
    {
        if((*lista)->dado == num)
        {
            remover = *lista;
            *lista = remover->proximo;
        }else
        {
            aux = *lista;
            while(aux->proximo && aux->proximo->dado != num)
                aux = aux->proximo;
            if(aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
        
    }
    return remover;
}

int main()
{
    int opcao, valor, valorRef;
    No *remover, *lista = NULL;
    do{
    printf("\n0 - Sair\n1 - InserirF \n2 - InserirI\n3 - InserirM\n4 - Imprimir");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
        {
        case 1:
            printf("\nNumero: \n");
            scanf("%d", &valor);
            InserirFim(&lista, valor);
            break;
        case 2:
            printf("\nNumero: \n");
            scanf("%d", &valor);
            InserirInicio(&lista, valor);
            break;
        case 3:
            printf("\nNumero: \n");
            scanf("%d", &valor);
            printf("\nNumero ref: \n");
            scanf("%d", &valorRef);
            InserirMeio(&lista, valor, valorRef);
        case 4:
            Imprimir(lista);
            break;
        case 5:
            printf("\nNumero a ser removido: \n");
            scanf("%d", &valor);
            remover = Remover(&lista, valor);
            if(remove)
            {
                printf("removido");
                free(remover);
            }
            break;
        default:
            if(opcao != 0){
                printf("Opção inválida\n");    
            }
        }

    } while (opcao != 0);
    return 0;
}