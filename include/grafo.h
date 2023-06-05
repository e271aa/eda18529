#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------
 <copyright file="grafo.h" company="IPCA"> Copyright IPCA. Todos os direitos reservados. </copyright>
 <date>2023</date>
 <author>Ruben Tinoco Martins</author>
 <email>a18529@alunos.ipca.pt</email>
 <version>1.0</version>
 <desc>Declarações e estruturas para manipulação de grafos</desc>
----------------------------------------------------------------*/

typedef struct adjacenteRegisto
{
    char geocodigo[100];
    float distancia;
    struct adjacenteRegisto *seguinte;
} Adjacente;

typedef struct verticeRegisto
{
    char geocodigo[100];
    Adjacente *adjacentes;
    struct verticeRegisto *seguinte;
} Vertice;

typedef struct Grafo
{
    Vertice *vertices;
} Grafo;

Grafo *criarGrafo();

Vertice *criarVertice(char geocodigo[]);

void adicionarVertice(Grafo *grafo, Vertice *vertice);

int criarAresta(Grafo *grafo, char geocodigoOrigem[], char geocodigoDestino[], float distancia);

void listarAdjacentes(Grafo *grafo, char geocodigo[]);

void guardarGrafo(Grafo *grafo, const char *nomeArquivo);

Grafo *lerGrafo(const char *nomeArquivo);

void guardarGrafoBinario(Grafo *grafo, const char *nomeArquivo);

Grafo *lerGrafoBinario(const char *nomeArquivo);

float obterDistanciaAdjacente(Grafo *grafo, char geocodigoOrigem[], char geocodigoDestino[]);