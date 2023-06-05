#include <stdlib.h>
#include <string.h>
#include "../include/meio.h"
#include "../include/tools.h"

int guardarMeios(Meio *inicio)
{
  FILE *fp;
  fp = fopen("../db/meios.txt", "w");
  if (fp != NULL)
  {
    Meio *aux = inicio;
    while (aux != NULL)
    {
      fprintf(fp, "%d;%f;%f;%f;%d;%s;%s\n", aux->meioCodigo, aux->meioBateria, aux->meioAutonomia, aux->meioPrecoPorMinuto, aux->meioAlugado, aux->meioTipo, aux->meioGeocodigo);
      aux = aux->seguinte;
    }
    fclose(fp);
    return (1);
  }
  else
    return (0);
}

Meio *lerMeios()
{
  FILE *fp;
  int meCod, meAlu;
  float meBat, meAut, mePre;
  char meTipo[50], meGeo[100];
  Meio *aux = NULL;
  fp = fopen("../db/meios.txt", "r");
  if (fp != NULL)
  {
    while (fscanf(fp, "%d;%f;%f;%f;%d;%s;%s\n", &meCod, &meBat, &meAut, &mePre, &meAlu, meTipo, meGeo) == 7)
    {
      aux = inserirMeio(aux, meCod, meTipo, meBat, meAut, mePre, meGeo, meAlu);
    }
    fclose(fp);
  }
  return (aux);
}

int limparArquivoMeios()
{
  FILE *fp;
  fp = fopen("../db/meios.txt", "w");
  if (fp != NULL)
  {
    fclose(fp);
    return 1;
  }
  else
    return 0;
}

int guardarMeiosBinario(Meio *inicio)
{
  FILE *fp;
  fp = fopen("../db/meios.bin", "wb");
  if (fp != NULL)
  {
    Meio *aux = inicio;
    while (aux != NULL)
    {
      fwrite(aux, sizeof(Meio), 1, fp);
      aux = aux->seguinte;
    }
    fclose(fp);
    return (1);
  }
  else
    return (0);
}

Meio *lerMeiosBinario()
{
  FILE *fp;
  Meio *inicio = NULL;
  fp = fopen("../db/meios.bin", "rb");
  if (fp != NULL)
  {
    Meio m;
    while (fread(&m, sizeof(Meio), 1, fp) == 1)
    {
      inicio = inserirMeio(inicio, m.meioCodigo, m.meioTipo, m.meioBateria, m.meioAutonomia, m.meioPrecoPorMinuto, m.meioGeocodigo, m.meioAlugado);
    }
    fclose(fp);
  }
  return (inicio);
}

int limparArquivoMeiosBinario()
{
  FILE *fp;
  fp = fopen("../db/meios.bin", "wb");
  if (fp != NULL)
  {
    fclose(fp);
    return 1;
  }
  else
    return 0;
}

Meio *inserirMeio(Meio *inicio, int meCod, char meTipo[], float meBat, float meAut, float mePre, char meGeo[], int meAlu)
{
  Meio *novo = malloc(sizeof(struct meioRegisto));
  if (novo != NULL)
  {
    novo->meioCodigo = meCod;
    strcpy(novo->meioTipo, meTipo);
    novo->meioBateria = meBat;
    novo->meioAutonomia = meAut;
    novo->meioPrecoPorMinuto = mePre;
    strcpy(novo->meioGeocodigo, meGeo);
    novo->meioAlugado = meAlu;
    novo->seguinte = inicio;
    inicio = novo;
  }
  return inicio;
}

void listarMeios(Meio *inicio)
{
  int n = 0;
  Meio *p = inicio;
  /** contar o número de elementos na lista */
  while (p != NULL)
  {
    n++;
    p = p->seguinte;
  }
  /** criar um vetor temporário */
  Meio **meios = malloc(n * sizeof(Meio *));
  /** copiar os elementos da lista para o vetor */
  p = inicio;
  for (int i = 0; i < n; i++)
  {
    meios[i] = p;
    p = p->seguinte;
  }
  /** ordenar o vetor por número de meio */
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (meios[i]->meioCodigo > meios[j]->meioCodigo)
      {
        Meio *temp = meios[i];
        meios[i] = meios[j];
        meios[j] = temp;
      }
    }
  }
  /** imprimir os elementos do vetor em ordem crescente de número de meio */
  for (int i = 0; i < n; i++)
  {
    imprimirLinha('\xC4');
    printf("\033[1mCodigo do meio: %d\033[0m\n > Tipo de mobilidade: %s\n > Nivel da bateria: %.1f%%\n > Autonomia: %.1fkm\n > Preco por minuto: %.2f euros\n > Geocodigo: %s\n > Status: %s\n", meios[i]->meioCodigo, meios[i]->meioTipo, meios[i]->meioBateria, meios[i]->meioAutonomia, meios[i]->meioPrecoPorMinuto, meios[i]->meioGeocodigo, meios[i]->meioAlugado ? "Alugado" : "Disponivel");
  }
  imprimirLinha('\xC4');
  /** liberar a memória alocada para o vetor */
  free(meios);
}

