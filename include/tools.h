#pragma once
#include <stdio.h>

/*---------------------------------------------------------------
 <copyright file="tools.h" company="IPCA"> Copyright IPCA. Todos os direitos reservados. </copyright>
 <date>2023</date>
 <author>Ruben Tinoco Martins</author>
 <email>a18529@alunos.ipca.pt</email>
 <version>1.0</version>
 <desc>Definição de estruturas e funções auxiliares</desc>
----------------------------------------------------------------*/

typedef struct Stack
{
    int *array;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity);

int isFull(Stack *stack);

int isEmpty(Stack *stack);

void push(Stack *stack, int item);

int pop(Stack *stack);

//////////////////////////////////////////////////////

void menuCriarGrafo();

//////////////////////////////////////////////////////

void imprimirLinha(char c);

void imprimirCoisas(char c);

void imprimirCentrado(char c, const char *texto);

void imprimeEspacos(char *str);

//////////////////////////////////////////////////////

void loading();

//////////////////////////////////////////////////////

void menuPrincipal(int opMenu);

void menuCliente(int opCliente);

void menuGestor(int opGestor);

void menuGerirMeio(int opGerirMeio);

void menuGerirCliente(int opGerirCliente);

void menuGerirGestor(int opGerirGestor);

//////////////////////////////////////////////////////

int login(char *username, char *password);

//////////////////////////////////////////////////////

void validacaoOperacao(int opVal);

//////////////////////////////////////////////////////

void menuCarregarSaldo(char *username);

void menuAdicionarMeio();

void menuRemoverMeio();

void menuRemoverTodosMeios();

void menuEditarMeio();

void menuListarMeio();

void menuListarAutonomiaMeio();

//////////////////////////////////////////////////////

void menuAdicionarCliente();

void menuRemoverCliente();

void menuRemoverTodosClientes();

void menuEditarCliente();

void menuListarCliente();

//////////////////////////////////////////////////////

void menuAdicionarGestor();

void menuRemoverGestor();

void menuRemoverTodosGestores();

void menuEditarGestor();

void menuListarGestor();

//////////////////////////////////////////////////////

void credenciaisInvalidas();

//////////////////////////////////////////////////////

void menuListarMeiosDisponiveis();

void menuAlugarMeio();

void menuDevolverMeio();