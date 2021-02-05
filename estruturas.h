#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#define OCUPANTES_MAX 6
#define HISTORICO_MAX 3

typedef struct pessoa
{
    char nome[30+1];
    int idade;
} TipoPessoa;

typedef struct reserva
{
    char tipoAlojamento; //T-tenda; C-caravana; B-Bungalow; '\0'-vazio;
    int isComEletricidade;//0 or 1
    int numeroDeOcupantes;
    TipoPessoa ocupantes[OCUPANTES_MAX];
} TipoReserva;

typedef struct lote
{
    TipoReserva reservaAtual; //T-tenda; C-caravana; B-Bungalow; '\0'-vazio;
    TipoReserva historico[HISTORICO_MAX];
} TipoLote;

#endif // ESTRUTURAS_H_INCLUDED
