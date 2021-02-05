#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "estruturas.h"
#include "subprogramas.c"
#define LINHAS_MAX 5
#define COLUNAS_MAX 5

int main()
{
    setlocale(LC_ALL, "portuguese");
    FILE *F;

    TipoLote matrizLotes[LINHAS_MAX][COLUNAS_MAX] = {};
    int linha, coluna;
    int opcao;

    F = fopen("matriz.bin", "rb");
    fread(matrizLotes, sizeof(TipoLote), LINHAS_MAX*COLUNAS_MAX, F);
    fclose(F);

    do{
        imprimeMenu();
        printf("\nEscolha uma opcção: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){

            case 1:
                imprimirParque(matrizLotes);
                break;

            case 2:
                printf("Insira a linha onde o lote está:");
                scanf("%d", &linha);
                fflush(stdin);
                printf("Insira a Coluna onde o lote está:");
                scanf("%d", &coluna);
                fflush(stdin);

                matrizLotes[linha][coluna] = reservarLote(linha, coluna);
                break;

            case 3:
                printf("Insira a linha onde o lote está: ");
                scanf("%d", &linha);
                fflush(stdin);
                printf("Insira a Coluna onde o lote está: ");
                scanf("%d", &coluna);
                fflush(stdin);

                consultarLote(linha, coluna, matrizLotes);
                break;

            case 4:
                consultarLoteNome(matrizLotes);
                break;

            case 5:
                printf("Insira a linha onde o lote está: ");
                scanf("%d", &linha);
                fflush(stdin);
                printf("Insira a Coluna onde o lote está: ");
                scanf("%d", &coluna);
                fflush(stdin);

                editarReserva(linha, coluna, matrizLotes);
                break;

            case 6:
                printf("Insira a linha onde o lote está: ");
                scanf("%d", &linha);
                fflush(stdin);
                printf("Insira a Coluna onde o lote está: ");
                scanf("%d", &coluna);
                fflush(stdin);

                eleminarReserva(linha, coluna, matrizLotes);
                break;

            case 7:
                F = fopen("matriz.bin", "wb");
                fwrite(matrizLotes, sizeof(TipoLote), LINHAS_MAX*COLUNAS_MAX, F);
                fflush(stdin);
                fclose(F);
                printf("Fim do Programa");
                break;

            default:
                printf("ERRO! Opção não existe!");
                break;
        }
    }while(opcao != 7);

    return 0;
}
