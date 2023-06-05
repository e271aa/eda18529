/**
 * @file main.c
 * @brief Ficheiro principal do programa.
 *
 * Este ficheiro contém a função `main`, que é o ponto de entrada do programa.
 * Ele inclui os ficheiros de cabeçalho necessários, define constantes e variáveis,
 * e implementa a lógica principal do programa, incluindo menus e interações com o utilizador.
 */

#include <stdio.h>   /** Biblioteca padrão para entrada e saída */
#include <string.h>  /** Biblioteca padrão para manipulação de strings */
#include <stdlib.h>  /** Biblioteca padrão para alocação de memória dinâmica */
#include <windows.h> /** Biblioteca específica para o ambiente Windows */
#include <conio.h>   /** Biblioteca específica para entrada de teclado */
#include <stdbool.h> /** Biblioteca para adicionar suporte ao tipo `bool` */

#include "../include/meio.h"    /** Ficheiro de cabeçalho referente a outro arquivo de código fonte */
#include "../include/cliente.h" /** Ficheiro de cabeçalho referente a outro arquivo de código fonte */
#include "../include/gestor.h"  /** Ficheiro de cabeçalho referente a outro arquivo de código fonte */
#include "../include/aluguer.h" /** Ficheiro de cabeçalho referente a outro arquivo de código fonte */
#include "../include/tools.h"   /** Ficheiro de cabeçalho referente a outro arquivo de código fonte */
#include "../include/grafo.h"   /** Ficheiro de cabeçalho referente a outro arquivo de código fonte */

#define TECLA_CIMA 72     /** Associa a entrada 72 em ASCII code como "TECLA_CIMA" */
#define TECLA_BAIXO 80    /** Associa a entrada 80 em ASCII code como "TECLA_BAIXO" */
#define TECLA_TAB 9       /** Associa a entrada 9 em ASCII code como "TECLA_TAB" */
#define TECLA_ENTER 13    /** Associa a entrada 13 em ASCII code como "TECLA_ENTER" */
#define TECLA_ESQUERDA 75 /** Associa a entrada 75 em ASCII code como "TECLA_ESQUERDA" */
#define TECLA_DIREITA 77  /** Associa a entrada 77 em ASCII code como "TECLA_DIREITA" */
#define TECLA_ESC 27      /** Associa a entrada 27 em ASCII code como "TECLA_ESC" */
#define TECLA_G 71        /** Associa a entrada 71 em ASCII code como "TECLA_G" */
#define TECLA_g 103       /** Associa a entrada 103 em ASCII code como "TECLA_g" */
#define TECLA_1 49        /** Associa a entrada 49 em ASCII code como "TECLA_1" */
#define TECLA_2 50        /** Associa a entrada 50 em ASCII code como "TECLA_2" */
#define TECLA_3 51        /** Associa a entrada 51 em ASCII code como "TECLA_3" */
#define TECLA_4 52        /** Associa a entrada 52 em ASCII code como "TECLA_4" */
#define TECLA_5 53        /** Associa a entrada 53 em ASCII code como "TECLA_5" */
#define TECLA_6 54        /** Associa a entrada 54 em ASCII code como "TECLA_6" */
#define TECLA_7 55        /** Associa a entrada 55 em ASCII code como "TECLA_7" */
#define TECLA_8 56        /** Associa a entrada 56 em ASCII code como "TECLA_8" */
#define TECLA_9 57        /** Associa a entrada 57 em ASCII code como "TECLA_9" */

#define TAMANHO_MAXIMO_NOME_UTILIZADOR 20 /** Define o tamanho máximo da "username", que será de 20 caracteres */
#define TAMANHO_MAXIMO_PASSWORD 20        /** Define o tamanho máximo da "password", que será de 20 caracteres */

/**
 * @brief Função principal do programa.
 * @return Retorna 0 em caso de sucesso.
 */

