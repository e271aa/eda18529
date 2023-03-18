#include <stdlib.h>
#include <string.h>
#include "cliente.h"


int guardarClientes(Cliente* inicio)
{
    FILE* fp;
    fp = fopen("clientes.txt","w");
    if (fp!=NULL)
    {
        Cliente* aux= inicio;
        while (aux != NULL)
        {
            fprintf(fp,"%d;%s;%s;%s\n", aux->codigo, aux->nome, 
                            aux->telefone, aux->endereco);
            aux = aux->seguinte;
        }
        fclose(fp);
        return(1);
    }
    else return(0);
}

Cliente* lerClientes()
{
    FILE* fp;
    int cod;
    char nome[50], telefone[20], endereco[100];
    Cliente* aux=NULL;
    fp = fopen("clientes.txt","r");
    if (fp!=NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp,"%d;%[^;];%[^;];%[^\n]s\n", &cod, nome, telefone, endereco);
            aux = inserirCliente(aux, cod, nome, telefone, endereco);
        }
        fclose(fp);
    }
    return(aux);
}

// Inserção de um novo registo de cliente
Cliente* inserirCliente(Cliente * inicio, int cod, char nome[], char telefone[], char endereco[])
{
    if (!existeCliente(inicio, cod))
    {
        Cliente * novo = malloc(sizeof(struct cliente_registo));
        if (novo != NULL)
        {
            novo->codigo = cod;
            strcpy(novo->nome,nome);
            strcpy(novo->telefone,telefone);
            strcpy(novo->endereco,endereco);
            novo->seguinte = inicio;
            return(novo);
        }
    } 
    else return(inicio);
}

// listar na consola o conteúdo da lista ligada de clientes
void listarClientes(Cliente * inicio)
{
    while (inicio != NULL)
    {
        printf("%d %s %s %s\n",inicio->codigo,inicio->nome, 
                    inicio->telefone, inicio->endereco);
        inicio = inicio->seguinte;
    }
}

// Determinar existência do 'codigo' na lista ligada 'inicio' de clientes
// devolve 1 se existir ou 0 caso contrário
int existeCliente(Cliente* inicio, int cod)
{
    while(inicio!=NULL)
    {
        if (inicio->codigo == cod) return(1);
        inicio = inicio->seguinte;
    }
    return(0);
}

// Remover um cliente a partir do seu código
Cliente* removerCliente(Cliente* inicio, int cod) 
{
    Cliente *anterior=inicio, *atual=inicio, *aux;

    if (atual==NULL) return(NULL);
    else if (atual->codigo == cod) // remoção do 1º registo
    {
        aux = atual->seguinte;
        free(atual);
        return(aux);
    }
    else
    {
        while ((atual!=NULL)&&(atual->codigo!=cod)) 
        {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual==NULL) return(inicio);
        else
        {anterior->seguinte = atual->seguinte;
        free(atual);
        return(inicio);
        }
    }
}
