#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *direita,*esquerda;
    
}NoArv;

NoArv* InserirNo(NoArv *raiz, int num)
{
    if(raiz == NULL)
    {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->dado = num;
        aux->direita = NULL;
        aux->esquerda = NULL;
        return aux;
    }else{
        if(num < raiz->dado)
            raiz->esquerda = InserirNo(raiz->esquerda, num);
        else
            raiz->direita = InserirNo(raiz->direita, num);
    }
}

void Imprimir1(NoArv *raiz)
{
    if(raiz)
    {
        printf("%d", raiz->dado);
        Imprimir1(raiz->esquerda);
        Imprimir1(raiz->direita);
    }
}

void Imprimir2(NoArv *raiz)
{
    if(raiz)
    {
        Imprimir1(raiz->esquerda);
        printf("%d", raiz->dado);
        Imprimir1(raiz->direita);
    }
}

NoArv* Busca1(NoArv *raiz, int num)
{
    if(raiz)
    {
        if(num == raiz->dado)
            return raiz;
        else if(num < raiz->dado)
            return Busca1(raiz->esquerda, num);
        else
            return Busca1(raiz->direita, num);
    }return NULL;
}

int main()
{
    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n1-Inserir, 2-Imprimir,3-ImprimirOrdenado\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nInsira o numero desejado:\n");
            scanf("%d",&valor);
            raiz = InserirNo(raiz, valor);
            printf("Deu bom");
            break;
        case 2:
            Imprimir1(raiz);
            break;
        case 3:
            Imprimir2(raiz);
            break;
        case 4:
            printf("\nInsira o numero desejado:\n");
            scanf("%d",&valor);
            busca = Busca1(raiz, valor);
            if(busca)
                printf("Encontrado");
            else
                printf("Nao encotrado");
            break;
        default:
            if(opcao != 0)
            printf("Opcao invalida");
        }
    }while (opcao != 0);

    return 0;
}