#pragma once
#include <stdio.h>

/*---------------------------------------------------------------
 <copyright file="gestor.h" company="IPCA"> Copyright IPCA. Todos os direitos reservados. </copyright>
 <date>2023</date>
 <author>Ruben Tinoco Martins</author>
 <email>a18529@alunos.ipca.pt</email>
 <version>1.0</version>
 <desc>Definições e funções relacionadas aos gestores</desc>
----------------------------------------------------------------*/

typedef struct gestorRegisto
{
    int gestorNif;                  /** número de identificação fiscal do gestor */
    char gestorNome[50];            /** nome completo do gestor */
    char gestorEmail[50];           /** endereço de e-mail do gestor */
    char gestorCargo[50];           /** cargo ou função do gestor na organização */
    char gestorUsername[50];        /** nome de utilizador do gestor */
    char gestorPassword[50];        /** senha de acesso do gestor */
    struct gestorRegisto *seguinte; /** ponteiro para o próximo gestor na lista ligada */
} Gestor;

/** Insere um novo registo de gestor no início da lista ligada */
Gestor *inserirGestor(Gestor *inicio, int gesNif, char gesNome[], char gesEmail[], char gesCargo[], char gesUser[], char gesPass[]);

/** Lista todos os gestores presentes na lista ligada na consola */
void listarGestores(Gestor *inicio);

/** Verifica se um dado gestor com o 'nif' especificado existe na lista ligada 'inicio' */
int existeGestor(Gestor *inicio, int gesNif);

int validarLoginGestor(Gestor *inicio, char *gesUser, char *gesPass);

/** Remove o gestor com o 'nif' especificado da lista ligada 'inicio' */
Gestor *removerGestor(Gestor *inicio, int gesNif);

/** Edita as informações do gestor com o 'nif' especificado na lista ligada 'inicio' */
Gestor *editarGestor(Gestor *inicio, int gesNif, char gesNome[], char gesEmail[], char gesCargo[], char gesUser[], char gesPass[]);

/** Armazena a lista ligada 'inicio' em um arquivo de texto */
int guardarGestores(Gestor *inicio);

/** Lê e retorna uma lista ligada de gestores a partir de um arquivo de texto previamente criado */
Gestor *lerGestores();

int limparArquivoGestores();

/** Armazena a lista ligada 'inicio' em um arquivo binário */
int guardarGestoresBinario(Gestor *inicio);

/** Lê e retorna uma lista ligada de gestores a partir de um arquivo binário previamente criado */
Gestor *lerGestoresBinario();

int limparArquivoGestoresBinario();

void listarGestorComNIF(Gestor *inicio, int gesNif);