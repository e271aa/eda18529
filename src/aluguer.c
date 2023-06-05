#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "../include/aluguer.h"
#include "../include/cliente.h" /** para acessar a função existeCliente() */
#include "../include/meio.h"    /** para acessar as funções existeMeio() e editarMeio() */
#include "../include/tools.h"

int guardarAlugueres(Aluguer *inicio)
{
    FILE *fp;
    fp = fopen("../db/alugueres.txt", "w");
    if (fp != NULL)
    {
        Aluguer *aux = inicio;
        while (aux != NULL)
        {
            fprintf(fp, "%d;%d\n", aux->clienteNif, aux->meioCodigo);
            aux = aux->seguinte;
        }
        fclose(fp);
        return (1);
    }
    else
        return (0);
}

Aluguer *lerAlugueres()
{
    FILE *fp;
    int cliNif, meCod;
    Aluguer *aux = NULL;
    fp = fopen("../db/alugueres.txt", "r");
    if (fp != NULL)
    {
        while (fscanf(fp, "%d;%d\n", &cliNif, &meCod) == 2)
        {
            aux = inserirAluguer(aux, cliNif, meCod);
        }
        fclose(fp);
    }
    return (aux);
}

int guardarAlugueresBinario(Aluguer *inicio)
{
    FILE *fp;
    fp = fopen("../db/alugueres.bin", "wb");
    if (fp != NULL)
    {
        Aluguer *aux = inicio;
        while (aux != NULL)
        {
            fwrite(aux, sizeof(Aluguer), 1, fp);
            aux = aux->seguinte;
        }
        fclose(fp);
        return (1);
    }
    else
        return (0);
}

Aluguer *lerAlugueresBinario()
{
    FILE *fp;
    Aluguer *inicio = NULL;
    fp = fopen("../db/alugueres.bin", "rb");
    if (fp != NULL)
    {
        Aluguer a;
        while (fread(&a, sizeof(Aluguer), 1, fp) == 1)
        {
            inicio = inserirAluguer(inicio, a.clienteNif, a.meioCodigo);
        }
        fclose(fp);
    }
    return (inicio);
}

Aluguer *inserirAluguer(Aluguer *inicio, int cliNif, int meCod)
{
    Aluguer *novo = malloc(sizeof(struct aluguerRegisto));
    if (novo != NULL)
    {
        novo->clienteNif = cliNif;
        novo->meioCodigo = meCod;
        novo->seguinte = inicio;
        inicio = novo;
    }
    return inicio;
}

int existeAluguer(Aluguer *inicio, int cliNif, int meCod)
{
    while (inicio != NULL)
    {
        if (inicio->clienteNif == cliNif && inicio->meioCodigo == meCod)
            return (1);
        inicio = inicio->seguinte;
    }
    return (0);
}

void alugarMeio(Meio *meios, int meCod)
{
    meios = editarMeio(meios, meCod, "", -1, -1, -1, "", 1); /** define meio_alugado como 1 (alugado) */
    guardarMeios(meios);
    guardarMeiosBinario(meios);
}

int meioDisponivel(Meio *meios, int meCod)
{
    Meio *aux = meios;
    while (aux != NULL)
    {
        if (aux->meioCodigo == meCod)
        {
            if (aux->meioAlugado == 0)
                return 1; /** meio disponível */
            else
                return 0; /** meio já alugado */
        }
        aux = aux->seguinte;
    }
    return 0; /** meio não encontrado, assume não disponível */
}

void listarMeiosDisponiveis(Meio *inicio)
{
    Meio *p = inicio;
    imprimirLinha('\xC4');
    /** percorrer a lista e imprimir apenas os elementos disponíveis */
    while (p != NULL)
    {
        if (p->meioAlugado == 0)
        {
            printf("\033[1mCodigo do meio: %d\033[0m\n > Tipo de mobilidade: %s\n > Nivel da bateria: %.1f%%\n > Autonomia: %.1fkm\n > Preco por minuto: %.2f euros\n > Geocodigo: %s\n > Status: %s\n", p->meioCodigo, p->meioTipo, p->meioBateria, p->meioAutonomia, p->meioPrecoPorMinuto, p->meioGeocodigo, p->meioAlugado ? "Alugado" : "Disponivel");
            imprimirLinha('\xC4');
        }
        p = p->seguinte;
    }
}

