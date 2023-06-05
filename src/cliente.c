#include <stdlib.h>
#include <string.h>
#include "../include/cliente.h"
#include "../include/tools.h"

int guardarClientesLeitura(Cliente *inicio)
{
    FILE *fp;
    fp = fopen("../db/clientesLer.txt", "w");
    if (fp != NULL)
    {
        Cliente *aux = inicio;
        while (aux != NULL)
        {
            fprintf(fp, "%d;%s;%s;%d;%s;%f;%s;%s\n", aux->clienteNif, aux->clienteNome, aux->clienteEmail, aux->clienteTelefone, aux->clienteGeocodigo, aux->clienteSaldo, aux->clienteUsername, aux->clientePassword);
            aux = aux->seguinte;
        }
        fclose(fp);
        return (1);
    }
    else
        return (0);
}

int guardarClientes(Cliente *inicio)
{
    FILE *fp;
    fp = fopen("../db/clientes.txt", "w");
    if (fp != NULL)
    {
        Cliente *aux = inicio;
        while (aux != NULL)
        {
            fprintf(fp, "%d;%[^\n];%[^\n];%d;%[^\n];%f;%[^\n];%[^\n]\n", aux->clienteNif, aux->clienteNome, aux->clienteEmail, aux->clienteTelefone, aux->clienteGeocodigo, aux->clienteSaldo, aux->clienteUsername, aux->clientePassword);
            aux = aux->seguinte;
        }
        fclose(fp);
        return 1;
    }
    else
        return 0;
}

Cliente *lerClientes()
{
    FILE *fp;
    int cliNif, cliTel;
    char cliNome[50], cliEmail[50], cliGeo[100], cliUser[50], cliPass[50];
    float cliSaldo;
    Cliente *aux = NULL;
    fp = fopen("../db/clientes.txt", "r");
    if (fp != NULL)
    {
        while (fscanf(fp, "%d;%[^\n];%[^\n];%d;%[^\n];%f;%[^\n];%[^\n]\n", &cliNif, cliNome, cliEmail, &cliTel, cliGeo, &cliSaldo, cliUser, cliPass) == 8)
        {
            aux = inserirCliente(aux, cliNif, cliNome, cliEmail, cliTel, cliGeo, cliSaldo, cliUser, cliPass);
        }
        fclose(fp);
    }
    return aux;
}

int limparArquivoClientes()
{
    FILE *fp;
    fp = fopen("../db/clientes.txt", "w");
    if (fp != NULL)
    {
        fclose(fp);
        return 1;
    }
    else
        return 0;
}

int guardarClientesBinario(Cliente *inicio)
{
    FILE *fp;
    fp = fopen("../db/clientes.bin", "wb");
    if (fp != NULL)
    {
        Cliente *aux = inicio;
        while (aux != NULL)
        {
            fwrite(aux, sizeof(Cliente), 1, fp);
            aux = aux->seguinte;
        }
        fclose(fp);
        return (1);
    }
    else
        return (0);
}

Cliente *lerClientesBinario()
{
    FILE *fp;
    Cliente *inicio = NULL;
    fp = fopen("../db/clientes.bin", "rb");
    if (fp != NULL)
    {
        Cliente c;
        while (fread(&c, sizeof(Cliente), 1, fp) == 1)
        {
            inicio = inserirCliente(inicio, c.clienteNif, c.clienteNome, c.clienteEmail, c.clienteTelefone, c.clienteGeocodigo, c.clienteSaldo, c.clienteUsername, c.clientePassword);
        }
        fclose(fp);
    }
    return (inicio);
}

int limparArquivoClientesBinario()
{
    FILE *fp;
    fp = fopen("../db/clientes.bin", "wb");
    if (fp != NULL)
    {
        fclose(fp);
        return 1;
    }
    else
        return 0;
}

/** Inserção de um novo registo de cliente */
Cliente *inserirCliente(Cliente *inicio, int cliNif, char cliNome[], char cliEmail[], int cliTel, char cliGeo[], float cliSaldo, char cliUser[], char cliPass[])
{
    Cliente *novo = malloc(sizeof(struct clienteRegisto));
    if (novo != NULL)
    {
        novo->clienteNif = cliNif;
        strcpy(novo->clienteNome, cliNome);
        strcpy(novo->clienteEmail, cliEmail);
        novo->clienteTelefone = cliTel;
        strcpy(novo->clienteGeocodigo, cliGeo);
        novo->clienteSaldo = cliSaldo;
        strcpy(novo->clienteUsername, cliUser);
        strcpy(novo->clientePassword, cliPass);
        novo->seguinte = inicio;
        inicio = novo;
    }
    return inicio;
}