void listarMeiosPorAutonomia(Meio *inicio)
{
  int n = 0;
  Meio *p = inicio;
  /** contar o número de elementos na lista */
  while (p != NULL)
  {
    n++;
    p = p->seguinte;
  }
  /** criar um vetor temporário */
  Meio **meios = malloc(n * sizeof(Meio *));
  /** copiar os elementos da lista para o vetor */
  p = inicio;
  for (int i = 0; i < n; i++)
  {
    meios[i] = p;
    p = p->seguinte;
  }
  /** ordenar o vetor por autonomia */
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (meios[i]->meioAutonomia < meios[j]->meioAutonomia)
      {
        Meio *temp = meios[i];
        meios[i] = meios[j];
        meios[j] = temp;
      }
    }
  }
  /** imprimir os elementos do vetor em ordem decrescente de autonomia */
  for (int i = 0; i < n; i++)
  {
    imprimirLinha('\xC4');
    printf("\033[1mCodigo do meio: %d\033[0m\n > Tipo de mobilidade: %s\n > Nivel da bateria: %.1f%%\n > Autonomia: %.1fkm\n > Preco por minuto: %.2f euros\n > Geocodigo: %s\n > Status: %s\n", meios[i]->meioCodigo, meios[i]->meioTipo, meios[i]->meioBateria, meios[i]->meioAutonomia, meios[i]->meioPrecoPorMinuto, meios[i]->meioGeocodigo, meios[i]->meioAlugado ? "Alugado" : "Disponivel");
  }
  imprimirLinha('\xC4');
}

void listarMeioComCodigo(Meio *inicio, int meCod)
{
    Meio *p = inicio;
    int encontrado = 0;

    while (p != NULL)
    {
        if (p->meioCodigo == meCod)
        {
            encontrado = 1;
            printf("\033[1mCodigo do meio: %d\033[0m\n > Tipo de mobilidade: %s\n > Nivel da bateria: %.1f%%\n > Autonomia: %.1fkm\n > Preco por minuto: %.2f euros\n > Geocodigo: %s\n > Status: %s\n", p->meioCodigo, p->meioTipo, p->meioBateria, p->meioAutonomia, p->meioPrecoPorMinuto, p->meioGeocodigo, p->meioAlugado ? "Alugado" : "Disponivel");
        }
        p = p->seguinte;
    }
}


/** Determinar existência do 'codigo' na lista ligada 'inicio' */
/** devolve 1 se existir ou 0 caso contrário */
int existeMeio(Meio *inicio, int meCod)
{
  while (inicio != NULL)
  {
    if (inicio->meioCodigo == meCod)
      return (1);
    inicio = inicio->seguinte;
  }
  return (0);
}

/** Remover um meio a partir do seu código */
Meio *removerMeio(Meio *inicio, int meCod)
{
  Meio *anterior = inicio, *atual = inicio, *aux;

  if (atual == NULL)
    return (NULL);
  else if (atual->meioCodigo == meCod) /** remoção do 1º registo */
  {
    aux = atual->seguinte;
    free(atual);
    return (aux);
  }
  else
  {
    while ((atual != NULL) && (atual->meioCodigo != meCod))
    {
      anterior = atual;
      atual = atual->seguinte;
    }
    if (atual == NULL)
      return (inicio);
    else
    {
      anterior->seguinte = atual->seguinte;
      free(atual);
      return (inicio);
    }
  }
}

Meio *editarMeio(Meio *inicio, int meCod, char meTipo[], float meBat, float meAut, float mePre, char meGeo[], int meAlu)
{
  Meio *aux = inicio;
  while (aux != NULL)
  {
    if (aux->meioCodigo == meCod)
    {
      if (strlen(meTipo) > 0)
        strcpy(aux->meioTipo, meTipo);
      if (meBat != -1) /** se valor diferente de -1, altera o campo */
        aux->meioBateria = meBat;
      if (meAut != -1) /** se valor diferente de -1, altera o campo */
        aux->meioAutonomia = meAut;
      if (mePre != -1) /** se valor diferente de -1, altera o campo */
        aux->meioPrecoPorMinuto = mePre;
      if (strlen(meGeo) > 0)
        strcpy(aux->meioGeocodigo, meGeo);
      if (meAlu != -1) /** se valor diferente de -1, altera o campo */
        aux->meioAlugado = meAlu;
      return inicio;
    }
    aux = aux->seguinte;
  }
  printf("\nMeio com codigo %d nao encontrado!\n", meCod);
  return inicio;
}

Meio *obterMeioPorCodigo(Meio *meios, int meCod)
{
  Meio *atual = meios;
  while (atual != NULL && atual->meioCodigo != meCod)
  {
    atual = atual->seguinte;
  }
  return atual;
}