void listarMeiosDisponiveisParaAlugar(Meio *inicio, const char *clienteGeocodigo)
{
    Meio *p = inicio;
    imprimirLinha('\xC4');
    
    /** Mostrar meios disponíveis com o mesmo geocódigo do cliente */
    while (p != NULL)
    {
        if (p->meioAlugado == 0 && strcmp(p->meioGeocodigo, clienteGeocodigo) == 0)
        {
            printf("\033[1mCodigo do meio: %d\033[0m\n > Tipo de mobilidade: %s\n > Nivel da bateria: %.1f%%\n > Autonomia: %.1fkm\n > Preco por minuto: %.2f euros\n > Geocodigo: %s\n > Status: %s\n", p->meioCodigo, p->meioTipo, p->meioBateria, p->meioAutonomia, p->meioPrecoPorMinuto, p->meioGeocodigo, p->meioAlugado ? "Alugado" : "Disponivel");
            imprimirLinha('\xC4');
        }
        p = p->seguinte;
    }
    
    /** Mostrar meios disponíveis em outras localizações */
    p = inicio;
    printf("\033[1m");
    imprimirCentrado(' ', "MEIOS DISPONIVEIS FORA DO GEOCODIGO DO CLIENTE");
    printf("\033[0m\n");
    imprimirLinha('\xC4');
    while (p != NULL)
    {
        if (p->meioAlugado == 0 && strcmp(p->meioGeocodigo, clienteGeocodigo) != 0)
        {
            printf("\033[1mCodigo do meio: %d\033[0m\n > Tipo de mobilidade: %s\n > Nivel da bateria: %.1f%%\n > Autonomia: %.1fkm\n > Preco por minuto: %.2f euros\n > Geocodigo: %s\n > Status: %s\n", p->meioCodigo, p->meioTipo, p->meioBateria, p->meioAutonomia, p->meioPrecoPorMinuto, p->meioGeocodigo, p->meioAlugado ? "Alugado" : "Disponivel");
            imprimirLinha('\xC4');
        }
        p = p->seguinte;
    }
}

int haMeiosDisponiveis(Meio *inicio)
{
    Meio *p = inicio;

    while (p != NULL)
    {
        if (p->meioAlugado == 0)
        {
            return 1;
        }
        p = p->seguinte;
    }

    return 0;
}

Aluguer *removerAluguer(Aluguer *inicio, int cliNif, int meCod)
{
    Aluguer *anterior = NULL;
    Aluguer *atual = inicio;

    while (atual != NULL)
    {
        if (atual->clienteNif == cliNif && atual->meioCodigo == meCod)
        {
            if (anterior == NULL) /** Primeiro elemento da lista */
            {
                inicio = atual->seguinte;
            }
            else
            {
                anterior->seguinte = atual->seguinte;
            }

            free(atual);
            break;
        }

        anterior = atual;
        atual = atual->seguinte;
    }

    return inicio;
}

