#pragma once
#include <stdio.h>

/*---------------------------------------------------------------
 <copyright file="cliente.h" company="IPCA"> Copyright IPCA. Todos os direitos reservados. </copyright>
 <date>2023</date>
 <author>Ruben Tinoco Martins</author>
 <email>a18529@alunos.ipca.pt</email>
 <version>1.0</version>
 <desc>Definições e funções relacionadas aos clientes</desc>
----------------------------------------------------------------*/

typedef struct clienteRegisto
{
    int clienteNif;                  /** número de identificação fiscal do cliente */
    char clienteNome[50];            /** nome completo do cliente */
    char clienteEmail[50];           /** endereço de e-mail do cliente */
    int clienteTelefone;             /** número de telefone do cliente */
    char clienteGeocodigo[100];      /** código de localização geográfica do cliente */
    float clienteSaldo;              /** saldo do cliente */
    char clienteUsername[50];        /** nome de utilizador do cliente */
    char clientePassword[50];        /** senha de acesso do cliente */
    struct clienteRegisto *seguinte; /** ponteiro para o próximo cliente na lista ligada */
} Cliente;

/** Insere um novo registo de cliente no início da lista ligada */
Cliente *inserirCliente(Cliente *inicio, int cliNif, char cliNome[], char cliEmail[], int cliTel, char cliGeo[], float cliSaldo, char cliUser[], char cliPass[]);

/** Lista todos os clientes presentes na lista ligada na consola */
void listarClientes(Cliente *inicio);

/** Verifica se um dado cliente com o 'nif' especificado existe na lista ligada 'inicio' */
int existeCliente(Cliente *inicio, int cliNif);

int validarLoginCliente(Cliente *inicio, char *cliUser, char *cliPass);

/** Remove o cliente com o 'nif' especificado da lista ligada 'inicio' */
Cliente *removerCliente(Cliente *inicio, int cliNif);

/** Edita as informações do cliente com o 'nif' especificado na lista ligada 'inicio' */
Cliente *editarCliente(Cliente *inicio, int cliNif, char cliNome[], char cliEmail[], int cliTel, char cliGeo[], float cliSaldo, char cliUser[], char cliPass[]);

/** Armazena a lista ligada 'inicio' em um arquivo de texto */
int guardarClientes(Cliente *inicio);

/** Lê e retorna uma lista ligada de clientes a partir de um arquivo de texto previamente criado */
Cliente *lerClientes();

int limparArquivoClientes();

/** Armazena a lista ligada 'inicio' em um arquivo binário */
int guardarClientesBinario(Cliente *inicio);

/** Lê e retorna uma lista ligada de clientes a partir de um arquivo binário previamente criado */
Cliente *lerClientesBinario();

int limparArquivoClientesBinario();

Cliente *procurarCliente(Cliente *inicio, int cliNif);

Cliente *obterClientePorUsername(Cliente *clientes, char *username);

Cliente *obterClientePorNif(Cliente *clientes, int cliNif);

int guardarClientesLeitura(Cliente *inicio);

void listarClienteComNIF(Cliente *inicio, int cliNif);