/** listar na consola o conteúdo da lista ligada de clientes */
void listarClientes(Cliente *inicio)
{
    while (inicio != NULL)
    {
        imprimirLinha('\xC4');
        printf("\033[1mNIF: %d\033[0m\n > Primeiro nome: %s\n > Email: %s\n > Telemovel: %d\n > Geocodigo: %s\n > Saldo: %.2f euros\n > Username: %s\n > Password: %s\n", inicio->clienteNif, inicio->clienteNome, inicio->clienteEmail, inicio->clienteTelefone, inicio->clienteGeocodigo, inicio->clienteSaldo, inicio->clienteUsername, inicio->clientePassword);
        inicio = inicio->seguinte;
    }
    imprimirLinha('\xC4');
}

void listarClienteComNIF(Cliente *inicio, int cliNif)
{
    Cliente *p = inicio;
    int encontrado = 0;

    while (p != NULL)
    {
        if (p->clienteNif == cliNif)
        {
            encontrado = 1;
            printf("\033[1mNIF: %d\033[0m\n > Primeiro nome: %s\n > Email: %s\n > Telemovel: %d\n > Geocodigo: %s\n > Saldo: %.2f euros\n > Username: %s\n > Password: %s\n", p->clienteNif, p->clienteNome, p->clienteEmail, p->clienteTelefone, p->clienteGeocodigo, p->clienteSaldo, p->clienteUsername, p->clientePassword);
        }
        p = p->seguinte;
    }
}

/** Determinar existência do 'codigo' na lista ligada 'inicio' de clientes */
/** devolve 1 se existir ou 0 caso contrário */
int existeCliente(Cliente *inicio, int cliNif)
{
    while (inicio != NULL)
    {
        if (inicio->clienteNif == cliNif)
            return (1);
        inicio = inicio->seguinte;
    }
    return (0);
}

Cliente *procurarCliente(Cliente *inicio, int cliNif)
{
    Cliente *p = inicio;

    while (p != NULL)
    {
        if (p->clienteNif == cliNif)
        {
            return p; /** Retorna o ponteiro para o cliente encontrado */
        }
        p = p->seguinte;
    }

    return NULL; /** Retorna NULL se o cliente não for encontrado */
}

/** Remover um cliente a partir do seu código */
Cliente *removerCliente(Cliente *inicio, int cliNif)
{
    Cliente *anterior = inicio, *atual = inicio, *aux;

    if (atual == NULL)
        return (NULL);
    else if (atual->clienteNif == cliNif) /** remoção do 1º registo */
    {
        aux = atual->seguinte;
        free(atual);
        return (aux);
    }
    else
    {
        while ((atual != NULL) && (atual->clienteNif != cliNif))
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

int validarLoginCliente(Cliente *inicio, char *cliUser, char *cliPass)
{
    Cliente *atual = inicio;

    while (atual != NULL)
    {
        if (strcmp(atual->clienteUsername, cliUser) == 0 &&
            strcmp(atual->clientePassword, cliPass) == 0)
        {
            return 1; /** Login válido */
        }
        atual = atual->seguinte;
    }

    return 0; /** Login inválido */
}

Cliente *obterClientePorUsername(Cliente *clientes, char *username)
{
    Cliente *atual = clientes;
    while (atual != NULL)
    {
        if (strcmp(atual->clienteUsername, username) == 0)
        {
            return atual;
        }
        atual = atual->seguinte;
    }
    return NULL;
}

Cliente *obterClientePorNif(Cliente *clientes, int cliNif)
{
    Cliente *atual = clientes;
    while (atual != NULL)
    {
        if (atual->clienteNif == cliNif)
        {
            return atual;
        }
        atual = atual->seguinte;
    }
    return NULL;
}

Cliente *editarCliente(Cliente *inicio, int cliNif, char cliNome[], char cliEmail[], int cliTel, char cliGeo[], float cliSaldo, char cliUser[], char cliPass[])
{
    Cliente *aux = inicio;
    while (aux != NULL)
    {
        if (aux->clienteNif == cliNif)
        {
            if (strlen(cliNome) > 0)
                strcpy(aux->clienteNome, cliNome);
            if (strlen(cliEmail) > 0)
                strcpy(aux->clienteEmail, cliEmail);
            if (cliTel != -1)
                aux->clienteTelefone = cliTel;
            if (strlen(cliGeo) > 0)
                strcpy(aux->clienteGeocodigo, cliGeo);
            if (cliSaldo != -1)
                aux->clienteSaldo = cliSaldo;
            if (strlen(cliUser) > 0)
                strcpy(aux->clienteUsername, cliUser);
            if (strlen(cliPass) > 0)
                strcpy(aux->clientePassword, cliPass);
            return inicio;
        }
        aux = aux->seguinte;
    }
    return inicio;
}
