#include <stdlib.h>
#include <string.h>
#include "meio.h"

int guardarMeios(Meio* inicio)
{
    FILE* fp;
    fp = fopen("meios.txt","w");
    if (fp!=NULL)
    {
        Meio* aux= inicio;
        while (aux != NULL)
        {
            fprintf(fp,"%d;%f;%f;%s\n", aux->codigo, aux->bateria, aux->autonomia, aux->tipo);
            aux = aux->seguinte;
        }
        fclose(fp);
        return(1);
    }
    else
        return(0);
}

Meio* lerMeios()
{
    FILE* fp;
    int cod;
    float bat, aut;
    char tipo[50];
    Meio* aux=NULL;
    fp = fopen("meios.txt","r");
    if (fp!=NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp,"%d;%f;%f;%[^\n]s\n", &cod, &bat, &aut, tipo);
            aux = inserirMeio(aux, cod, tipo, bat, aut);
        }
        fclose(fp);
    }
    return(aux);
}

int guardarMeiosBinario(Meio* inicio)
{
    FILE* fp;
    fp = fopen("meios.bin","wb");
    if (fp!=NULL)
    {
        Meio* aux= inicio;
        while (aux != NULL)
        {
            fwrite(aux, sizeof(Meio), 1, fp);
            aux = aux->seguinte;
        }
        fclose(fp);
        return(1);
    }
    else
        return(0);
}

Meio* lerMeiosBinario()
{
    FILE* fp;
    Meio* inicio = NULL;
    fp = fopen("meios.bin","rb");
    if (fp!=NULL)
    {
        Meio m;
        while (fread(&m, sizeof(Meio), 1, fp) == 1)
        {
            inicio = inserirMeio(inicio, m.codigo, m.tipo, m.bateria, m.autonomia);
        }
        fclose(fp);
    }
    return(inicio);
}

// Inserção de um novo registo
Meio* inserirMeio(Meio * inicio, int cod, char tipo[], float bat, float aut)
{
  if (!existeMeio(inicio, cod)) {
  Meio * novo = malloc(sizeof(struct meio_registo));
  if (novo != NULL) {
    novo->codigo = cod;
    strcpy(novo->tipo, tipo);
    novo->bateria = bat;
    novo->seguinte = inicio;
    return(novo);
    }
  } else return(inicio);
}

// listar na consola o conteúdo da lista ligada
void listarMeios(Meio * inicio)
{while (inicio != NULL)
 {printf("%d %s %.2f %.2f\n",inicio->codigo,inicio->tipo, 
		             inicio->bateria, inicio->autonomia);
  inicio = inicio->seguinte;
 }
}

// Determinar existência do 'codigo' na lista ligada 'inicio'
// devolve 1 se existir ou 0 caso contrário
int existeMeio(Meio* inicio, int cod)
{while(inicio!=NULL)
  {if (inicio->codigo == cod) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

// Remover um meio a partir do seu código{
Meio* removerMeio(Meio* inicio, int cod) 
{
 Meio *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->codigo == cod) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->codigo!=cod)) 
  {anterior = atual;
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