int main()
{
    /** Variáveis de menu */
    char teclaMenu, teclaCliente, teclaGestor, teclaGerirMeio, teclaGerirCliente, teclaGerirGestor;
    int opCliente = 1, opGestor = 1, opGerirMeio = 1, opGerirCliente = 1, opGerirGestor = 1, opMenu = 1;
    int currentMenu = 0;
    Stack *menuStack = createStack(10);

    /** Variáveis de autenticação */
    char username[TAMANHO_MAXIMO_NOME_UTILIZADOR + 1] = "";
    char password[TAMANHO_MAXIMO_PASSWORD + 1] = "";

    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** @var Variável para armazenar a lista de clientes */
    Cliente *clientes = NULL;

    /** @var Variável para armazenar a lista de gestores */
    Gestor *gestores = NULL;

    /** @var Variável para armazenar a lista de alugueres */
    Aluguer *alugueres = NULL;

    loading();

    do
    {
        /** Carrega os dados dos ficheiros. */
        meios = lerMeios();
        if (meios == NULL)
        {
            meios = lerMeiosBinario();
        }
        clientes = lerClientes();
        if (clientes == NULL)
        {
            clientes = lerClientesBinario();
        }
        gestores = lerGestores();
        if (gestores == NULL)
        {
            gestores = lerGestoresBinario();
        }
        alugueres = lerAlugueres();
        if (alugueres == NULL)
        {
            alugueres = lerAlugueresBinario();
        }

        /** Exibe o menu adequado com base no valor de currentMenu. */
        if (currentMenu == 0)
        {
            menuPrincipal(opMenu);
        }
        else if (currentMenu == 1)
        {
            menuCliente(opCliente);
        }
        else if (currentMenu == 2)
        {
            menuGestor(opGestor);
        }
        else if (currentMenu == 3)
        {
            menuGerirMeio(opGerirMeio);
        }
        else if (currentMenu == 4)
        {
            menuGerirCliente(opGerirCliente);
        }
        else if (currentMenu == 5)
        {
            menuGerirGestor(opGerirGestor);
        }

        /** Processa a entrada do utilizador com base no valor de currentMenu. */
        switch (currentMenu)
        {
        case 0:
            teclaMenu = getch();
            switch (teclaMenu)
            {
            case TECLA_1:
                opMenu = 1;
                break;
            case TECLA_2:
                opMenu = 2;
                break;
            case TECLA_TAB:
            case TECLA_BAIXO:
                opMenu = opMenu == 1 ? 2 : opMenu == 2 ? 4
                                                       : 1;
                break;
            case TECLA_CIMA:
                opMenu = opMenu == 4 ? 2 : opMenu == 2 ? 1
                                                       : 4;
                break;
            case TECLA_G:
            case TECLA_g:
                opMenu = 4;
                break;
            case TECLA_ENTER:
                switch (opMenu)
                {
                case 1:
                    menuAdicionarCliente();
                    break;
                case 2:
                    login(username, password);
                    if (validarLoginCliente(clientes, username, password) || (strcmp(username, "admin") == 0 &&
                                                                              strcmp(password, "admin") == 0))
                    {
                        push(menuStack, currentMenu);
                        currentMenu = 1;
                        strcpy(username, "");
                        strcpy(password, "");
                    }
                    else
                    {

                        system("cls");
                        credenciaisInvalidas();
                        strcpy(username, "");
                        strcpy(password, "");
                    }
                    break;
                case 4:
                    login(username, password);
                    if (validarLoginGestor(gestores, username, password) || (strcmp(username, "admin") == 0 &&
                                                                             strcmp(password, "admin") == 0))
                    {
                        push(menuStack, currentMenu);
                        currentMenu = 2;
                        strcpy(username, "");
                        strcpy(password, "");
                    }
                    else
                    {
                        system("cls");
                        credenciaisInvalidas();
                        strcpy(username, "");
                        strcpy(password, "");
                    }
                    break;
                default:
                    break;
                }
                break;
            }
            break;
        case 1:
            teclaCliente = getch();
            switch (teclaCliente)
            {
            case TECLA_1:
                opCliente = 1;
                break;
            case TECLA_2:
                opCliente = 2;
                break;
            case TECLA_3:
                opCliente = 3;
                break;
            case TECLA_4:
                opCliente = 4;
                break;
            case TECLA_TAB:
            case TECLA_BAIXO:
                opCliente = opCliente == 1 ? 2 : opCliente == 2 ? 3
                                             : opCliente == 3   ? 4
                                             : opCliente == 4   ? 9
                                                                : 1;
                break;
            case TECLA_CIMA:
                opCliente = opCliente == 9 ? 4 : opCliente == 4 ? 3
                                             : opCliente == 3   ? 2
                                             : opCliente == 2   ? 1
                                                                : 9;
                break;
            case TECLA_9:
                opCliente = 9;
            case TECLA_ENTER:
                if (opCliente == 1)
                {
                    menuListarMeiosDisponiveis();
                }
                if (opCliente == 2)
                {
                    menuAlugarMeio();
                }
                if (opCliente == 3)
                {
                    menuDevolverMeio();
                }
                if (opCliente == 4)
                {
                    login(username, password);
                    if (validarLoginCliente(clientes, username, password))
                    {
                        char loggedInUser[50];
                        strcpy(loggedInUser, username);
                        menuCarregarSaldo(loggedInUser);
                        strcpy(username, "");
                        strcpy(password, "");
                    }
                    else
                    {

                        system("cls");
                        credenciaisInvalidas();
                        strcpy(username, "");
                        strcpy(password, "");
                    }
                    break;
                }
                if (opCliente == 9)
                {
                    currentMenu = pop(menuStack);
                    currentMenu = (currentMenu < 0) ? 0 : currentMenu; /** Limita o valor mínimo de currentMenu em 0 */
                    continue;
                }
                break;
            default:
                break;
            }
            break;
        case 2:
            teclaGestor = getch();
            switch (teclaGestor)
            {
            case TECLA_1:
                opGestor = 1;
                break;
            case TECLA_2:
                opGestor = 2;
                break;
            case TECLA_3:
                opGestor = 3;
                break;
            case TECLA_TAB:
            case TECLA_BAIXO:
                opGestor = opGestor == 1 ? 2 : opGestor == 2 ? 3
                                           : opGestor == 3   ? 9
                                                             : 1;
                break;
            case TECLA_CIMA:
                opGestor = opGestor == 9 ? 3 : opGestor == 3 ? 2
                                           : opGestor == 2   ? 1
                                                             : 9;
                break;
            case TECLA_9:
                opGestor = 9;
            case TECLA_ENTER:
                switch (opGestor)
                {
                case 1:
                    push(menuStack, currentMenu);
                    currentMenu = 3;
                    break;
                case 2:
                    push(menuStack, currentMenu);
                    currentMenu = 4;
                    break;
                case 3:
                    push(menuStack, currentMenu);
                    currentMenu = 5;
                    break;
                case 9:
                    currentMenu = pop(menuStack);
                    currentMenu = (currentMenu < 0) ? 0 : currentMenu; /** Limita o valor mínimo de currentMenu em 0 */
                    continue;
                }
                break;
            default:
                break;
            }
            break;
        case 3:
            teclaGerirMeio = getch();
            /** Menu gerir meio */
            switch (teclaGerirMeio)
            {
            case TECLA_1:
                opGerirMeio = 1;
                break;
            case TECLA_2:
                opGerirMeio = 2;
                break;
            case TECLA_3:
                opGerirMeio = 3;
                break;
            case TECLA_4:
                opGerirMeio = 4;
                break;
            case TECLA_5:
                opGerirMeio = 5;
                break;
            case TECLA_6:
                opGerirMeio = 6;
                break;
            case TECLA_TAB:
            case TECLA_BAIXO:
                opGerirMeio = opGerirMeio == 1 ? 2 : opGerirMeio == 2 ? 3
                                                 : opGerirMeio == 3   ? 4
                                                 : opGerirMeio == 4   ? 5
                                                 : opGerirMeio == 5   ? 6
                                                 : opGerirMeio == 6   ? 9
                                                                      : 1;
                break;
            case TECLA_CIMA:
                opGerirMeio = opGerirMeio == 9 ? 6 : opGerirMeio == 6 ? 5
                                                 : opGerirMeio == 5   ? 4
                                                 : opGerirMeio == 4   ? 3
                                                 : opGerirMeio == 3   ? 2
                                                 : opGerirMeio == 2   ? 1
                                                                      : 9;
                break;
            case TECLA_9:
                opGerirMeio = 9;
            case TECLA_ENTER:
                switch (opGerirMeio)
                {
                case 1: /** Inserir meio */
                    menuAdicionarMeio();
                    break;
                case 2: /** Remover meio */
                    menuRemoverMeio();
                    break;
                case 3: /** Remover todos os meios */
                    menuRemoverTodosMeios();
                    break;
                case 4: /** Editar meios */
                    menuEditarMeio();
                    break;
                case 5: /** Listar meios */
                    menuListarMeio();
                    break;
                case 6: /** Listar meios por ordem decrescente de autonomia */
                    menuListarAutonomiaMeio();
                    break;
                case 9:
                    currentMenu = pop(menuStack);
                    continue;
                }
                break;
            default:
                break;
            }
            break;
        case 4:
            teclaGerirCliente = getch();
            /** Menu gerir cliente */
            switch (teclaGerirCliente)
            {
            case TECLA_1:
                opGerirCliente = 1;
                break;
            case TECLA_2:
                opGerirCliente = 2;
                break;
            case TECLA_3:
                opGerirCliente = 3;
                break;
            case TECLA_4:
                opGerirCliente = 4;
                break;
            case TECLA_5:
                opGerirCliente = 5;
                break;
            case TECLA_TAB:
            case TECLA_BAIXO:
                opGerirCliente = opGerirCliente == 1 ? 2 : opGerirCliente == 2 ? 3
                                                       : opGerirCliente == 3   ? 4
                                                       : opGerirCliente == 4   ? 5
                                                       : opGerirCliente == 5   ? 9
                                                                               : 1;
                break;
            case TECLA_CIMA:
                opGerirCliente = opGerirCliente == 9 ? 5 : opGerirCliente == 5 ? 4
                                                       : opGerirCliente == 4   ? 3
                                                       : opGerirCliente == 3   ? 2
                                                       : opGerirCliente == 2   ? 1
                                                                               : 9;
                break;
            case TECLA_9:
                opGerirCliente = 9;
            case TECLA_ENTER:
                switch (opGerirCliente)
                {
                case 1: /** Inserir cliente */
                    menuAdicionarCliente();
                    break;
                case 2: /** Remover cliente */
                    menuRemoverCliente();
                    break;
                case 3: /** Remover todos os clientes */
                    menuRemoverTodosClientes();
                    break;
                case 4: /** Editar clientes */
                    menuEditarCliente();
                    break;
                case 5: /** Listar clientes */
                    menuListarCliente();
                    break;
                case 9:
                    currentMenu = pop(menuStack);
                    continue;
                }
                break;
            default:
                break;
            }
            break;
        case 5:
            teclaGerirGestor = getch();
            /** Menu gerir gestor */
            switch (teclaGerirGestor)
            {
            case TECLA_1:
                opGerirGestor = 1;
                break;
            case TECLA_2:
                opGerirGestor = 2;
                break;
            case TECLA_3:
                opGerirGestor = 3;
                break;
            case TECLA_4:
                opGerirGestor = 4;
                break;
            case TECLA_5:
                opGerirGestor = 5;
                break;
            case TECLA_TAB:
            case TECLA_BAIXO:
                opGerirGestor = opGerirGestor == 1 ? 2 : opGerirGestor == 2 ? 3
                                                     : opGerirGestor == 3   ? 4
                                                     : opGerirGestor == 4   ? 5
                                                     : opGerirGestor == 5   ? 9
                                                                            : 1;
                break;
            case TECLA_CIMA:
                opGerirGestor = opGerirGestor == 9 ? 5 : opGerirGestor == 5 ? 4
                                                     : opGerirGestor == 4   ? 3
                                                     : opGerirGestor == 3   ? 2
                                                     : opGerirGestor == 2   ? 1
                                                                            : 9;
                break;
            case TECLA_9:
                opGerirGestor = 9;
            case TECLA_ENTER:
                switch (opGerirGestor)
                {
                case 1: /** Inserir gestor */
                    menuAdicionarGestor();
                    break;
                case 2: /** Remover gestor */
                    menuRemoverGestor();
                    break;

                case 3: /** Remover todos os gestores */
                    menuRemoverTodosGestores();
                    break;
                case 4: /** Editar gestores */
                    menuEditarGestor();
                    break;
                case 5: /** Listar gestores */
                    menuListarGestor();
                    break;
                case 9:
                    currentMenu = pop(menuStack);
                    continue;
                }
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    } while (teclaMenu != TECLA_ESC && teclaCliente != TECLA_ESC && teclaGestor != TECLA_ESC && teclaGerirMeio != TECLA_ESC && teclaGerirCliente != TECLA_ESC && teclaGerirGestor != TECLA_ESC);

    free(menuStack->array);
    free(menuStack);

    return 0;
}