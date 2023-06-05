#pragma once
#include <stdio.h>

#include "../include/meio.h"    /** arquivo de cabeçalho referente a outro arquivo de código fonte */
#include "../include/cliente.h" /** arquivo de cabeçalho referente a outro arquivo de código fonte */

/*---------------------------------------------------------------
 <copyright file="aluguer.h" company="IPCA"> Copyright IPCA. Todos os direitos reservados. </copyright>
 <date>2023</date>
 <author>Ruben Tinoco Martins</author>
 <email>a18529@alunos.ipca.pt</email>
 <version>1.0</version>
 <desc>Manipulação de aluguéis e listas ligadas</desc>
----------------------------------------------------------------*/

typedef struct aluguerRegisto
{
    int clienteNif;                  /** número de identificação fiscal do cliente */
    int meioCodigo;                  /** código do meio de mobilidade elétrica */
    struct aluguerRegisto *seguinte; /** ponteiro para o próximo aluguer na lista ligada */
} Aluguer;

/** Insere um novo registo de aluguer no início da lista ligada */
Aluguer *inserirAluguer(Aluguer *inicio, int cliNif, int meCod);

/** Verifica se existe um registo de aluguer para o cliente com o número de identificação fiscal 'cliNif' */
/** e para o meio de mobilidade elétrica com o código 'meCod' */
int existeAluguer(Aluguer *inicio, int cliNif, int meCod);

/** Guarda os registos de aluguer presentes na lista ligada em um arquivo */
int guardarAlugueres(Aluguer *inicio);

/** Lê os registos de aluguer de um arquivo e cria uma lista ligada com eles */
Aluguer *lerAlugueres();

void alugarMeio(Meio *meios, int meCod);

int meioDisponivel(Meio *meios, int meCod);

void listarMeiosDisponiveis(Meio *inicio);

void listarMeiosDisponiveisParaAlugar(Meio *inicio, const char *clienteGeocodigo);

int haMeiosDisponiveis(Meio *inicio);

void devolverMeio(Meio *meios, Aluguer *alugueres, Cliente *clientes, int cliNif, int meCod, int tempoUtilizacao, float distancia, char geocodigoDestino[]);

int guardarAlugueresBinario(Aluguer *inicio);

Aluguer *lerAlugueresBinario();

Aluguer *removerAluguer(Aluguer *inicio, int cliNif, int meCod);

Aluguer *procurarAluguer(Aluguer *inicio, int cliNif, int meCod);

Aluguer *procurarAluguerPorNIF(Aluguer *inicio, int cliNif);

void listarMeiosPorNIF(Aluguer *alugueres, int cliNif);