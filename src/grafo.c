#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/grafo.h"   /** Ficheiro de cabeçalho referente a outro arquivo de código fonte */

Grafo *criarGrafo()
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->vertices = NULL;
    return grafo;
}

Vertice *criarVertice(char geocodigo[])
{
    Vertice *vertice = (Vertice *)malloc(sizeof(Vertice));
    strcpy(vertice->geocodigo, geocodigo);
    vertice->adjacentes = NULL;
    vertice->seguinte = NULL;
    return vertice;
}

void adicionarVertice(Grafo *grafo, Vertice *vertice)
{
    if (grafo->vertices == NULL)
    {
        grafo->vertices = vertice;
    }
    else
    {
        Vertice *atual = grafo->vertices;
        while (atual->seguinte != NULL)
        {
            atual = atual->seguinte;
        }
        atual->seguinte = vertice;
    }
}

int criarAresta(Grafo *grafo, char geocodigoOrigem[], char geocodigoDestino[], float distancia)
{
    Vertice *origem = NULL;
    Vertice *destino = NULL;
    Adjacente *adjacenteOrigem = NULL;
    Adjacente *adjacenteDestino = NULL;

    Vertice *atual = grafo->vertices;
    while (atual != NULL)
    {
        if (strcmp(atual->geocodigo, geocodigoOrigem) == 0)
        {
            origem = atual;
        }
        if (strcmp(atual->geocodigo, geocodigoDestino) == 0)
        {
            destino = atual;
        }
        if (origem != NULL && destino != NULL)
        {
            break;
        }
        atual = atual->seguinte;
    }

    if (origem == NULL || destino == NULL)
    {
        return 0; /** Vértices não encontrados */
    }

    adjacenteOrigem = (Adjacente *)malloc(sizeof(Adjacente));
    strcpy(adjacenteOrigem->geocodigo, geocodigoDestino);
    adjacenteOrigem->distancia = distancia;
    adjacenteOrigem->seguinte = origem->adjacentes;
    origem->adjacentes = adjacenteOrigem;

    adjacenteDestino = (Adjacente *)malloc(sizeof(Adjacente));
    strcpy(adjacenteDestino->geocodigo, geocodigoOrigem);
    adjacenteDestino->distancia = distancia;
    adjacenteDestino->seguinte = destino->adjacentes;
    destino->adjacentes = adjacenteDestino;

    return 1; /** Aresta criada com sucesso */
}

void listarAdjacentes(Grafo *grafo, char geocodigo[])
{
    Vertice *vertice = NULL;
    Adjacente *adjacente = NULL;

    Vertice *atual = grafo->vertices;
    while (atual != NULL)
    {
        if (strcmp(atual->geocodigo, geocodigo) == 0)
        {
            vertice = atual;
            break;
        }
        atual = atual->seguinte;
    }

    if (vertice == NULL)
    {
        printf("Vertice nao encontrado.\n");
        return;
    }

    adjacente = vertice->adjacentes;
    printf("Adjacentes do vertice %s:\n", vertice->geocodigo);
    while (adjacente != NULL)
    {
        printf("- Geocodigo: %s, Distancia: %.2f\n", adjacente->geocodigo, adjacente->distancia);
        adjacente = adjacente->seguinte;
    }
}

void guardarGrafo(Grafo *grafo, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Vertice *vertice = grafo->vertices;
    while (vertice != NULL)
    {
        fprintf(arquivo, "Vertice: %s\n", vertice->geocodigo);

        Adjacente *adjacente = vertice->adjacentes;
        while (adjacente != NULL)
        {
            fprintf(arquivo, " - Adjacente: %s, Distancia: %.2f\n", adjacente->geocodigo, adjacente->distancia);
            adjacente = adjacente->seguinte;
        }

        vertice = vertice->seguinte;
    }

    fclose(arquivo);
    printf("Grafo salvo com sucesso no arquivo %s.\n", nomeArquivo);
}

