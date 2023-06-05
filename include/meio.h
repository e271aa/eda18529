#pragma once
#include <stdio.h>

/*---------------------------------------------------------------
 <copyright file="meio.h" company="IPCA"> Copyright IPCA. Todos os direitos reservados. </copyright>
 <date>2023</date>
 <author>Ruben Tinoco Martins</author>
 <email>a18529@alunos.ipca.pt</email>
 <version>1.0</version>
 <desc>Definições e funções relacionadas aos meios de mobilidade elétrica</desc>
----------------------------------------------------------------*/

typedef struct meioRegisto
{
    int meioCodigo;               /** código do meio de mobilidade elétrica */
    char meioTipo[50];            /** tipo do meio de mobilidade elétrica */
    float meioBateria;            /** nivel de bateria do meio de mobilidade elétrica */
    float meioAutonomia;          /** autonomia do meio de mobilidade elétrica */
    float meioPrecoPorMinuto;     /** preço por hora do meio de mobilidade elétrica */
    char meioGeocodigo[100];      /** código de localização geográfica do meio de mobilidade elétrica */
    int meioAlugado;              /** status do aluguer: 0 - não alugado, 1 - alugado */
    struct meioRegisto *seguinte; /** ponteiro para o próximo meio na lista ligada */
} Meio;

/** Insere um novo registo de meio no início da lista ligada */
Meio *inserirMeio(Meio *inicio, int meCod, char meTipo[], float meBat, float meAut, float mePre, char meGeo[], int meAlu);

/** Lista todos os meios presentes na lista ligada na consola */
void listarMeios(Meio *inicio);

void listarMeiosPorAutonomia(Meio *inicio);

/** Verifica se um dado meio com o 'codigo' especificado existe na lista ligada 'inicio' */
int existeMeio(Meio *inicio, int meCodigo);

/** Remove o meio com o 'codigo' especificado da lista ligada 'inicio' */
Meio *removerMeio(Meio *inicio, int meCod);

/** Edita as informações do meio com o 'codigo' especificado na lista ligada 'inicio' */
Meio *editarMeio(Meio *inicio, int meCod, char meTipo[], float meBat, float meAut, float mePre, char meGeo[], int meAlu);

/** Armazena a lista ligada 'inicio' em um arquivo de texto */
int guardarMeios(Meio *inicio);

/** Lê e retorna uma lista ligada de meios a partir de um arquivo de texto previamente criado */
Meio *lerMeios();

int limparArquivoMeios();

/** Armazena a lista ligada 'inicio' em um arquivo binário */
int guardarMeiosBinario(Meio *inicio);

/** Lê e retorna uma lista ligada de meios a partir de um arquivo binário previamente criado */
Meio *lerMeiosBinario();

int limparArquivoMeiosBinario();

Meio *obterMeioPorCodigo(Meio *meios, int meCod);

void listarMeioComCodigo(Meio *inicio, int meCod);