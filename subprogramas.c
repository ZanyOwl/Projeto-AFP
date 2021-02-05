#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "estruturas.h"
#define LINHAS_MAX 5
#define COLUNAS_MAX 5

void imprimirParque(TipoLote matriz[][COLUNAS_MAX])
{
    int i , j;

    printf("LOTES");

    for (j =0; j < COLUNAS_MAX; j++)
    {
        printf("    COL-%d", j);
    }
    printf("\n\n");

    for (i = 0; i < LINHAS_MAX; i++)
    {
        printf("lIN-%d", i);

        for (j = 0; j < COLUNAS_MAX; j++)
        {
            if (matriz[i][j].reservaAtual.tipoAlojamento == '\0')
            {
                printf("      ...");
            }
            else
            {
                printf("      %c%d%d", matriz[i][j].reservaAtual.tipoAlojamento,
                   matriz[i][j].reservaAtual.isComEletricidade,
                   matriz[i][j].reservaAtual.numeroDeOcupantes);
            }
        }

        printf("\n\n");
    }
}

TipoLote reservarLote(int linha, int coluna)
{
    TipoLote matrizLote[linha][coluna];
    char alojamento;
    int eletricidade, ocupantes;

    printf("Qual o tipo de reserva (T/C/B): ");
    scanf(" %c", &alojamento);
    fflush(stdin);
    matrizLote[linha][coluna].reservaAtual.tipoAlojamento = alojamento;

    printf("Tem eletricidade? (0/1): ");
    scanf("%d", &eletricidade);
    fflush(stdin);
    matrizLote[linha][coluna].reservaAtual.isComEletricidade = eletricidade;

    printf("Quantos ocupantes tem?: ");
    scanf("%d", &ocupantes);
    fflush(stdin);
    if (ocupantes <= 0 || ocupantes > 6)
    {
        printf("ERRO! Minimo numero possível de ocupantes do lote é 1 e maximo permitido é 6");
        scanf("%d", &ocupantes);
        fflush(stdin);
    }
    else
    {
        matrizLote[linha][coluna].reservaAtual.numeroDeOcupantes = ocupantes;
    }

    for (int i = 0; i < ocupantes; i++)
    {
        printf("Nome do Ocupante: ");
        gets(matrizLote[linha][coluna].reservaAtual.ocupantes[i].nome);
        fflush(stdin);
        printf("Idade do Ocupante: ");
        scanf("%d", &matrizLote[linha][coluna].reservaAtual.ocupantes[i].idade);
        fflush(stdin);
    }

    return matrizLote[linha][coluna];
}

void consultarLote (int linha, int coluna, TipoLote matrizLote[][COLUNAS_MAX])
{
    printf("Reserva Atual - Alojamento: %c / Eletricidade: %d / Ocupantes: %d\n", matrizLote[linha][coluna].reservaAtual.tipoAlojamento,
           matrizLote[linha][coluna].reservaAtual.isComEletricidade,
           matrizLote[linha][coluna].reservaAtual.numeroDeOcupantes);
    for (int i = 0; i < HISTORICO_MAX; i++)
    {
       printf("Histórico - Reserva %d - Alojamento: %c / Eletricidade: %d / Ocupantes: %d\n", i + 1, matrizLote[linha][coluna].historico[i].tipoAlojamento,
              matrizLote[linha][coluna].historico[i].isComEletricidade,
              matrizLote[linha][coluna].historico[i].numeroDeOcupantes);
    }
}

void imprimeMenu(){

        system("COLOR C");
        printf("\n --------- Menu --------- \n");
        printf("\n 1 - Visualizar o mapa do Parque ");
        printf("\n 2 - Reservar um lote e registar os detalhes ");
        printf("\n 3 - Consultar um lote ");
        printf("\n 4 - Pesquisar lote por nome do campista");
        printf("\n 5 - Editar informação da reserva atual de um lote");
        printf("\n 6 - Eleminar a reserva do lote");
        printf("\n 7 - Fechar Programa ");
        printf("\n --------- // ---------- \n");

}