Grafo *lerGrafo(const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    Grafo *grafo = criarGrafo();
    Vertice *verticeAtual = NULL;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (linha[0] == '\n') {
            continue;  /** Ignorar linhas em branco */
        }

        if (strncmp(linha, "Vertice: ", 9) == 0)
        {
            char geocodigo[100];
            sscanf(linha, "Vertice: %[^\n]", geocodigo);
            Vertice *vertice = criarVertice(geocodigo);
            adicionarVertice(grafo, vertice);
            verticeAtual = vertice;
        }
        else if (verticeAtual != NULL && strncmp(linha, " - Adjacente: ", 14) == 0)
        {
            char geocodigo[100];
            float distancia;
            sscanf(linha, " - Adjacente: %[^,], Distancia: %f", geocodigo, &distancia);
            criarAresta(grafo, verticeAtual->geocodigo, geocodigo, distancia);
        }
    }

    fclose(arquivo);
    printf("Grafo lido com sucesso do arquivo %s.\n", nomeArquivo);
    return grafo;
}

void guardarGrafoBinario(Grafo *grafo, const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo binário para escrita.\n");
        return;
    }

    Vertice *vertice = grafo->vertices;
    while (vertice != NULL)
    {
        int tamanhoGeocodigo = strlen(vertice->geocodigo) + 1; /** Inclui o caractere nulo */
        fwrite(&tamanhoGeocodigo, sizeof(int), 1, arquivo);
        fwrite(vertice->geocodigo, sizeof(char), tamanhoGeocodigo, arquivo);

        Adjacente *adjacente = vertice->adjacentes;
        while (adjacente != NULL)
        {
            int tamanhoGeocodigoAdjacente = strlen(adjacente->geocodigo) + 1; /** Inclui o caractere nulo */
            fwrite(&tamanhoGeocodigoAdjacente, sizeof(int), 1, arquivo);
            fwrite(adjacente->geocodigo, sizeof(char), tamanhoGeocodigoAdjacente, arquivo);
            fwrite(&adjacente->distancia, sizeof(float), 1, arquivo);

            adjacente = adjacente->seguinte;
        }

        vertice = vertice->seguinte;
    }

    fclose(arquivo);
    printf("Grafo salvo com sucesso no arquivo binário %s.\n", nomeArquivo);
}

Grafo *lerGrafoBinario(const char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo binário para leitura.\n");
        return NULL;
    }

    Grafo *grafo = criarGrafo();
    Vertice *verticeAtual = NULL;
    char geocodigo[100];
    int tamanhoGeocodigo;

    while (fread(&tamanhoGeocodigo, sizeof(int), 1, arquivo) == 1)
    {
        fread(geocodigo, sizeof(char), tamanhoGeocodigo, arquivo);
        Vertice *vertice = criarVertice(geocodigo);
        adicionarVertice(grafo, vertice);
        verticeAtual = vertice;

        int tamanhoGeocodigoAdjacente;
        while (fread(&tamanhoGeocodigoAdjacente, sizeof(int), 1, arquivo) == 1)
        {
            char geocodigoAdjacente[100];
            fread(geocodigoAdjacente, sizeof(char), tamanhoGeocodigoAdjacente, arquivo);
            float distancia;
            fread(&distancia, sizeof(float), 1, arquivo);
            criarAresta(grafo, verticeAtual->geocodigo, geocodigoAdjacente, distancia);
        }
    }

    fclose(arquivo);
    printf("Grafo lido com sucesso do arquivo binário %s.\n", nomeArquivo);
    return grafo;
}

float obterDistanciaAdjacente(Grafo *grafo, char geocodigoOrigem[], char geocodigoDestino[])
{
    Vertice *verticeOrigem = NULL;
    Vertice *verticeDestino = NULL;
    
    Vertice *atual = grafo->vertices;
    while (atual != NULL)
    {
        if (strcmp(atual->geocodigo, geocodigoOrigem) == 0)
        {
            verticeOrigem = atual;
        }
        if (strcmp(atual->geocodigo, geocodigoDestino) == 0)
        {
            verticeDestino = atual;
        }
        if (verticeOrigem != NULL && verticeDestino != NULL)
        {
            break;
        }
        atual = atual->seguinte;
    }

    if (verticeOrigem == NULL || verticeDestino == NULL)
    {
        printf("Vertices nao encontrados.\n");
        return -1;
    }

    Adjacente *adjacente = verticeOrigem->adjacentes;
    while (adjacente != NULL)
    {
        if (strcmp(adjacente->geocodigo, geocodigoDestino) == 0)
        {
            return adjacente->distancia;
        }
        adjacente = adjacente->seguinte;
    }

    printf("Vertice adjacente nao encontrado.\n");
    return -1;
}