void devolverMeio(Meio *meios, Aluguer *alugueres, Cliente *clientes, int cliNif, int meCod, int tempoUtilizacao, float distancia, char geocodigoDestino[])
{
    /** Verifica se existe um aluguer correspondente aos dados informados */
    Aluguer *atual = alugueres;
    while (atual != NULL && (atual->clienteNif != cliNif || atual->meioCodigo != meCod))
    {
        atual = atual->seguinte;
    }

    /** Se encontrou um aluguer correspondente, remove-o da lista e atualiza o meio */
    if (atual != NULL)
    {
        Meio *meio = obterMeioPorCodigo(meios, meCod);
        float autonomiaAtual = meio->meioAutonomia;
        float bateriaAtual = meio->meioBateria;
        float precoPorMinuto = meio->meioPrecoPorMinuto;

        Cliente *cliente = obterClientePorNif(clientes, cliNif);
        float saldoAtual = cliente->clienteSaldo;

        float novaAutonomia = autonomiaAtual - distancia;

        if (novaAutonomia < 0)
        {
            printf("\n\033[31mA autonomia atual nao e suficiente para o tempo de utilizacao fornecido\033[0m");
            printf("\nPor favor, insira um novo valor para o tempo de utilizacao\n");
            return;
        }

        /** Calcula preço do aluguer e edita saldo do cliente */
        float precoAluguer = precoPorMinuto * tempoUtilizacao;
        float novoSaldo = saldoAtual - precoAluguer;

        if (novoSaldo < 0)
        {
            printf("\n\033[31mO saldo atual nao e suficiente para o preco do aluguer\033[31m");
            printf("\nPor favor, insira um novo valor para o tempo de utilizacao\n");
            return;
        }

        alugueres = removerAluguer(alugueres, cliNif, meCod);
        guardarAlugueres(alugueres);
        guardarAlugueresBinario(alugueres);

        float novaBateria = (bateriaAtual * novaAutonomia) / autonomiaAtual;

        meios = editarMeio(meios, meCod, "", novaBateria, novaAutonomia, -1, geocodigoDestino, 0);
        guardarMeios(meios);
        guardarMeiosBinario(meios);

        clientes = editarCliente(clientes, cliNif, "", "", -1, geocodigoDestino, novoSaldo, "", "");
        guardarClientes(clientes);
        guardarClientesBinario(clientes);

        printf("\n\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "MEIO DEVOLVIDO COM SUCESSO");
        printf("\033[0m\n");
        imprimirLinha('\xC4');

        /** Mostra as informações para o usuário */
        printf("\n\n \033[7m Informacoes do aluguer \033[0m\n");
        printf("\033[1mNIF: %d\033[0m\n > Codigo do meio: %d\n > Preco do Aluguer: %.2f euros\n > Nova Autonomia: %.1fkm\n > Saldo Atual do Cliente: %.2f euros\n", cliNif, meCod, precoAluguer, novaAutonomia, novoSaldo);
    }
}

Aluguer *procurarAluguer(Aluguer *inicio, int cliNif, int meCod)
{
    Aluguer *p = inicio;

    while (p != NULL)
    {
        if (p->clienteNif == cliNif && p->meioCodigo == meCod)
        {
            return p; /** Retorna o ponteiro para o aluguer encontrado */
        }
        p = p->seguinte;
    }

    return NULL; /** Retorna NULL se o aluguer não for encontrado */
}

Aluguer *procurarAluguerPorNIF(Aluguer *inicio, int cliNif)
{
    Aluguer *p = inicio;

    while (p != NULL)
    {
        if (p->clienteNif == cliNif)
        {
            return p; /** Retorna o ponteiro para o aluguer encontrado */
        }
        p = p->seguinte;
    }

    return NULL; /** Retorna NULL se o aluguer não for encontrado */
}

void listarMeiosPorNIF(Aluguer *alugueres, int cliNif)
{
    Aluguer *aluguer = procurarAluguerPorNIF(alugueres, cliNif);

    if (aluguer != NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("Codigo do(s) meio(s) alugado(s) pelo NIF %d:", cliNif);

        while (aluguer != NULL)
        {
            if (aluguer->seguinte == NULL)
            {
                printf("\033[7m %d \033[0m\n", aluguer->meioCodigo);
            }
            else
            {
                printf("\033[7m %d,\033[0m", aluguer->meioCodigo);
            }

            aluguer = aluguer->seguinte;
        }

        imprimirLinha('\xC4');
    }
    else
    {
        printf("Nenhum aluguer correspondente encontrado para o cliente %d.\n", cliNif);
    }
}