void consultarLoteNome (TipoLote matriz[][COLUNAS_MAX])
{
    char nome[21];

    printf("Insira o nome do campista: ");
    gets(nome);
    fflush(stdin);

    for (int i = 0; i < LINHAS_MAX; i++)
    {
        for (int j = 0; j < COLUNAS_MAX; j++)
        {
            int ocupantes = matriz[i][j].reservaAtual.numeroDeOcupantes;

            for (int k = 0; k < ocupantes; k++)
            {
                if (strcmp(nome, matriz[i][j].reservaAtual.ocupantes[k].nome) == 0)
                {
                    printf("Reserva Atual - Alojamento: %c / Eletricidade: %d / Ocupantes: %d\n", matriz[i][j].reservaAtual.tipoAlojamento,
                    matriz[i][j].reservaAtual.isComEletricidade,
                    matriz[i][j].reservaAtual.numeroDeOcupantes);
                    break;
                }
                else
                {
                    printf("ERRO! Nome não encontrado!");
                }
            }
            ocupantes = 0;
        }
    }
}

void editarReserva (int linha, int coluna, TipoLote matriz[][COLUNAS_MAX])
{
    char edicao, alojamento;
    int eletrecidade, nOcupantes;

    printf("Reserva Atual - Alojamento: %c / Eletricidade: %d / Ocupantes: %d\n", matriz[linha][coluna].reservaAtual.tipoAlojamento,
           matriz[linha][coluna].reservaAtual.isComEletricidade,
           matriz[linha][coluna].reservaAtual.numeroDeOcupantes);
    do{
        printf("Alojamento - A\n");
        printf("Eletrcidade - E\n");
        printf("Nº de Ocupantes - N\n"),
        printf("Sair - S\n");
        printf("Qual é o campo a ser editado?: ");
        scanf(" %c", &edicao);
        fflush(stdin);

        switch(edicao)
        {
            case 'A': case 'a':
                printf("Qual o novo tipo de alojamento?: ");
                scanf(" %c", &alojamento);
                fflush(stdin);

                matriz[linha][coluna].reservaAtual.tipoAlojamento = alojamento;
                break;
            case 'E': case 'e':
                printf("Novo valor de eletrecidade? ");
                scanf("%d", &eletrecidade);
                fflush(stdin);

                if (eletrecidade < 0 || eletrecidade > 1)
                {
                    printf("Eletrecidade só pode ter o valore de 0 (NAO) ou 1 (SIM)");
                    scanf("%d", &eletrecidade);
                    fflush(stdin);
                }

                matriz[linha][coluna].reservaAtual.isComEletricidade = eletrecidade;
                break;
            case 'N': case 'n':
                printf("Quantos ocupantes tem o lote?: ");
                scanf("%d", &nOcupantes);
                fflush(stdin);

                if (nOcupantes < 0 || nOcupantes > 6)
                {
                    printf("O Numero de ocupantes do lote não pode ser abaixo de 0 nem acima de 6!");
                    scanf("%d", &nOcupantes);
                    fflush(stdin);
                }

                matriz[linha][coluna].reservaAtual.numeroDeOcupantes = nOcupantes;
                break;
            case 'S': case 's':
                printf("A sair da edição de Lote.\n");
                break;
            default:
                printf("ERRO! Opção não existe! Tente de Novo.\n");
                break;
        }
    }while(edicao != 'S' && edicao != 's');
}

void eleminarReserva (int linha, int coluna, TipoLote matriz[][COLUNAS_MAX])
{
    TipoReserva temp;
    int nOcupantes;

    temp = matriz[linha][coluna].historico[HISTORICO_MAX-1];
    for (int i = HISTORICO_MAX-1; i > 0; i--)
    {
        matriz[linha][coluna].historico[i] = matriz[linha][coluna].historico[i-1];
    }
    matriz[linha][coluna].historico[0] = temp;
    matriz[linha][coluna].historico[0] = matriz[linha][coluna].reservaAtual;


    matriz[linha][coluna].reservaAtual.tipoAlojamento = '\0';
    matriz[linha][coluna].reservaAtual.isComEletricidade = 0;
    nOcupantes = matriz[linha][coluna].reservaAtual.numeroDeOcupantes;
    for (int j = 0; j < nOcupantes; j++)
    {
        matriz[linha][coluna].reservaAtual.ocupantes[j].nome[0] = '\0';
        matriz[linha][coluna].reservaAtual.ocupantes[j].idade = 0;
    }
    matriz[linha][coluna].reservaAtual.numeroDeOcupantes = 0;

    printf("Reserva Eleminada.");
}
