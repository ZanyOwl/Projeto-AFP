#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define OCUPANTES_MAX 6
#define HISTORICO_MAX 3
#define LINHAS_MAX 5
#define COLUNAS_MAX 5

typedef struct pessoa
{
    char nome[20+1];
    int idade;
} TipoPessoa;

typedef struct reserva
{
    char tipoAlojamento; //T-tenda; C-caravana; B-Bungalow; '\0'-vazio;
    int isComEletricidade;//0 or 1
    int numeroDeOcupantes;
    TipoPessoa ocupantes[OCUPANTES_MAX];
} TipoReserva;

typedef struct historico
{
    TipoReserva reservaGuardada[HISTORICO_MAX]; //Guarda as reservas feitas. Recebe diretamente a estrutura em vez dos dados um por um, guardando assim todas as prioridade;
} TipoHistorico;

typedef struct lote
{
    TipoReserva reservaAtual; //T-tenda; C-caravana; B-Bungalow; '\0'-vazio;
    TipoHistorico historico[HISTORICO_MAX];
} TipoLote;

/*void imprimirParque(TipoLote*);*/
TipoLote reservarLote(int, int);
void consultarLote(int, int, TipoLote*);

int main()
{
    setlocale(LC_ALL, "portuguese");

    TipoLote matrizLotes[LINHAS_MAX][COLUNAS_MAX] = {};
    int linha, coluna;
    /*imprimirParque(&matrizLotes);*/

    printf("Linha: ");
    scanf("%d", &linha);
    printf("Coluna: ");
    scanf("%d", &coluna);

    matrizLotes[linha][coluna] = reservarLote(linha, coluna);
    return 0;
}

/*void imprimirParque(TipoLote *matrizLotes)
{
    for (int i = 0; i < LINHAS_MAX; i++)
    {
        printf ("%d\n", i);
        for (int j = 0; j < COLUNAS_MAX; j++)
        {
            printf("%d\t", j);
        }
    }
}*/

TipoLote reservarLote(int linha, int coluna)
{
    TipoLote matrizLote[linha][coluna];
    char alojamento;
    int eletricidade, ocupantes;

    printf("Qual o tipo de reserva /[T/C/B/]: ");
    scanf(" %c", &alojamento);
    matrizLote[linha][coluna].reservaAtual.tipoAlojamento = alojamento;

    printf("Tem eletricidade? /[0/1/]: ");
    scanf("%d", &eletricidade);
    matrizLote[linha][coluna].reservaAtual.isComEletricidade = eletricidade;

    printf("Quantos ocupantes tem?: ");
    scanf("%d", &ocupantes);
    if (ocupantes <= 0 || ocupantes > 6)
    {
        printf("ERRO! Minimo numero possível de ocupantes do lote é 1 e maximo permitido é 6");
        scanf("%d", &ocupantes);
    }
    else
    {
        matrizLote[linha][coluna].reservaAtual.numeroDeOcupantes = ocupantes;
    }

    for (int i = 0; i < ocupantes; i++)
    {
        printf("Nome do Ocupante: ");
        gets(matrizLote[linha][coluna].reservaAtual.ocupantes[i].nome);
        printf("Idade do Ocupante: ");
        scanf("%d", &matrizLote[linha][coluna].reservaAtual.ocupantes[i].idade);
    }

    return matrizLote[linha][coluna];
}

void consultarLote (int linha, int coluna, TipoLote matrizLote[][])
{
    printf("Reserva Atual - Alojamento: %c / Eletricidade: %d / Ocupantes: %d\n", matrizLote[linha][coluna].reservaAtual.tipoAlojamento,
           matrizLote[linha][coluna].reservaAtual.isComEletricidade,
           matrizLote[linha][coluna].reservaAtual.numeroDeOcupantes);
    for (int i = 0; i < HISTORICO_MAX; i++)
    {
       printf("Histórico - Reserva %d - Alojamento: %c / Eletricidade: %d / Ocupantes: %d\n", i + 1, matrizLote[linha][coluna].historico.reservaGuardada[i].tipoAlojamento,
              matrizLote[linha][coluna].historico.reservaGuardada[i].isComEletricidade,
              matrizLote[linha][coluna].historico.reservaGuardada.numeroDeOcupantes);
    }
}
