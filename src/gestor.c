#include <stdlib.h>
#include <string.h>
#include "../include/gestor.h"
#include "../include/tools.h"

int guardarGestores(Gestor *inicio)
{
  FILE *fp;
  fp = fopen("../db/gestores.txt", "w");
  if (fp != NULL)
  {
    Gestor *aux = inicio;
    while (aux != NULL)
    {
      fprintf(fp, "%d;%s;%s;%s;%s;%s\n", aux->gestorNif, aux->gestorNome, aux->gestorEmail, aux->gestorCargo, aux->gestorUsername, aux->gestorPassword);
      aux = aux->seguinte;
    }
    fclose(fp);
    return (1);
  }
  else
    return (0);
}

Gestor *lerGestores()
{
  FILE *fp;
  int gesNif;
  char gesNome[50], gesEmail[50], gesCargo[50], gesUser[50], gesPass[50];
  Gestor *aux = NULL;
  fp = fopen("../db/gestores.txt", "r");
  if (fp != NULL)
  {
    while (fscanf(fp, "%d;%s;%s;%s;%s;%s\n", &gesNif, gesNome, gesEmail, gesCargo, gesUser, gesPass) == 6)
    {
      aux = inserirGestor(aux, gesNif, gesNome, gesEmail, gesCargo, gesUser, gesPass);
    }
    fclose(fp);
  }
  return (aux);
}

int limparArquivoGestores()
{
  FILE *fp;
  fp = fopen("../db/gestores.txt", "w");
  if (fp != NULL)
  {
    fclose(fp);
    return 1;
  }
  else
    return 0;
}

int guardarGestoresBinario(Gestor *inicio)
{
  FILE *fp;
  fp = fopen("../db/gestores.bin", "wb");
  if (fp != NULL)
  {
    Gestor *aux = inicio;
    while (aux != NULL)
    {
      fwrite(aux, sizeof(Gestor), 1, fp);
      aux = aux->seguinte;
    }
    fclose(fp);
    return (1);
  }
  else
    return (0);
}

Gestor *lerGestoresBinario()
{
  FILE *fp;
  Gestor *inicio = NULL;
  fp = fopen("../db/gestores.bin", "rb");
  if (fp != NULL)
  {
    Gestor g;
    while (fread(&g, sizeof(Gestor), 1, fp) == 1)
    {
      inicio = inserirGestor(inicio, g.gestorNif, g.gestorNome, g.gestorEmail, g.gestorCargo, g.gestorUsername, g.gestorPassword);
    }
    fclose(fp);
  }
  return (inicio);
}

int limparArquivoGestoresBinario()
{
  FILE *fp;
  fp = fopen("../db/gestores.bin", "wb");
  if (fp != NULL)
  {
    fclose(fp);
    return 1;
  }
  else
    return 0;
}

Gestor *inserirGestor(Gestor *inicio, int gesNif, char gesNome[], char gesEmail[], char gesCargo[], char gesUser[], char gesPass[])
{
  Gestor *novo = malloc(sizeof(struct gestorRegisto));
  if (novo != NULL)
  {
    novo->gestorNif = gesNif;
    strcpy(novo->gestorNome, gesNome);
    strcpy(novo->gestorEmail, gesEmail);
    strcpy(novo->gestorCargo, gesCargo);
    strcpy(novo->gestorUsername, gesUser);
    strcpy(novo->gestorPassword, gesPass);
    novo->seguinte = inicio;
    inicio = novo;
  }
  return inicio;
}

/** listar na consola o conteúdo da lista ligada */
void listarGestores(Gestor *inicio)
{
  while (inicio != NULL)
  {
    imprimirLinha('\xC4');
    printf("\033[1mNIF: %d\033[0m\n > Primeiro nome: %s\n > Email: %s\n > Cargo: %s\n > Username: %s\n > Password: %s\n", inicio->gestorNif, inicio->gestorNome, inicio->gestorEmail, inicio->gestorCargo, inicio->gestorUsername, inicio->gestorPassword);
    inicio = inicio->seguinte;
  }
  imprimirLinha('\xC4');
}

void listarGestorComNIF(Gestor *inicio, int gesNif)
{
    Gestor *p = inicio;
    int encontrado = 0;

    while (p != NULL)
    {
        if (p->gestorNif == gesNif)
        {
            encontrado = 1;
            printf("\033[1mNIF: %d\033[0m\n > Primeiro nome: %s\n > Email: %s\n > Cargo: %s\n > Username: %s\n > Password: %s\n", p->gestorNif, p->gestorNome, p->gestorEmail, p->gestorCargo, p->gestorUsername, p->gestorPassword);
        }
        p = p->seguinte;
    }
}

/** Determinar existência do 'codigo' na lista ligada 'inicio' */
/** devolve 1 se existir ou 0 caso contrário */
int existeGestor(Gestor *inicio, int gesNif)
{
  while (inicio != NULL)
  {
    if (inicio->gestorNif == gesNif)
      return (1);
    inicio = inicio->seguinte;
  }
  return (0);
}

/** Remover um meio a partir do seu código */
Gestor *removerGestor(Gestor *inicio, int gesNif)
{
  Gestor *anterior = inicio, *atual = inicio, *aux;

  if (atual == NULL)
    return (NULL);
  else if (atual->gestorNif == gesNif) /** remoção do 1º registo */
  {
    aux = atual->seguinte;
    free(atual);
    return (aux);
  }
  else
  {
    while ((atual != NULL) && (atual->gestorNif != gesNif))
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

Gestor *editarGestor(Gestor *inicio, int gesNif, char gesNome[], char gesEmail[], char gesCargo[], char gesUser[], char gesPass[])
{
  Gestor *aux = inicio;
  while (aux != NULL)
  {
    if (aux->gestorNif == gesNif)
    {
      if (strlen(gesNome) > 0)
        strcpy(aux->gestorNome, gesNome);
      if (strlen(gesEmail) > 0)
        strcpy(aux->gestorEmail, gesEmail);
      if (strlen(gesCargo) > 0)
        strcpy(aux->gestorCargo, gesCargo);
      if (strlen(gesUser) > 0)
        strcpy(aux->gestorUsername, gesUser);
      if (strlen(gesPass) > 0)
        strcpy(aux->gestorPassword, gesPass);
      printf("\nGestor com NIF %d editado com sucesso!\n", gesNif);
      return inicio;
    }
    aux = aux->seguinte;
  }
  printf("\nGestor com NIF %d nao encontrado!\n", gesNif);
  return inicio;
}

int validarLoginGestor(Gestor *inicio, char *gesUser, char *gesPass)
{
  Gestor *atual = inicio;

  while (atual != NULL)
  {
    if (strcmp(atual->gestorUsername, gesUser) == 0 &&
        strcmp(atual->gestorPassword, gesPass) == 0)
    {
      return 1; /** Login válido */
    }
    atual = atual->seguinte;
  }

  return 0; /** Login inválido */
}