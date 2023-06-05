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

bool exitLoop = false;

Stack *createStack(int capacity)
{
    Stack *stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(capacity * sizeof(int));
    return stack;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

//////////////////////////////////////////////////////

void menuCriarGrafo()
{
    Grafo *grafo = criarGrafo();

    Vertice *vertice1 = criarVertice("///davam.nele.solda");             /** BRAGA PARQUE */
    Vertice *vertice2 = criarVertice("///alpinos.contributivo.cintila"); /** SAMEIRO BRAGA */
    Vertice *vertice3 = criarVertice("///facial.jogam.chame");           /** CHAFARIZ DA AVENIDADA */
    Vertice *vertice4 = criarVertice("///pediu.flui.bica");              /** HOSPITAL DE BRAGA */
    Vertice *vertice5 = criarVertice("///redor.olhe.atol");              /** MINHO CENTER */
    Vertice *vertice6 = criarVertice("///massas.faixa.selos");           /** UNIVERSIDADE DO MINHO */
    Vertice *vertice7 = criarVertice("///idosa.fraca.jogamos");          /** MCDONALDS UM */
    Vertice *vertice8 = criarVertice("///merece.irem.alcancei");         /** JARDIM SANTA BARBARA */
    Vertice *vertice9 = criarVertice("///lesmas.chorar.folga");          /** PARQUE DA PONTE */
    Vertice *vertice10 = criarVertice("///redor.belo.ligam");            /** BOM JESUS */
    Vertice *vertice11 = criarVertice("///sulcar.desfastio.adubar");     /** IPCA BRAGA */

    adicionarVertice(grafo, vertice1);
    adicionarVertice(grafo, vertice2);
    adicionarVertice(grafo, vertice3);
    adicionarVertice(grafo, vertice4);
    adicionarVertice(grafo, vertice5);
    adicionarVertice(grafo, vertice6);
    adicionarVertice(grafo, vertice7);
    adicionarVertice(grafo, vertice8);
    adicionarVertice(grafo, vertice9);
    adicionarVertice(grafo, vertice10);
    adicionarVertice(grafo, vertice11);

    /** Arestas para o vértice "///davam.nele.solda" (Braga Parque) */
    criarAresta(grafo, "///davam.nele.solda", "///alpinos.contributivo.cintila", 5.8);
    criarAresta(grafo, "///davam.nele.solda", "///facial.jogam.chame", 2.7);
    criarAresta(grafo, "///davam.nele.solda", "///pediu.flui.bica", 1.3);
    criarAresta(grafo, "///davam.nele.solda", "///redor.olhe.atol", 3.5);
    criarAresta(grafo, "///davam.nele.solda", "///massas.faixa.selos", 1.2);
    criarAresta(grafo, "///davam.nele.solda", "///idosa.fraca.jogamos", 1.7);
    criarAresta(grafo, "///davam.nele.solda", "///merece.irem.alcancei", 3);
    criarAresta(grafo, "///davam.nele.solda", "///lesmas.chorar.folga", 3.2);
    criarAresta(grafo, "///davam.nele.solda", "///redor.belo.ligam", 5.4);
    criarAresta(grafo, "///davam.nele.solda", "///sulcar.desfastio.adubar", 3.4);

    /** Arestas para o vértice "///alpinos.contributivo.cintila" (Sameiro Braga) */
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///facial.jogam.chame", 8.8);
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///pediu.flui.bica", 7.4);
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///redor.olhe.atol", 6.3);
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///massas.faixa.selos", 5.9);
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///idosa.fraca.jogamos", 5.8);
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///merece.irem.alcancei", 9.3);
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///lesmas.chorar.folga", 8.5);
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///redor.belo.ligam", 2.4);
    criarAresta(grafo, "///alpinos.contributivo.cintila", "///sulcar.desfastio.adubar", 8.4);

    /** Arestas para o vértice "///facial.jogam.chame" (Chafariz da Avenida) */
    criarAresta(grafo, "///facial.jogam.chame", "///pediu.flui.bica", 3.2);
    criarAresta(grafo, "///facial.jogam.chame", "///redor.olhe.atol", 3.9);
    criarAresta(grafo, "///facial.jogam.chame", "///massas.faixa.selos", 2.6);
    criarAresta(grafo, "///facial.jogam.chame", "///idosa.fraca.jogamos", 2.9);
    criarAresta(grafo, "///facial.jogam.chame", "///merece.irem.alcancei", 0.35);
    criarAresta(grafo, "///facial.jogam.chame", "///lesmas.chorar.folga", 1.5);
    criarAresta(grafo, "///facial.jogam.chame", "///redor.belo.ligam", 6.7);
    criarAresta(grafo, "///facial.jogam.chame", "///sulcar.desfastio.adubar", 1.6);

    /** Arestas para o vértice "///pediu.flui.bica" (Hospital de Braga) */
    criarAresta(grafo, "///pediu.flui.bica", "///redor.olhe.atol", 4.5);
    criarAresta(grafo, "///pediu.flui.bica", "///massas.faixa.selos", 1.3);
    criarAresta(grafo, "///pediu.flui.bica", "///idosa.fraca.jogamos", 2.3);
    criarAresta(grafo, "///pediu.flui.bica", "///merece.irem.alcancei", 3.5);
    criarAresta(grafo, "///pediu.flui.bica", "///lesmas.chorar.folga", 4.8);
    criarAresta(grafo, "///pediu.flui.bica", "///redor.belo.ligam", 6);
    criarAresta(grafo, "///pediu.flui.bica", "///sulcar.desfastio.adubar", 5);

    /** Arestas para o vértice "///redor.olhe.atol" (Minho Center) */
    criarAresta(grafo, "///redor.olhe.atol", "///massas.faixa.selos", 2.8);
    criarAresta(grafo, "///redor.olhe.atol", "///idosa.fraca.jogamos", 2.7);
    criarAresta(grafo, "///redor.olhe.atol", "///merece.irem.alcancei", 3.8);
    criarAresta(grafo, "///redor.olhe.atol", "///lesmas.chorar.folga", 2.5);
    criarAresta(grafo, "///redor.olhe.atol", "///redor.belo.ligam", 4.4);
    criarAresta(grafo, "///redor.olhe.atol", "///sulcar.desfastio.adubar", 3);

    /** Arestas para o vértice "///massas.faixa.selos" (Universidade do Minho) */
    criarAresta(grafo, "///massas.faixa.selos", "///idosa.fraca.jogamos", 0.6);
    criarAresta(grafo, "///massas.faixa.selos", "///merece.irem.alcancei", 3.9);
    criarAresta(grafo, "///massas.faixa.selos", "///lesmas.chorar.folga", 3.1);
    criarAresta(grafo, "///massas.faixa.selos", "///redor.belo.ligam", 4.3);
    criarAresta(grafo, "///massas.faixa.selos", "///sulcar.desfastio.adubar", 3.3);

    /** Arestas para o vértice "///idosa.fraca.jogamos" (McDonald's Um) */
    criarAresta(grafo, "///idosa.fraca.jogamos", "///merece.irem.alcancei", 3.8);
    criarAresta(grafo, "///idosa.fraca.jogamos", "///lesmas.chorar.folga", 2.9);
    criarAresta(grafo, "///idosa.fraca.jogamos", "///redor.belo.ligam", 4.1);
    criarAresta(grafo, "///idosa.fraca.jogamos", "///sulcar.desfastio.adubar", 3.1);

    /** Arestas para o vértice "///merece.irem.alcancei" (Jardim Santa Barbara) */
    criarAresta(grafo, "///merece.irem.alcancei", "///lesmas.chorar.folga", 1.4);
    criarAresta(grafo, "///merece.irem.alcancei", "///redor.belo.ligam", 6.9);
    criarAresta(grafo, "///merece.irem.alcancei", "///sulcar.desfastio.adubar", 1.6);

    /** Arestas para o vértice "///lesmas.chorar.folga" (Parque da Ponte) */
    criarAresta(grafo, "///lesmas.chorar.folga", "///redor.belo.ligam", 6);
    criarAresta(grafo, "///lesmas.chorar.folga", "///sulcar.desfastio.adubar", 0.45);

    /** Aresta para o vértice "///redor.belo.ligam" (Bom Jesus) */
    criarAresta(grafo, "///redor.belo.ligam", "///sulcar.desfastio.adubar", 7.3);

    guardarGrafo(grafo, "../db/grafo.txt");
    guardarGrafoBinario(grafo, "../db/grafo.bin");
}

//////////////////////////////////////////////////////

/**
 * @brief Imprime uma linha horizontal com o caractere especificado.
 *
 * @param c O caractere a ser utilizado na linha.
 */

void imprimirLinha(char c)
{
    int larguraJanela;

#ifdef _WIN32
    /** Obtém as informações do buffer de tela do console no Windows */
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    larguraJanela = csbi.srWindow.Right - csbi.srWindow.Left;
#else
    /** Obtém o tamanho da janela do terminal no Linux/Mac */
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    larguraJanela = w.ws_col;
#endif
    /** Imprime o caractere especificado para preencher a largura da janela */
    for (int i = 0; i < larguraJanela; i++)
    {
        printf("%c", c);
    }
    printf("\n");
}

/**
 * @brief Imprime uma sequência do caractere especificado para uma largura de janela específica.
 *
 * @param c O caractere a ser impresso.
 */

void imprimirCoisas(char c)
{
    int larguraJanela;

#ifdef _WIN32
    /** Obtém as informações do buffer de tela do console no Windows */
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    larguraJanela = csbi.srWindow.Right - csbi.srWindow.Left;
#else
    /** Obtém o tamanho da janela do terminal no Linux/Mac */
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    larguraJanela = w.ws_col;
#endif
    /** Divide a largura da janela por 4 */
    larguraJanela /= 4;
    /** Imprime o caractere especificado para preencher 1/4 da largura da janela */
    for (int i = 0; i < larguraJanela; i++)
    {
        printf("%c", c);
    }
}

/**
 * @brief Imprime um texto centralizado entre caracteres especificados.
 *
 * @param c O caractere a ser utilizado ao redor do texto.
 * @param texto O texto a ser impresso.
 */

void imprimirCentrado(char c, const char *texto)
{
    int larguraJanela;

#ifdef _WIN32
    /** Obtém as informações do buffer de tela do console no Windows */
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    larguraJanela = csbi.srWindow.Right - csbi.srWindow.Left;
#else
    /** Obtém o tamanho da janela do terminal no Linux/Mac */
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    larguraJanela = w.ws_col;
#endif
    /** Calcula o número de caracteres no texto */
    int caracteresTexto = strlen(texto);
    /** Reduz a largura da janela pelo número de caracteres do texto */
    larguraJanela -= caracteresTexto;
    /** Divide a largura restante por 2 para centralizar o texto */
    larguraJanela /= 2;
    /** Imprime o caractere especificado para preencher a metade da largura da janela */
    for (int i = 0; i < larguraJanela; i++)
    {
        printf("%c", c);
    }

    printf("%s", texto);
}

/**
 * @brief Imprime espaços em branco antes da string para ajustar o tamanho total.
 *
 * @param str A string para a qual os espaços serão adicionados.
 */

void imprimeEspacos(char *str)
{
    int num_caracteres = strlen(str);      /** calcula o número de caracteres na string */
    int num_espacos = 26 - num_caracteres; /** calcula o número de espaços necessários para completar 22 caracteres */
    if (num_espacos > 0)                   /** se houver espaços a serem adicionados */
    {
        printf("%*s", num_espacos, ""); /** imprime os espaços em branco antes da string */
    }
}

//////////////////////////////////////////////////////

/**
 * @brief Solicita ao usuário uma entrada de número decimal (float) com confirmação.
 *
 * @param prompt A mensagem de prompt exibida ao usuário.
 * @param exitLoop Ponteiro para uma variável booleana que controla a saída do loop principal.
 * @return O valor float inserido pelo usuário.
 */

float floatConfirmacao(const char *prompt, bool *exitLoop)
{
    char input[50];
    float value;
    int result;
    char ch;

    do
    {
        printf("%s", prompt);
        scanf("%s", input);

        if (strcmp(input, "SAIR") == 0)
        {
            *exitLoop = true;
            break;
        }

        result = sscanf(input, "%f", &value);

        // Limpa o buffer de entrada
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        if (result != 1)
        {
            printf(" \033[2m(A entrada contem caracteres invalidos. Insira apenas numeros)\033[0m\n");
        }
    } while (result != 1);

    return value;
}

// float floatConfirmacao(const char *prompt, bool *exitLoop)
// {
//     char input[50]; /** Array para armazenar a entrada do usuário */
//     float value;    /** Variável para armazenar o valor float convertido da entrada */
//     int result;     /** Variável para armazenar o resultado da função sscanf */
//     char ch;        /** Variável temporária para limpar o buffer de entrada */

//     do
//     {
//         printf("%s", prompt); /** Exibe o prompt para o usuário */
//         scanf("%s", input);   /** Lê a entrada do usuário como uma string */

//         if (strcmp(input, "SAIR") == 0)
//         {
//             *exitLoop = true; /** Define a variável de controle de loop como true para sair do loop principal */
//             break;
//         }

//         result = sscanf(input, "%f", &value); /** Converte a entrada em um valor float e armazena em 'value' */

//         /** Limpa o buffer de entrada */
//         while ((ch = getchar()) != '\n' && ch != EOF)
//             ;

//         if (result != 1) /** Verifica se a conversão foi bem-sucedida */
//         {
//             printf(" \033[2m(A entrada contem caracteres invalidos. Insira apenas numeros)\033[0m\n");
//         }
//     } while (result != 1); /** Repete o loop até que a conversão seja bem-sucedida */

//     return value; /** Retorna o valor float inserido pelo usuário */
// }

/**
 * @brief Solicita ao usuário uma entrada de número inteiro (int) com confirmação.
 *
 * @param prompt A mensagem de prompt exibida ao usuário.
 * @param exitLoop Ponteiro para uma variável booleana que controla a saída do loop principal.
 * @return O valor int inserido pelo usuário.
 */

int intConfirmacao(const char *prompt, bool *exitLoop)
{
    char input[50];
    int value;
    int result;
    char ch;

    do
    {
        printf("%s", prompt);
        scanf("%s", input);

        if (strcmp(input, "SAIR") == 0)
        {
            *exitLoop = true;
            break; // Sai do loop imediatamente
        }

        result = sscanf(input, "%d", &value);

        // Limpa o buffer de entrada
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;

        if (result == 0)
        {
            printf(" \033[2m(A entrada contem caracteres invalidos. Insira apenas numeros)\033[0m\n");
        }
    } while (result == 0);

    return value;
}

// int intConfirmacao(const char *prompt, bool *exitLoop)
// {
//     char input[50]; /** Array para armazenar a entrada do usuário */
//     float value;    /** Variável para armazenar o valor int convertido da entrada */
//     int result;     /** Variável para armazenar o resultado da função sscanf */
//     char ch;        /** Variável temporária para limpar o buffer de entrada */

//     do
//     {
//         printf("%s", prompt); /** Exibe o prompt para o usuário */
//         scanf("%s", input);   /** Lê a entrada do usuário como uma string */

//         if (strcmp(input, "SAIR") == 0)
//         {
//             *exitLoop = true; /** Define a variável de controle de loop como true para sair do loop principal */
//             break;
//         }

//         result = sscanf(input, "%d", &value); /** Converte a entrada em um valor int e armazena em 'value' */

//         /** Limpa o buffer de entrada */
//         while ((ch = getchar()) != '\n' && ch != EOF)
//             ;

//         if (result == 0) /** Verifica se a conversão foi bem-sucedida */
//         {
//             printf(" \033[2m(A entrada contem caracteres invalidos. Insira apenas numeros)\033[0m\n");
//         }
//     } while (result == 0); /** Repete o loop até que a conversão seja bem-sucedida */

//     return value; /** Retorna o valor int inserido pelo usuário */
// }

//////////////////////////////////////////////////////

void loading()
{
    /** Imprime uma mensagem de boas-vindas com o nome da empresa em verde */
    printf("\033[32m\n\n\n\n\n\n\n\t\t\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4 Bem-vindo(a) a GreenGo! \xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\033[0m\n");

    /** Imprime uma mensagem explicando o que a empresa faz */
    printf("\n\n\nA GreenGo e uma empresa de mobilidade eletrica que oferece solucoes de transporte sustentavel para pessoas e empresas. \nCom a nossa frota de veiculos eletricos, ajudamos a reduzir as emissoes de CO2 e a preservar o meio ambiente.\n\n\n");

    /** Imprime uma mensagem de direitos autorais */
    printf("2023 - Todos os direitos reservados\n\n\n\n");

    /** Oculta o cursor */
    printf("\e[?25l");

    /** Inicialize a variável "tempo" com 0 */
    int tempo = 0;

    /** Execute o loop do sleep até que 10 segundos sejam alcançados ou o utilizador pressione uma tecla */
    while (tempo < 10000 && !kbhit())
    {
        /** Calcule a porcentagem do progresso atual */
        float progress = (float)tempo / 10000.0f;

        /** Imprima a barra de progresso correspondente ao progresso atual */
        printf("\r\t\t\t\t    ");
        int barWidth = 40;
        int pos = (int)(progress * barWidth);
        for (int i = 0; i < barWidth; i++)
        {
            if (i < pos)
                printf("\033[42m \033[0m"); /** Imprime o símbolo '#' em verde para indicar o progresso */
            else if (i == pos)
                printf("\033[42m \033[0m"); /** Imprime uma seta '>' em branco para indicar a direção da barra de progresso */
            else
                printf("\033[47m \033[0m"); /** Imprime um espaço em branco para indicar a parte restante da barra de progresso */
        }
        printf(" %d%%", (int)(progress * 100)); /** Imprime a porcentagem atual do progresso */

        fflush(stdout); /** Força a impressão imediata na tela */
        Sleep(100);     /** Aguarda 100 milissegundos de cada vez */
        tempo += 100;   /** Atualiza o tempo decorrido */
    }

    /** Limpa o buffer do teclado */
    if (kbhit())
    {
        _getch();
    }

    /** Limpa a tela */
    system("cls"); /** Limpa o ecrã do console */
}

//////////////////////////////////////////////////////

/**
 * @brief Função que exibe o menu principal.
 *
 * @param opMenu A opção selecionada no menu.
 */

void menuPrincipal(int opMenu)
{
    int i;
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("%c", '\xDA');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xBF');
    imprimirCoisas(' ');
    printf("\xB3                          \033[32mGreenGo\033[0m                          \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("\xB3  %s                    \xB3\n", opMenu == 1 ? "\033[2m>\033[0m  1. Criar uma nova conta de cliente" : "   \033[2m1. Criar uma nova conta de cliente\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                     \xB3\n", opMenu == 2 ? "\033[2m>\033[0m  2. Iniciar sessao com a sua conta" : "   \033[2m2. Iniciar sessao com a sua conta\033[0m");
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("\xB3        %s        \xB3\n", opMenu == 4 ? "Pressione G para iniciar sessao como gestor" : "\033[2mPressione G para iniciar sessao como gestor\033[0m");
    imprimirCoisas(' ');
    printf("\xB3                  \033[31mPressione ESC para sair\033[0m                  \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC0');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xD9');
    printf("\e[?25l"); /** Oculta o cursor */
}

/**
 * @brief Função que exibe o menu do cliente.
 *
 * @param opCliente A opção selecionada no menu.
 */

void menuCliente(int opCliente)
{
    int i;
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("%c", '\xDA');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xBF');
    imprimirCoisas(' ');
    printf("\xB3                          \033[32mGreenGo\033[0m                          \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("\xB3  %s                           \xB3\n", opCliente == 1 ? "\033[2m>\033[0m  1. Listar meios disponiveis" : "   \033[2m1. Listar meios disponiveis\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                          \xB3\n", opCliente == 2 ? "\033[2m>\033[0m  2. Alugar meio de transporte" : "   \033[2m2. Alugar meio de transporte\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                        \xB3\n", opCliente == 3 ? "\033[2m>\033[0m  3. Devolver meio de transporte" : "   \033[2m3. Devolver meio de transporte\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                  \xB3\n", opCliente == 4 ? "\033[2m>\033[0m  4. Carregar saldo na conta cliente \033[2m*\033[0m" : "   \033[2m4. Carregar saldo na conta cliente \033[2m*\033[0m\033[0m");
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("\xB3             %s              \xB3\n", opCliente == 9 ? "Pressione 9 para terminar sessao" : "\033[2mPressione 9 para terminar sessao\033[0m");
    imprimirCoisas(' ');
    printf("\xB3                  \033[31mPressione ESC para sair\033[0m                  \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC0');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xD9');
    printf("\e[?25l"); /** Oculta o cursor */
    printf("\n\n\t\033[2m* E necessario efetuar o login para prosseguir com esta operacao\033[0m\n");
}

/**
 * @brief Função que exibe o menu do gestor.
 *
 * @param opGestor A opção selecionada no menu.
 */

void menuGestor(int opGestor)
{
    int i;
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("%c", '\xDA');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xBF');
    imprimirCoisas(' ');
    printf("\xB3                          \033[32mGreenGo\033[0m                          \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("\xB3  %s                  \xB3\n", opGestor == 1 ? "\033[2m>\033[0m  1. Gerir meio de mobilidade eletrica" : "   \033[2m1. Gerir meio de mobilidade eletrica\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                                      \xB3\n", opGestor == 2 ? "\033[2m>\033[0m  2. Gerir cliente" : "   \033[2m2. Gerir cliente\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                                       \xB3\n", opGestor == 3 ? "\033[2m>\033[0m  3. Gerir gestor" : "   \033[2m3. Gerir gestor\033[0m");
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("\xB3             %s              \xB3\n", opGestor == 9 ? "Pressione 9 para terminar sessao" : "\033[2mPressione 9 para terminar sessao\033[0m");
    imprimirCoisas(' ');
    printf("\xB3                  \033[31mPressione ESC para sair\033[0m                  \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC0');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xD9');
    printf("\e[?25l"); /** Oculta o cursor */
}

/**
 * @brief Função que exibe o menu de gerir meio de transporte.
 *
 * @param opGerirMeio A opção selecionada no menu.
 */

void menuGerirMeio(int opGerirMeio)
{
    int i;
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("%c", '\xDA');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xBF');
    imprimirCoisas(' ');
    printf("\xB3            \033[32mGerir meios de mobilidade eletrica\033[0m             \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("\xB3  %s                                     \xB3\n", opGerirMeio == 1 ? "\033[2m>\033[0m  1. Adicionar Meio" : "   \033[2m1. Adicionar Meio\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                                       \xB3\n", opGerirMeio == 2 ? "\033[2m>\033[0m  2. Remover Meio" : "   \033[2m2. Remover Meio\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                             \xB3\n", opGerirMeio == 3 ? "\033[2m>\033[0m  3. Remover Todos os Meios" : "   \033[2m3. Remover Todos os Meios\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                                        \xB3\n", opGerirMeio == 4 ? "\033[2m>\033[0m  4. Editar Meio" : "   \033[2m4. Editar Meio\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                              \xB3\n", opGerirMeio == 5 ? "\033[2m>\033[0m  5. Listar Todos os Meios" : "   \033[2m5. Listar Todos os Meios\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s    \xB3\n", opGerirMeio == 6 ? "\033[2m>\033[0m  6. Listar Meios por ordem decrescente de autonomia" : "   \033[2m6. Listar Meios por ordem decrescente de autonomia\033[0m");
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("\xB3        %s         \xB3\n", opGerirMeio == 9 ? "Pressione 9 para regressar a tela anterior" : "\033[2mPressione 9 para regressar a tela anterior\033[0m");
    imprimirCoisas(' ');
    printf("\xB3                  \033[31mPressione ESC para sair\033[0m                  \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC0');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xD9');
    printf("\e[?25l"); /** Oculta o cursor */
}

/**
 * @brief Função que exibe o menu de gerir cliente.
 *
 * @param opGerirCliente A opção selecionada no menu.
 */

void menuGerirCliente(int opGerirCliente)
{
    int i;
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("%c", '\xDA');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xBF');
    imprimirCoisas(' ');
    printf("\xB3                      \033[32mGerir clientes\033[0m                       \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("\xB3  %s                                  \xB3\n", opGerirCliente == 1 ? "\033[2m>\033[0m  1. Adicionar Cliente" : "   \033[2m1. Adicionar Cliente\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                                    \xB3\n", opGerirCliente == 2 ? "\033[2m>\033[0m  2. Remover Cliente" : "   \033[2m2. Remover Cliente\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                          \xB3\n", opGerirCliente == 3 ? "\033[2m>\033[0m  3. Remover Todos os Clientes" : "   \033[2m3. Remover Todos os Clientes\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                                     \xB3\n", opGerirCliente == 4 ? "\033[2m>\033[0m  4. Editar Cliente" : "   \033[2m4. Editar Cliente\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                           \xB3\n", opGerirCliente == 5 ? "\033[2m>\033[0m  5. Listar Todos os Clientes" : "   \033[2m5. Listar Todos os Clientes\033[0m");
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("\xB3        %s         \xB3\n", opGerirCliente == 9 ? "Pressione 9 para regressar a tela anterior" : "\033[2mPressione 9 para regressar a tela anterior\033[0m");
    imprimirCoisas(' ');
    printf("\xB3                  \033[31mPressione ESC para sair\033[0m                  \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC0');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xD9');
    printf("\e[?25l"); /** Oculta o cursor */
}

/**
 * @brief Função que exibe o menu de gerir gestor.
 *
 * @param opGerirGestor A opção selecionada no menu.
 */

void menuGerirGestor(int opGerirGestor)
{
    int i;
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("%c", '\xDA');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xBF');
    imprimirCoisas(' ');
    printf("\xB3                      \033[32mGerir gestores\033[0m                       \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("\xB3  %s                                   \xB3\n", opGerirGestor == 1 ? "\033[2m>\033[0m  1. Adicionar Gestor" : "   \033[2m1. Adicionar Gestor\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                                     \xB3\n", opGerirGestor == 2 ? "\033[2m>\033[0m  2. Remover Gestor" : "   \033[2m2. Remover Gestor\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                          \xB3\n", opGerirGestor == 3 ? "\033[2m>\033[0m  3. Remover Todos os Gestores" : "   \033[2m3. Remover Todos os Gestores\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                                      \xB3\n", opGerirGestor == 4 ? "\033[2m>\033[0m  4. Editar Gestor" : "   \033[2m4. Editar Gestor\033[0m");
    imprimirCoisas(' ');
    printf("\xB3  %s                           \xB3\n", opGerirGestor == 5 ? "\033[2m>\033[0m  5. Listar Todos os Gestores" : "   \033[2m5. Listar Todos os Gestores\033[0m");
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("\xB3        %s         \xB3\n", opGerirGestor == 9 ? "Pressione 9 para regressar a tela anterior" : "\033[2mPressione 9 para regressar a tela anterior\033[0m");
    imprimirCoisas(' ');
    printf("\xB3                  \033[31mPressione ESC para sair\033[0m                  \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC0');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xD9');
    printf("\e[?25l"); /** Oculta o cursor */
}

//////////////////////////////////////////////////////

/**
 * @brief Função de login que verifica as credenciais do usuário.
 *
 * @param username O nome de usuário fornecido pelo usuário.
 * @param password A senha fornecida pelo usuário.
 * @return Retorna um valor inteiro indicando o resultado do login.
 */

int login(char *username, char *password)
{
    int cur_field = 0; /** 0 para o campo de nome de utilizador, 1 para o campo de senha */
    /** Essa variável armazena qual campo de entrada está sendo editado (nome de utilizador ou senha) */
    int i;
    system("cls");     /** Limpa o ecrã do console */
    printf("\e[?25l"); /** Oculta o cursor */
    /** Essas linhas limpam a tela e ocultam o cursor para que a entrada do utilizador seja mais limpa */

    /** Exibe os campos de entrada e destaca o campo de nome de utilizador */
    printf("\n\n\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("\t   %c", '\xDA');
    for (i = 0; i < 45; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xBF');
    imprimirCoisas(' ');
    printf("\t   \xB3                    \033[32mLogin\033[0m                    \xB3\n");
    imprimirCoisas(' ');
    printf("\t   %c", '\xC3');
    for (i = 0; i < 45; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("\t   %c", '\xB3');
    for (i = 0; i < 45; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');

    /** Aqui está a lógica para exibir os campos de entrada e destacar o campo atual */
    /** O campo atual é destacado pela cor do texto (vermelho para senha, normal para nome de utilizador) */
    if (cur_field == 0)
    {
        imprimirCoisas(' ');
        printf("\t   \xB3  Nome de usuario: ");
        printf("\033[31m%s\033[0m", username); /** Destaca o nome de utilizador em vermelho */
    }
    else
    {
        printf("%s", username);
    }
    imprimeEspacos(username);
    printf("\xB3\n");

    imprimirCoisas(' ');
    printf("\t   \xB3  \033[2mSenha:\033[0m ");
    if (cur_field == 1)
    {
        for (size_t i = 0; i < strlen(password); i++)
        {
            printf("*"); /** Exibe um asterisco no lugar da senha para proteger a privacidade do utilizador */
        }
    }
    else
    {
        printf("%s", password);
    }
    imprimeEspacos(password);
    printf("          \xB3\n");
    imprimirCoisas(' ');
    printf("\t   %c", '\xB3');
    for (i = 0; i < 45; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("\t   %c", '\xC0');
    for (i = 0; i < 45; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xD9');
    printf("\n\n\t\033[2mUtilize a tecla TAB para navegar entre os campos\n");
    printf("\tPrima ENTER para efetuar o login\033[0m");

    /** Processa a entrada do utilizador até que a tecla Enter seja pressionada */
    while (1)
    {
        int key = getch();

        /** Se a tecla Enter for pressionada, saia do loop */
        if (key == '\r')
        {
            break;
        }

        /** Se a tecla Tab ou uma das setas for pressionada, alterne o campo atual */
        if (key == '\t' || key == 224)
        {
            cur_field = (cur_field + 1) % 2;
        }

        /** Se a tecla Backspace for pressionada, apague o último caractere do campo atual */
        if (key == '\b')
        {
            if (cur_field == 0 && strlen(username) > 0)
            {
                username[strlen(username) - 1] = '\0';
            }
            else if (cur_field == 1 && strlen(password) > 0)
            {
                password[strlen(password) - 1] = '\0';
            }
        }

        /** Se uma tecla de caractere imprimível for pressionada, adicione-a ao campo atual */
        /** if ((key >= 32 && key <= 47) || (key >= 58 && key <= 64) || (key >= 91 && key <= 126)) */
        if (key >= ' ' && key <= '~')
        {
            if (cur_field == 0 && strlen(username) < TAMANHO_MAXIMO_NOME_UTILIZADOR)
            {
                strncat(username, (char *)&key, 1);
            }
            else if (cur_field == 1 && strlen(password) < TAMANHO_MAXIMO_PASSWORD)
            {
                strncat(password, (char *)&key, 1);
            }
        }

        /** Limpa a tela e exibe os campos atualizados */
        system("cls"); /** Limpa o ecrã do console */
        printf("\n\n\n\n\n\n\n");
        imprimirCoisas(' ');
        printf("\t   %c", '\xDA');
        for (i = 0; i < 45; i++)
        {
            printf("%c", '\xC4');
        }
        printf("%c\n", '\xBF');
        imprimirCoisas(' ');
        printf("\t   \xB3                    \033[32mLogin\033[0m                    \xB3\n");
        imprimirCoisas(' ');
        printf("\t   %c", '\xC3');
        for (i = 0; i < 45; i++)
        {
            printf("%c", '\xC4');
        }
        printf("%c\n", '\xB4');
        imprimirCoisas(' ');
        printf("\t   %c", '\xB3');
        for (i = 0; i < 45; i++)
        {
            printf("%c", ' ');
        }
        printf("%c\n", '\xB3');
        if (cur_field == 0)
        {
            imprimirCoisas(' ');
            printf("\t   \xB3  Nome de usuario: ");
            printf("\033[31m%s\033[0m", username);
            imprimeEspacos(username);
            printf("\xB3\n");
            imprimirCoisas(' ');
            printf("\t   \xB3  \033[2mSenha:\033[0m ");
        }
        else
        {
            imprimirCoisas(' ');
            printf("\t   \xB3  \033[2mNome de usuario:\033[0m ");
            printf("\033[2m%s\033[0m", username);
            imprimeEspacos(username);
            printf("\xB3\n");
        }

        if (cur_field == 1)
        {
            imprimirCoisas(' ');
            printf("\t   \xB3  Senha: ");
            for (size_t i = 0; i < strlen(password); i++)
            {
                printf("\033[31m*\033[0m");
            }
        }
        else
        {
            for (size_t i = 0; i < strlen(password); i++)
            {
                printf("\033[2m*\033[0m");
            }
        }
        imprimeEspacos(password);
        printf("          \xB3\n");
        imprimirCoisas(' ');
        printf("\t   %c", '\xB3');
        for (i = 0; i < 45; i++)
        {
            printf("%c", ' ');
        }
        printf("%c\n", '\xB3');
        imprimirCoisas(' ');
        printf("\t   %c", '\xC0');
        for (i = 0; i < 45; i++)
        {
            printf("%c", '\xC4');
        }
        printf("%c\n", '\xD9');
        printf("\n\n\t\033[2mUtilize a tecla TAB para navegar entre os campos\n");
        printf("\tPrima ENTER para efetuar o login\033[0m");
    }
    return 0;
}

//////////////////////////////////////////////////////

void validacaoOperacao(int opVal)
{
    int i;
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("%c", '\xDA');
    for (i = 0; i < 59; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xBF');
    imprimirCoisas(' ');
    printf("\xB3    \033[32mTem certeza de que deseja continuar com a operacao?\033[0m    \xB3\n");
    imprimirCoisas(' ');
    printf("%c", '\xC3');
    for (i = 0; i < 29; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c", '\xC2');
    for (i = 0; i < 29; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xB4');
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 29; i++)
    {
        printf("%c", ' ');
    }
    printf("%c", '\xB3');
    for (i = 0; i < 29; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("\xB3             %s             \xB3", opVal == 1 ? "SIM" : "\033[2mSIM\033[0m");
    printf("             %s             \xB3\n", opVal == 2 ? "NAO" : "\033[2mNAO\033[0m");
    imprimirCoisas(' ');
    printf("%c", '\xB3');
    for (i = 0; i < 29; i++)
    {
        printf("%c", ' ');
    }
    printf("%c", '\xB3');
    for (i = 0; i < 29; i++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '\xB3');
    imprimirCoisas(' ');
    printf("%c", '\xC0');
    for (i = 0; i < 29; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c", '\xC1');
    for (i = 0; i < 29; i++)
    {
        printf("%c", '\xC4');
    }
    printf("%c\n", '\xD9');
}

//////////////////////////////////////////////////////

/**
 * Função para carregar o saldo de um cliente.
 *
 * @param username O nome de utilizador do cliente.
 */

void menuCarregarSaldo(char *username)
{
    /** @var Variável para armazenar a lista de clientes */
    Cliente *clientes = NULL;

    /** Variáveis para armazenar informações de clientes */
    int cliNif;
    float carregarSaldo, novoSaldo;

    /** Carrega os dados dos ficheiros. */
    clientes = lerClientes();
    if (clientes == NULL)
    {
        clientes = lerClientesBinario();
    }

    bool exitLoop = false;

    exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */

    Cliente *clienteLogado = obterClientePorUsername(clientes, username);

    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\033[1mBem-vindo(a) de volta, %s!\033[0m \033[2m(saldo atual: %.2f euros)\033[0m", clienteLogado->clienteNome, clienteLogado->clienteSaldo);
    printf("\nComo podemos ajuda-lo(a) a tornar sua proxima viagem com a \033[32mGreenGo\033[0m uma experiencia memoravel e agradavel?\n");
    printf("\n \033[2m(Preencha os campos abaixo com as informacoes solicitadas, para cancelar escreva SAIR)\033[0m\n");
    carregarSaldo = floatConfirmacao("Insira o valor em euros que pretender carregar na sua conta cliente: ", &exitLoop);
    if (exitLoop)
    {
        return;
    }
    cliNif = clienteLogado->clienteNif;
    novoSaldo = clienteLogado->clienteSaldo + carregarSaldo;
    clientes = editarCliente(clientes, cliNif, "", "", -1, "", novoSaldo, "", "");
    guardarClientes(clientes);
    guardarClientesLeitura(clientes);
    guardarClientesBinario(clientes);
    printf("\n\n");
    imprimirLinha('\xC4');
    printf("\033[1m");
    imprimirCentrado(' ', "CARREGAMENTO EFECTUADO COM SUCESSO");
    printf("\033[0m\n");
    imprimirLinha('\xC4');
    printf("\n\n \033[7m Informacoes do carregamento \033[0m\n");
    printf("\033[1mNIF: %d\033[0m\n > Nome do(a) cliente: %s\n > Saldo atual do Cliente: %.2f euros\n", cliNif, clienteLogado->clienteNome, novoSaldo);
    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
    getch(); /** Espera que o utilizador pressionar uma tecla */
}

/**
 *
 * Função para adicionar um novo meio de mobilidade.
 *
 */

void menuAdicionarMeio()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** Variáveis para armazenar informações de meios */
    int meCod = 1;
    float meBat, meAut, mePre;
    char meTipo[50], meGeo[100];
    int meAlu;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    meios = lerMeios();
    if (meios == NULL)
    {
        meios = lerMeiosBinario();
    }

    bool exitLoop = false;

    exitLoop = false;
    do
    {
        validacaoOperacao(opVal);
        teclaVal = getch();
        switch (teclaVal)
        {
        case TECLA_ESQUERDA:
        case TECLA_DIREITA:
        case TECLA_TAB:
            opVal = opVal == 1 ? 2 : 1;
            break;
        case TECLA_ENTER:
            switch (opVal)
            {
            case 1:
                system("cls"); /** Limpa o ecrã do console */
                printf("\n\n \033[7m Novo Meio de mobilidade eletrica \033[0m\n");
                printf(" \033[2m(Preencha os campos abaixo com as informacoes solicitadas, para cancelar escreva SAIR)\033[0m\n\n");
                printf(" > Tipo de mobilidade eletrica: ");
                scanf("%s", meTipo);
                if (strcmp(meTipo, "SAIR") == 0)
                {
                    return;
                }
                do
                {
                    meBat = floatConfirmacao(" > Nivel da bateria (%): ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    if (meBat < 0 || meBat > 100)
                    {
                        printf(" \033[2m(Valor invalido para o nivel da bateria. O nivel da bateria e representado em percentagem de 0 a 100%%)\033[0m\n");
                    }
                } while (meBat < 0 || meBat > 100);
                meAut = floatConfirmacao(" > Autonomia (km): ", &exitLoop);
                if (exitLoop)
                {
                    return;
                }
                mePre = floatConfirmacao(" > Preco por minuto: ", &exitLoop);
                if (exitLoop)
                {
                    return;
                }
                printf(" > Geocodigo (atraves do what3words.com)\n");
                printf("\033[2m 1. ///davam.nele.solda (BRAGA PARQUE)\n");
                printf(" 2. ///alpinos.contributivo.cintila (SAMEIRO BRAGA)\n");
                printf(" 3. ///facial.jogam.chame (CHAFARIZ DA AVENIDADA)\n");
                printf(" 4. ///pediu.flui.bica (HOSPITAL DE BRAGA)\n");
                printf(" 5. ///redor.belo.ligam (MINHO CENTER)\n");
                printf(" 6. ///massas.faixa.selos (UNIVERSIDADE DO MINHO)\n");
                printf(" 7. ///idosa.fraca.jogamos (MCDONALDS UM)\n");
                printf(" 8. ///merece.irem.alcancei (JARDIM SANTA BARBARA)\n");
                printf(" 9. ///lesmas.chorar.folga (PARQUE DA PONTE)\n");
                printf("10. ///redor.olhe.atol (BOM JESUS)\n");
                printf("11. ///sulcar.desfastio.adubar (IPCA BRAGA)\033[0m\n");

                int opcao;
                do
                {
                    opcao = intConfirmacao("Escolha a opcao correspondente ao geocodigo desejado: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    printf("%d", &opcao);

                    switch (opcao)
                    {
                    case 1:
                        strcpy(meGeo, "///davam.nele.solda");
                        break;
                    case 2:
                        strcpy(meGeo, "///alpinos.contributivo.cintila");
                        break;
                    case 3:
                        strcpy(meGeo, "///facial.jogam.chame");
                        break;
                    case 4:
                        strcpy(meGeo, "///pediu.flui.bica");
                        break;
                    case 5:
                        strcpy(meGeo, "///redor.belo.ligam");
                        break;
                    case 6:
                        strcpy(meGeo, "///massas.faixa.selos");
                        break;
                    case 7:
                        strcpy(meGeo, "///idosa.fraca.jogamos");
                        break;
                    case 8:
                        strcpy(meGeo, "///merece.irem.alcancei");
                        break;
                    case 9:
                        strcpy(meGeo, "///lesmas.chorar.folga");
                        break;
                    case 10:
                        strcpy(meGeo, "///redor.olhe.atol");
                        break;
                    case 11:
                        strcpy(meGeo, "///sulcar.desfastio.adubar");
                        break;
                    default:
                        printf(" \033[2m(Valor do geocodigo invalido. Escolha uma das opcoes entre 1 e 11)\033[0m\n");
                    }
                } while (opcao < 1 || opcao > 11);
                meAlu = 0;
                while (existeMeio(meios, meCod))
                {
                    meCod++;
                }
                meios = inserirMeio(meios, meCod, meTipo, meBat, meAut, mePre, meGeo, meAlu);
                guardarMeios(meios);
                guardarMeiosBinario(meios);
                system("cls"); /** Limpa o ecrã do console */
                printf("\n");
                printf("\033[1m");
                imprimirCentrado(' ', "MEIO INSERIDO COM SUCESSO");
                printf("\033[0m\n");
                imprimirLinha('\xC4');
                printf("\n \033[7m Informacoes do meio de mobilidade eletrica inserido \033[0m\n");
                listarMeioComCodigo(meios, meCod);
                printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                getch(); /** Espera que o utilizador pressionar uma tecla */
                exitLoop = true;
                break;
            case 2:
                exitLoop = true;
                break;
            }
            break;
        }
    } while (!exitLoop);
}

/**
 *
 * Função para remover um meio de mobilidade.
 *
 */

void menuRemoverMeio()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** Variáveis para armazenar informações de meios */
    int meCod = 1;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    meios = lerMeios();
    if (meios == NULL)
    {
        meios = lerMeiosBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (meios == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL REMOVER MEIOS DE MOBLIDIDADE ELETRICA PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    printf("\n\n \033[7m Remover Meio de mobilidade eletrica \033[0m\n");
                    meCod = intConfirmacao("\n > Insira o codigo do meio que deseja remover: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    while (!existeMeio(meios, meCod))
                    {
                        printf("\n \033[2m(O codigo inserido nao existe)\033[0m\n");
                        meCod = intConfirmacao(" > Reintroduza o codigo do meio que deseja remover: ", &exitLoop);
                    }
                    meios = removerMeio(meios, meCod);
                    guardarMeios(meios);
                    guardarMeiosBinario(meios);
                    printf("\n");
                    imprimirLinha('\xC4');
                    printf("\033[1m");
                    imprimirCentrado(' ', "MEIO REMOVIDO COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para remover todos os meios de mobilidades.
 *
 */

void menuRemoverTodosMeios()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    meios = lerMeios();
    if (meios == NULL)
    {
        meios = lerMeiosBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (meios == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL REMOVER MEIOS DE MOBLIDIDADE ELETRICA PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    limparArquivoMeios();
                    limparArquivoMeiosBinario();
                    printf("\n");
                    imprimirLinha('\xC4');
                    printf("\033[1m");
                    imprimirCentrado(' ', "DADOS DE TODOS OS MEIOS REMOVIDOS COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para editar um meio de mobilidade.
 *
 */

void menuEditarMeio()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** Variáveis para armazenar informações de meios */
    int meCod = 1;
    float meBat, meAut, mePre;
    char meTipo[50] = "", meGeo[100] = "";

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    meios = lerMeios();
    if (meios == NULL)
    {
        meios = lerMeiosBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (meios == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL EDITAR MEIOS DE MOBLIDIDADE ELETRICA PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    printf("\n\n \033[7m Editar Meio de mobilidade eletrica \033[0m\n");
                    meCod = intConfirmacao("\n > Insira o codigo do meio que deseja editar: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    while (!existeMeio(meios, meCod))
                    {
                        printf("\n \033[2m(O codigo inserido nao existe)\033[0m\n");
                        meCod = intConfirmacao(" > Reintroduza o codigo do meio que deseja editar: ", &exitLoop);
                        if (exitLoop)
                        {
                            return;
                        }
                    }
                    printf(" > Insira o novo tipo de mobilidade eletrica do meio (deixe em branco para manter o atual): ");
                    fgets(meTipo, sizeof(meTipo), stdin);
                    meTipo[strcspn(meTipo, "\n")] = '\0'; /** Remove a quebra de linha */
                    printf(" > Insira o novo nivel da bateria do meio (-1 para manter o atual): ");
                    do
                    {
                        scanf("%f", &meBat);
                        if (meBat < -1 || meBat > 100)
                        {
                            printf(" \033[2m(Valor invalido para o nivel da bateria. O nivel da bateria e representado em percentagem de 0 a 100%%)\033[0m\n");
                            printf(" > Reintroduza o novo nivel da bateria: ");
                        }
                    } while (meBat < -1 || meBat > 100);
                    printf(" > Insira o novo autonomia do meio (-1 para manter o atual): ");
                    scanf("%f", &meAut);
                    getchar();
                    printf(" > Insira o novo preco por minuto do meio (-1 para manter o atual): ");
                    scanf("%f", &mePre);
                    getchar();
                    printf(" > Geocodigo (atraves do what3words.com)\n");
                    printf("\033[2m 1. ///davam.nele.solda (BRAGA PARQUE)\n");
                    printf(" 2. ///alpinos.contributivo.cintila (SAMEIRO BRAGA)\n");
                    printf(" 3. ///facial.jogam.chame (CHAFARIZ DA AVENIDADA)\n");
                    printf(" 4. ///pediu.flui.bica (HOSPITAL DE BRAGA)\n");
                    printf(" 5. ///redor.belo.ligam (MINHO CENTER)\n");
                    printf(" 6. ///massas.faixa.selos (UNIVERSIDADE DO MINHO)\n");
                    printf(" 7. ///idosa.fraca.jogamos (MCDONALDS UM)\n");
                    printf(" 8. ///merece.irem.alcancei (JARDIM SANTA BARBARA)\n");
                    printf(" 9. ///lesmas.chorar.folga (PARQUE DA PONTE)\n");
                    printf("10. ///redor.olhe.atol (BOM JESUS)\n");
                    printf("11. ///sulcar.desfastio.adubar (IPCA BRAGA)\033[0m\n");

                    int opcao;
                    do
                    {
                        printf("Selecione a opcao correspondente ao geocódigo desejado (ou deixe em branco para manter o atual): ");
                        fgets(meGeo, sizeof(meGeo), stdin);
                        meGeo[strcspn(meGeo, "\n")] = '\0'; /** Remove a quebra de linha */

                        if (strlen(meGeo) == 0)
                        {
                            /** O usuário deixou em branco, não alterar nada */
                            printf("Nenhum geocódigo selecionado. O geocódigo atual será mantido.\n");
                            break; /** Sair do loop */
                        }

                        opcao = atoi(meGeo);
                        switch (opcao)
                        {
                        case 1:
                            strcpy(meGeo, "///davam.nele.solda");
                            break;
                        case 2:
                            strcpy(meGeo, "///alpinos.contributivo.cintila");
                            break;
                        case 3:
                            strcpy(meGeo, "///facial.jogam.chame");
                            break;
                        case 4:
                            strcpy(meGeo, "///pediu.flui.bica");
                            break;
                        case 5:
                            strcpy(meGeo, "///redor.belo.ligam");
                            break;
                        case 6:
                            strcpy(meGeo, "///massas.faixa.selos");
                            break;
                        case 7:
                            strcpy(meGeo, "///idosa.fraca.jogamos");
                            break;
                        case 8:
                            strcpy(meGeo, "///merece.irem.alcancei");
                            break;
                        case 9:
                            strcpy(meGeo, "///lesmas.chorar.folga");
                            break;
                        case 10:
                            strcpy(meGeo, "///redor.olhe.atol");
                            break;
                        case 11:
                            strcpy(meGeo, "///sulcar.desfastio.adubar");
                            break;
                        default:
                            printf("\033[2m(Valor do geocodigo invalido. Escolha uma das opcoes entre 1 e 11)\033[0m\n");
                            break;
                        }
                    } while (opcao < 1 || opcao > 11);
                    meios = editarMeio(meios, meCod, meTipo, meBat, meAut, mePre, meGeo, -1);
                    guardarMeios(meios);
                    guardarMeiosBinario(meios);
                    system("cls"); /** Limpa o ecrã do console */

                    /** Carrega os dados dos ficheiros. */
                    meios = lerMeios();
                    if (meios == NULL)
                    {
                        meios = lerMeiosBinario();
                    }

                    printf("\n");
                    printf("\033[1m");
                    imprimirCentrado(' ', "MEIO EDITADO COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n \033[7m Informacoes do meio de mobilidade eletrica \033[0m\n");
                    listarMeioComCodigo(meios, meCod);
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para listar os meios de mobilidades.
 *
 */

void menuListarMeio()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** Carrega os dados dos ficheiros. */
    meios = lerMeios();
    if (meios == NULL)
    {
        meios = lerMeiosBinario();
    }

    system("cls"); /** Limpa o ecrã do console */
    if (meios == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "A LISTA DE MEIOS DE MOBLIDIDADE ELETRICA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
    }
    else
    {
        printf("\n");
        printf("\033[1m");
        imprimirCentrado(' ', "LISTAGEM DE MEIOS DE MOBILIDADE ELETRICA");
        printf("\033[0m\n");
        listarMeios(meios);
    }
    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
    getch(); /** Espera que o utilizador pressionar uma tecla */
}

void menuListarAutonomiaMeio()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** Carrega os dados dos ficheiros. */
    meios = lerMeios();
    if (meios == NULL)
    {
        meios = lerMeiosBinario();
    }

    system("cls"); /** Limpa o ecrã do console */
    if (meios == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "A LISTA DE MEIOS DE MOBLIDIDADE ELETRICA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
    }
    else
    {
        printf("\n");
        printf("\033[1m");
        imprimirCentrado(' ', "LISTAGEM DE MEIOS DE MOBILIDADE ELETRICA");
        printf("\033[0m\n");
        listarMeiosPorAutonomia(meios);
    }
    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
    getch(); /** Espera que o utilizador pressionar uma tecla */
}

//////////////////////////////////////////////////////

/**
 *
 * Função para adicionar um novo cliente.
 *
 */

void menuAdicionarCliente()
{
    /** @var Variável para armazenar a lista de clientes */
    Cliente *clientes = NULL;

    /** Variáveis para armazenar informações de clientes */
    int cliNif, cliTel;
    char cliNome[50], cliEmail[50], cliGeo[100], cliUser[50], cliPass[50];
    float cliSaldo;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    clientes = lerClientes();
    if (clientes == NULL)
    {
        clientes = lerClientesBinario();
    }

    bool exitLoop = false;

    exitLoop = false;

    do
    {
        validacaoOperacao(opVal);
        teclaVal = getch();
        switch (teclaVal)
        {
        case TECLA_ESQUERDA:
        case TECLA_DIREITA:
        case TECLA_TAB:
            opVal = opVal == 1 ? 2 : 1;
            break;
        case TECLA_ENTER:
            switch (opVal)
            {
            case 1:

                system("cls"); /** Limpa o ecrã do console */
                printf("\n\n \033[7m Novo Cliente \033[0m\n");
                printf(" \033[2m(Preencha os campos abaixo com as informacoes solicitadas, para cancelar escreva SAIR)\033[0m\n\n");
                do
                {
                    cliNif = intConfirmacao("Insira o NIF do cliente: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    if (existeCliente(clientes, cliNif))
                    { /** Se o NIF inserido já existir no sistema */
                        printf(" \033[2m(O NIF inserido ja existe. Insira outro valor)\033[0m\n");
                    }
                } while (existeCliente(clientes, cliNif)); /** Repete o loop se a entrada for inválida ou se o NIF já existir */
                printf(" > Primeiro Nome: ");
                scanf("%s", cliNome);
                if (strcmp(cliNome, "SAIR") == 0)
                {
                    return;
                }
                printf(" > Email: ");
                scanf("%s", cliEmail);
                if (strcmp(cliEmail, "SAIR") == 0)
                {
                    return;
                }
                cliTel = intConfirmacao(" > Telemovel: ", &exitLoop);
                if (exitLoop)
                {
                    return;
                }
                printf(" > Geocodigo (atraves do what3words.com)\n");
                printf("\033[2m 1. ///davam.nele.solda (BRAGA PARQUE)\n");
                printf(" 2. ///alpinos.contributivo.cintila (SAMEIRO BRAGA)\n");
                printf(" 3. ///facial.jogam.chame (CHAFARIZ DA AVENIDADA)\n");
                printf(" 4. ///pediu.flui.bica (HOSPITAL DE BRAGA)\n");
                printf(" 5. ///redor.belo.ligam (MINHO CENTER)\n");
                printf(" 6. ///massas.faixa.selos (UNIVERSIDADE DO MINHO)\n");
                printf(" 7. ///idosa.fraca.jogamos (MCDONALDS UM)\n");
                printf(" 8. ///merece.irem.alcancei (JARDIM SANTA BARBARA)\n");
                printf(" 9. ///lesmas.chorar.folga (PARQUE DA PONTE)\n");
                printf("10. ///redor.olhe.atol (BOM JESUS)\n");
                printf("11. ///sulcar.desfastio.adubar (IPCA BRAGA)\033[0m\n");

                int opcao;
                do
                {
                    opcao = intConfirmacao("Escolha a opcao correspondente ao geocodigo desejado: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }

                    switch (opcao)
                    {
                    case 1:
                        strcpy(cliGeo, "///davam.nele.solda");
                        break;
                    case 2:
                        strcpy(cliGeo, "///alpinos.contributivo.cintila");
                        break;
                    case 3:
                        strcpy(cliGeo, "///facial.jogam.chame");
                        break;
                    case 4:
                        strcpy(cliGeo, "///pediu.flui.bica");
                        break;
                    case 5:
                        strcpy(cliGeo, "///redor.belo.ligam");
                        break;
                    case 6:
                        strcpy(cliGeo, "///massas.faixa.selos");
                        break;
                    case 7:
                        strcpy(cliGeo, "///idosa.fraca.jogamos");
                        break;
                    case 8:
                        strcpy(cliGeo, "///merece.irem.alcancei");
                        break;
                    case 9:
                        strcpy(cliGeo, "///lesmas.chorar.folga");
                        break;
                    case 10:
                        strcpy(cliGeo, "///redor.olhe.atol");
                        break;
                    case 11:
                        strcpy(cliGeo, "///sulcar.desfastio.adubar");
                        break;
                    default:
                        printf(" \033[2m(Valor do geocodigo invalido. Escolha uma das opcoes entre 1 e 11)\033[0m\n");
                    }
                } while (opcao < 1 || opcao > 11);
                cliSaldo = floatConfirmacao(" > Saldo: ", &exitLoop);
                if (exitLoop)
                {
                    return;
                }
                printf(" > Username: ");
                scanf("%s", cliUser);
                if (strcmp(cliUser, "SAIR") == 0)
                {
                    return;
                }
                printf(" > Password: ");
                scanf("%s", cliPass);
                if (strcmp(cliPass, "SAIR") == 0)
                {
                    return;
                }
                clientes = inserirCliente(clientes, cliNif, cliNome, cliEmail, cliTel, cliGeo, cliSaldo, cliUser, cliPass);
                guardarClientes(clientes);
                guardarClientesLeitura(clientes);
                guardarClientesBinario(clientes);
                system("cls"); /** Limpa o ecrã do console */
                printf("\n");
                printf("\033[1m");
                imprimirCentrado(' ', "CLIENTE INSERIDO COM SUCESSO");
                printf("\033[0m\n");
                imprimirLinha('\xC4');
                printf("\n \033[7m Informacoes do cliente inserido \033[0m\n");
                listarClienteComNIF(clientes, cliNif);
                printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                getch(); /** Espera que o utilizador pressionar uma tecla */
                exitLoop = true;
                break;
            case 2:
                exitLoop = true;
                break;
            }
            break;
        }
    } while (!exitLoop);
}

/**
 *
 * Função para remover um cliente.
 *
 */

void menuRemoverCliente()
{
    /** @var Variável para armazenar a lista de clientes */
    Cliente *clientes = NULL;

    /** Variáveis para armazenar informações de clientes */
    int cliNif;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    clientes = lerClientes();
    if (clientes == NULL)
    {
        clientes = lerClientesBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (clientes == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL REMOVER CLIENTES PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    printf("\n\n \033[7m Remover Cliente \033[0m\n");
                    cliNif = intConfirmacao("\n > Insira o NIF do cliente que deseja remover: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    while (!existeCliente(clientes, cliNif))
                    {
                        printf("\n \033[2m(O NIF inserido nao existe)\033[0m\n");
                        cliNif = intConfirmacao(" > Reintroduza o NIF do cliente que deseja remover: que deseja remover: ", &exitLoop);
                    }
                    clientes = removerCliente(clientes, cliNif);
                    guardarClientes(clientes);
                    guardarClientesLeitura(clientes);
                    guardarClientesBinario(clientes);
                    printf("\n");
                    imprimirLinha('\xC4');
                    printf("\033[1m");
                    imprimirCentrado(' ', "CLIENTE REMOVIDO COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para remover todos os clientes.
 *
 */

void menuRemoverTodosClientes()
{
    /** @var Variável para armazenar a lista de clientes */
    Cliente *clientes = NULL;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    clientes = lerClientes();
    if (clientes == NULL)
    {
        clientes = lerClientesBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (clientes == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL REMOVER CLIENTES PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    limparArquivoClientes();
                    limparArquivoClientesBinario();
                    printf("\n");
                    imprimirLinha('\xC4');
                    printf("\033[1m");
                    imprimirCentrado(' ', "DADOS DE TODOS OS CLIENTES REMOVIDOS COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para editar um cliente.
 *
 */

void menuEditarCliente()
{
    /** @var Variável para armazenar a lista de meios */
    Cliente *clientes = NULL;

    /** Variáveis para armazenar informações de meios */
    int cliNif, cliTel;
    char cliNome[50] = "", cliEmail[50] = "", cliGeo[100] = "", cliUser[50] = "", cliPass[50] = "";
    float cliSaldo;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    clientes = lerClientes();
    if (clientes == NULL)
    {
        clientes = lerClientesBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (clientes == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL EDITAR CLIENTES PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    printf("\n\n \033[7m Editar Cliente \033[0m\n");
                    cliNif = intConfirmacao("\n > Insira o NIF do cliente que deseja editar: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    while (!existeCliente(clientes, cliNif))
                    {
                        printf("\n \033[2m(O NIF inserido nao existe)\033[0m\n");
                        cliNif = intConfirmacao(" > Reintroduza o NIF do cliente que deseja editar: ", &exitLoop);
                        if (exitLoop)
                        {
                            return;
                        }
                    }
                    printf(" > Insira o novo nome do cliente (deixe em branco para manter o atual): ");
                    fgets(cliNome, sizeof(cliNome), stdin);
                    cliNome[strcspn(cliNome, "\n")] = '\0'; /** Remove a quebra de linha */
                    printf(" > Insira o novo email do cliente (deixe em branco para manter o atual): ");
                    fgets(cliEmail, sizeof(cliEmail), stdin);
                    cliEmail[strcspn(cliEmail, "\n")] = '\0';
                    printf(" > Insira o novo telemovel do cliente (-1 para manter o atual): ");
                    scanf("%d", &cliTel);
                    getchar(); /** Limpa o buffer de entrada */
                    printf(" > Geocodigo (atraves do what3words.com)\n");
                    printf("\033[2m 1. ///davam.nele.solda (BRAGA PARQUE)\n");
                    printf(" 2. ///alpinos.contributivo.cintila (SAMEIRO BRAGA)\n");
                    printf(" 3. ///facial.jogam.chame (CHAFARIZ DA AVENIDADA)\n");
                    printf(" 4. ///pediu.flui.bica (HOSPITAL DE BRAGA)\n");
                    printf(" 5. ///redor.belo.ligam (MINHO CENTER)\n");
                    printf(" 6. ///massas.faixa.selos (UNIVERSIDADE DO MINHO)\n");
                    printf(" 7. ///idosa.fraca.jogamos (MCDONALDS UM)\n");
                    printf(" 8. ///merece.irem.alcancei (JARDIM SANTA BARBARA)\n");
                    printf(" 9. ///lesmas.chorar.folga (PARQUE DA PONTE)\n");
                    printf("10. ///redor.olhe.atol (BOM JESUS)\n");
                    printf("11. ///sulcar.desfastio.adubar (IPCA BRAGA)\033[0m\n");

                    int opcao;
                    do
                    {
                        printf("Selecione a opcao correspondente ao geocódigo desejado (ou deixe em branco para manter o atual): ");
                        fgets(cliGeo, sizeof(cliGeo), stdin);
                        cliGeo[strcspn(cliGeo, "\n")] = '\0'; /** Remove a quebra de linha */

                        if (strlen(cliGeo) == 0)
                        {
                            /** O usuário deixou em branco, não alterar nada */
                            printf("Nenhum geocódigo selecionado. O geocódigo atual será mantido.\n");
                            break; /** Sair do loop */
                        }

                        opcao = atoi(cliGeo);
                        switch (opcao)
                        {
                        case 1:
                            strcpy(cliGeo, "///davam.nele.solda");
                            break;
                        case 2:
                            strcpy(cliGeo, "///alpinos.contributivo.cintila");
                            break;
                        case 3:
                            strcpy(cliGeo, "///facial.jogam.chame");
                            break;
                        case 4:
                            strcpy(cliGeo, "///pediu.flui.bica");
                            break;
                        case 5:
                            strcpy(cliGeo, "///redor.belo.ligam");
                            break;
                        case 6:
                            strcpy(cliGeo, "///massas.faixa.selos");
                            break;
                        case 7:
                            strcpy(cliGeo, "///idosa.fraca.jogamos");
                            break;
                        case 8:
                            strcpy(cliGeo, "///merece.irem.alcancei");
                            break;
                        case 9:
                            strcpy(cliGeo, "///lesmas.chorar.folga");
                            break;
                        case 10:
                            strcpy(cliGeo, "///redor.olhe.atol");
                            break;
                        case 11:
                            strcpy(cliGeo, "///sulcar.desfastio.adubar");
                            break;
                        default:
                            printf("\033[2m(Valor do geocodigo invalido. Escolha uma das opcoes entre 1 e 11)\033[0m\n");
                            break;
                        }
                    } while (opcao < 1 || opcao > 11);
                    printf(" > Insira o novo saldo do cliente (-1 para manter o atual): ");
                    scanf("%f", &cliSaldo);
                    getchar(); /** Limpa o buffer de entrada */
                    printf(" > Insira a nova username do cliente (deixe em branco para manter a atual): ");
                    fgets(cliUser, sizeof(cliUser), stdin);
                    cliUser[strcspn(cliUser, "\n")] = '\0';
                    printf(" > Insira a nova password do cliente (deixe em branco para manter a atual): ");
                    fgets(cliPass, sizeof(cliPass), stdin);
                    cliPass[strcspn(cliPass, "\n")] = '\0';
                    clientes = editarCliente(clientes, cliNif, cliNome, cliEmail, cliTel, cliGeo, cliSaldo, cliUser, cliPass);
                    guardarClientes(clientes);
                    guardarClientesLeitura(clientes);
                    guardarClientesBinario(clientes);
                    system("cls"); /** Limpa o ecrã do console */

                    /** Carrega os dados dos ficheiros. */
                    clientes = lerClientes();
                    if (clientes == NULL)
                    {
                        clientes = lerClientesBinario();
                    }

                    printf("\n");
                    printf("\033[1m");
                    imprimirCentrado(' ', "CLIENTE EDITADO COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n \033[7m Informacoes do cliente \033[0m\n");
                    listarClienteComNIF(clientes, cliNif);
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para listar os clientes.
 *
 */

void menuListarCliente()
{
    /** @var Variável para armazenar a lista de clientes */
    Cliente *clientes = NULL;

    /** Carrega os dados dos ficheiros. */
    clientes = lerClientes();
    if (clientes == NULL)
    {
        clientes = lerClientesBinario();
    }

    system("cls"); /** Limpa o ecrã do console */
    if (clientes == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "A LISTA DE CLIENTES ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
    }
    else
    {
        printf("\n");
        printf("\033[1m");
        imprimirCentrado(' ', "LISTAGEM DE CLIENTES");
        printf("\033[0m\n");
        listarClientes(clientes);
    }
    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
    getch(); /** Espera que o utilizador pressionar uma tecla */
}

//////////////////////////////////////////////////////

/**
 *
 * Função para adicionar um novo gestor.
 *
 */

void menuAdicionarGestor()
{
    /** @var Variável para armazenar a lista de gestores */
    Gestor *gestores = NULL;

    /** Variáveis para armazenar informações de gestores */
    int gesNif;
    char gesNome[50], gesEmail[50], gesCargo[50], gesUser[50], gesPass[50];

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    gestores = lerGestores();
    if (gestores == NULL)
    {
        gestores = lerGestoresBinario();
    }

    bool exitLoop = false;

    exitLoop = false;
    do
    {
        validacaoOperacao(opVal);
        teclaVal = getch();
        switch (teclaVal)
        {
        case TECLA_ESQUERDA:
        case TECLA_DIREITA:
        case TECLA_TAB:
            opVal = opVal == 1 ? 2 : 1;
            break;
        case TECLA_ENTER:
            switch (opVal)
            {
            case 1:
                system("cls"); /** Limpa o ecrã do console */
                printf("\n\n \033[7m Novo Gestor \033[0m\n");
                printf(" \033[2m(Preencha os campos abaixo com as informacoes solicitadas, para cancelar escreva SAIR)\033[0m\n\n");
                do
                {
                    gesNif = intConfirmacao("Insira o NIF do gestor: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    if (existeGestor(gestores, gesNif))
                    { /** Se o NIF inserido já existir no sistema */
                        printf(" \033[2m(O NIF inserido ja existe. Insira outro valor)\033[0m\n");
                    }
                } while (existeGestor(gestores, gesNif)); /** Repete o loop se a entrada for inválida ou se o NIF já existir */
                printf(" > Primeiro Nome: ");
                scanf("%s", gesNome);
                if (strcmp(gesNome, "SAIR") == 0)
                {
                    return;
                }
                printf(" > Email: ");
                scanf("%s", gesEmail);
                if (strcmp(gesEmail, "SAIR") == 0)
                {
                    return;
                }
                printf(" > Cargo: ");
                scanf("%s", gesCargo);
                if (strcmp(gesCargo, "SAIR") == 0)
                {
                    return;
                }
                printf(" > Username: ");
                scanf("%s", gesUser);
                if (strcmp(gesUser, "SAIR") == 0)
                {
                    return;
                }
                printf(" > Password: ");
                scanf("%s", gesPass);
                if (strcmp(gesPass, "SAIR") == 0)
                {
                    return;
                }
                gestores = inserirGestor(gestores, gesNif, gesNome, gesEmail, gesCargo, gesUser, gesPass);
                guardarGestores(gestores);
                guardarGestoresBinario(gestores);
                system("cls"); /** Limpa o ecrã do console */
                printf("\n");
                printf("\033[1m");
                imprimirCentrado(' ', "GESTOR INSERIDO COM SUCESSO");
                printf("\033[0m\n");
                imprimirLinha('\xC4');
                printf("\n \033[7m Informacoes do gestor inserido \033[0m\n");
                listarGestorComNIF(gestores, gesNif);
                printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                getch(); /** Espera que o utilizador pressionar uma tecla */
                exitLoop = true;
                break;
            case 2:
                exitLoop = true;
                break;
            }
            break;
        }
    } while (!exitLoop);
}

/**
 *
 * Função para remover um gestor.
 *
 */

void menuRemoverGestor()
{
    /** @var Variável para armazenar a lista de gestores */
    Gestor *gestores = NULL;

    /** Variáveis para armazenar informações de gestores */
    int gesNif;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    gestores = lerGestores();
    if (gestores == NULL)
    {
        gestores = lerGestoresBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (gestores == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL REMOVER GESTORES PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    printf("\n\n \033[7m Remover Gestor \033[0m\n");
                    gesNif = intConfirmacao("\n > Insira o NIF do gestor que deseja remover: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    while (!existeGestor(gestores, gesNif))
                    {
                        printf("\n \033[2m(O NIF inserido nao existe)\033[0m\n");
                        gesNif = intConfirmacao(" > Reintroduza o NIF do gestor que deseja remover: que deseja remover: ", &exitLoop);
                    }
                    gestores = removerGestor(gestores, gesNif);
                    guardarGestores(gestores);
                    guardarGestoresBinario(gestores);
                    printf("\n");
                    imprimirLinha('\xC4');
                    printf("\033[1m");
                    imprimirCentrado(' ', "GESTOR REMOVIDO COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para remover todos os gestores.
 *
 */

void menuRemoverTodosGestores()
{
    /** @var Variável para armazenar a lista de gestores */
    Gestor *gestores = NULL;

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    gestores = lerGestores();
    if (gestores == NULL)
    {
        gestores = lerGestoresBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (gestores == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL REMOVER GESTORES PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    limparArquivoGestores();
                    limparArquivoGestoresBinario();
                    printf("\n");
                    imprimirLinha('\xC4');
                    printf("\033[1m");
                    imprimirCentrado(' ', "DADOS DE TODOS OS GESTORES REMOVIDOS COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para editar um gestor.
 *
 */

void menuEditarGestor()
{
    /** @var Variável para armazenar a lista de gestores */
    Gestor *gestores = NULL;

    /** Variáveis para armazenar informações de gestores */
    int gesNif;
    char gesNome[50] = "", gesEmail[50] = "", gesCargo[50] = "", gesUser[50] = "", gesPass[50] = "";

    /** Variáveis de menu */
    char teclaVal;
    int opVal = 1;

    /** Carrega os dados dos ficheiros. */
    gestores = lerGestores();
    if (gestores == NULL)
    {
        gestores = lerGestoresBinario();
    }

    bool exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */
    if (gestores == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO E POSSIVEL EDITAR GESTORES PORQUE A LISTA ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
    }
    else
    {
        exitLoop = false;
        do
        {
            validacaoOperacao(opVal);
            teclaVal = getch();
            switch (teclaVal)
            {
            case TECLA_ESQUERDA:
            case TECLA_DIREITA:
            case TECLA_TAB:
                opVal = opVal == 1 ? 2 : 1;
                break;
            case TECLA_ENTER:
                switch (opVal)
                {
                case 1:
                {
                    system("cls"); /** Limpa o ecrã do console */
                    printf("\n\n \033[7m Editar Gestor \033[0m\n");
                    gesNif = intConfirmacao("\n > Insira o NIF do gestor que deseja editar: ", &exitLoop);
                    if (exitLoop)
                    {
                        return;
                    }
                    while (!existeGestor(gestores, gesNif))
                    {
                        printf("\n \033[2m(O NIF inserido nao existe)\033[0m\n");
                        gesNif = intConfirmacao(" > Reintroduza o NIF do gestor que deseja editar: ", &exitLoop);
                        if (exitLoop)
                        {
                            return;
                        }
                    }
                    getchar(); /** Limpa o buffer de entrada */
                    printf(" > Insira o novo nome do gestor (deixe em branco para manter o atual): ");
                    fgets(gesNome, sizeof(gesNome), stdin);
                    gesNome[strcspn(gesNome, "\n")] = '\0'; /** Remove a quebra de linha */
                    printf(" > Insira o novo email do gestor (deixe em branco para manter o atual): ");
                    fgets(gesEmail, sizeof(gesEmail), stdin);
                    gesEmail[strcspn(gesEmail, "\n")] = '\0'; /** Remove a quebra de linha */
                    printf(" > Insira o novo cargo do gestor (deixe em branco para manter o atual): ");
                    fgets(gesCargo, sizeof(gesCargo), stdin);
                    gesCargo[strcspn(gesCargo, "\n")] = '\0'; /** Remove a quebra de linha */
                    printf(" > Insira o novo username do gestor (deixe em branco para manter o atual): ");
                    fgets(gesUser, sizeof(gesUser), stdin);
                    gesUser[strcspn(gesUser, "\n")] = '\0'; /** Remove a quebra de linha */
                    printf(" > Insira a nova password do gestor (deixe em branco para manter o atual): ");
                    fgets(gesPass, sizeof(gesPass), stdin);
                    gesPass[strcspn(gesPass, "\n")] = '\0'; /** Remove a quebra de linha */
                    getchar();
                    gestores = editarGestor(gestores, gesNif, gesNome, gesEmail, gesCargo, gesUser, gesPass);
                    guardarGestores(gestores);
                    guardarGestoresBinario(gestores);
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    system("cls"); /** Limpa o ecrã do console */

                    /** Carrega os dados dos ficheiros. */
                    gestores = lerGestores();
                    if (gestores == NULL)
                    {
                        gestores = lerGestoresBinario();
                    }

                    printf("\n");
                    printf("\033[1m");
                    imprimirCentrado(' ', "GESTOR EDITADO COM SUCESSO");
                    printf("\033[0m\n");
                    imprimirLinha('\xC4');
                    printf("\n \033[7m Informacoes do gestor \033[0m\n");
                    listarGestorComNIF(gestores, gesNif);
                    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                    getch(); /** Espera que o utilizador pressionar uma tecla */
                    exitLoop = true;
                }
                break;
                case 2:
                    exitLoop = true;
                    break;
                }
                break;
            }
        } while (!exitLoop);
    }
}

/**
 *
 * Função para listar os gestores.
 *
 */

void menuListarGestor()
{
    /** @var Variável para armazenar a lista de gestores */
    Gestor *gestores = NULL;

    /** Carrega os dados dos ficheiros. */
    gestores = lerGestores();
    if (gestores == NULL)
    {
        gestores = lerGestoresBinario();
    }

    system("cls"); /** Limpa o ecrã do console */
    if (gestores == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "A LISTA DE GESTORES ESTA VAZIA");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
    }
    else
    {
        printf("\n");
        printf("\033[1m");
        imprimirCentrado(' ', "LISTAGEM DE GESTORES");
        printf("\033[0m\n");
        listarGestores(gestores);
    }
    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
    getch(); /** Espera que o utilizador pressionar uma tecla */
}

//////////////////////////////////////////////////////

void credenciaisInvalidas()
{
    int i;
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\n\n\n\n\n\n\n\n");
    imprimirCoisas(' ');
    printf("\033[31m%c\033[0m", '\xDA');
    for (i = 0; i < 59; i++)
    {
        printf("\033[31m%c\033[0m", '\xC4');
    }
    printf("\033[31m%c\033[0m\n", '\xBF');
    imprimirCoisas(' ');
    printf("\033[31m\xB3\033[0m            \033[31;1mNome de usuario ou senha invalidos!\033[0m            \033[31m\xB3\033[0m\n");
    imprimirCoisas(' ');
    printf("\033[31m%c\033[0m", '\xC0');
    for (i = 0; i < 59; i++)
    {
        printf("\033[31m%c\033[0m", '\xC4');
    }
    printf("\033[31m%c\033[0m\n", '\xD9');
    int tempo = 3000; /** 3 segundos */
    while (tempo > 0 && !_kbhit())
    {
        Sleep(100);   /** Espera 100ms */
        tempo -= 100; /** Diminui o tempo */
    }

    /** Limpa o buffer do teclado */
    if (kbhit())
    {
        _getch();
    }
}

//////////////////////////////////////////////////////

/**
 *
 * Função para exibir a lista de meios disponíveis para alugar.
 *
 */

void menuListarMeiosDisponiveis()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** Carrega os dados dos ficheiros. */
    meios = lerMeios();
    if (meios == NULL)
    {
        meios = lerMeiosBinario();
    }

    system("cls"); /** Limpa o ecrã do console */
    if (haMeiosDisponiveis(meios))
    {
        printf("\n");
        printf("\033[1m");
        imprimirCentrado(' ', "LISTAGEM DE MEIOS DE MOBILIDADE ELETRICA DISPONIVEIS PARA ALUGAR");
        printf("\033[0m\n");
        listarMeiosDisponiveis(meios);
    }
    else
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO HA MEIOS DISPONIVEIS PARA ALUGAR NESTE MOMENTO");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
    }
    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
    getch(); /** Espera o utilizador pressionar uma tecla */
}

/**
 *
 * Função para alugar um meio de mobilidade elétrica.
 *
 */

void menuAlugarMeio()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** @var Variável para armazenar a lista de clientes */
    Cliente *clientes = NULL;

    /** @var Variável para armazenar a lista de alugueres */
    Aluguer *alugueres = NULL;

    /** Variáveis para armazenar informações de meios */
    int meCod;

    /** Variáveis para armazenar informações de clientes */
    int cliNif;

    char criar, resp, confirma;

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
    alugueres = lerAlugueres();
    if (alugueres == NULL)
    {
        alugueres = lerAlugueresBinario();
    }

    bool exitLoop = false;

    exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */

    if (!haMeiosDisponiveis(meios))
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO HA MEIOS DISPONIVEIS PARA ALUGAR NESTE MOMENTO");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera o utilizador pressionar uma tecla */
        return;
    }

    Cliente *encontrarCliente = NULL;

    do
    {
        clientes = lerClientes();
        if (clientes == NULL)
        {
            clientes = lerClientesBinario();
        }
        alugueres = lerAlugueres();
        if (alugueres == NULL)
        {
            alugueres = lerAlugueresBinario();
        }
        system("cls"); /** Limpa o ecrã do console */
        printf("\n\n \033[7m Alugar meio de mobilidade eletrica \033[0m\n");
        printf(" \033[2m(Preencha os campos abaixo com as informacoes solicitadas)\033[0m\n\n");
        cliNif = intConfirmacao("Para alugar um meio, por favor insira o seu NIF: ", &exitLoop);
        if (exitLoop)
        {
            return;
        }
        encontrarCliente = procurarCliente(clientes, cliNif);
        if (!encontrarCliente)
        {
            printf("\n\033[31mNao encontramos nenhum registro correspondente ao cliente inserido\n");
            printf("Por favor, verifique se o NIF do cliente esta correto e tente novamente\033[0m\n");
            printf("\nSe e um novo cliente, deseja preencher a ficha de cliente? (S/N): ");
            scanf(" %c", &criar);
            if (criar == 'S' || criar == 's')
            {
                menuAdicionarCliente();
            }
        }
    } while (!encontrarCliente);
    system("cls"); /** Limpa o ecrã do console */
    printf("\n\n\033[1mBem-vindo(a) de volta, %s!\033[0m \033[2m(geocodigo atual: %s)\033[0m", encontrarCliente->clienteNome, encontrarCliente->clienteGeocodigo);
    printf("\nComo podemos ajuda-lo(a) a tornar sua proxima viagem com a \033[32mGreenGo\033[0m uma experiencia memoravel e agradavel?");
    printf("\n\n\n \033[2m(Introduza o valor \"S\" correspondente a Sim ou \"N\" correspondente a Nao)\033[0m");
    printf("\nDeseja ver os meios disponiveis para alugar? (S/N): ");
    scanf(" %c", &resp);
    printf("\n");
    if (resp == 'S' || resp == 's')
    {
        listarMeiosDisponiveisParaAlugar(meios, encontrarCliente->clienteGeocodigo);
    }
    meCod = intConfirmacao("\nInsira o codigo do meio que deseja alugar: ", &exitLoop);
    if (exitLoop)
    {
        return;
    }
    if (existeMeio(meios, meCod))
    {
        if (meioDisponivel(meios, meCod))
        {
            printf("\n \033[2m(Introduza o valor \"S\" correspondente a Sim ou \"N\" correspondente a Nao)\033[0m");
            printf("\nConfirma o aluguer do meio %d? (S/N): ", meCod);
            scanf("%c", &confirma);
            if (confirma == 'S' || confirma == 's')
            {
                alugueres = inserirAluguer(alugueres, cliNif, meCod);
                alugarMeio(meios, meCod);
                guardarAlugueres(alugueres);
                guardarAlugueresBinario(alugueres);
                printf("\n\n");
                imprimirLinha('\xC4');
                printf("\033[1m");
                imprimirCentrado(' ', "MEIO ALUGADO COM SUCESSO");
                printf("\033[0m\n");
                imprimirLinha('\xC4');
            }
        }
        else
        {
            printf("\n\n");
            imprimirLinha('\xC4');
            printf("\033[1m");
            imprimirCentrado(' ', "O MEIO DE DE MOBILIDADE ELETRICA INSERIDO JA ESTA ALUGADO");
            printf("\033[0m\n");
            imprimirLinha('\xC4');
            printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
            getch(); /** Espera que o utilizador pressionar uma tecla */
            return;
        }
    }
    else
    {
        printf("\n\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO ENCONTRAMOS NENHUM REGISTRO CORRESPONDENTE AO MEIO DE DE MOBILIDADE ELETRICA INSERIDO");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
        return;
    }
    printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
    getch(); /** Espera que o utilizador pressionar uma tecla */
}

/**
 *
 * Função para devolver um meio de mobilidade elétrica alugado.
 *
 */

void menuDevolverMeio()
{
    /** @var Variável para armazenar a lista de meios */
    Meio *meios = NULL;

    /** @var Variável para armazenar a lista de clientes */
    Cliente *clientes = NULL;

    /** @var Variável para armazenar a lista de alugueres */
    Aluguer *alugueres = NULL;

    /** @var Variável para armazenar a lista do grafo */
    Grafo *grafo = NULL;

    /** Variáveis para armazenar informações de meios */
    int meCod;

    /** Variáveis para armazenar informações de clientes */
    int cliNif;

    int tempoUtilizacao;

    char resp, confirma;

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
    alugueres = lerAlugueres();
    if (alugueres == NULL)
    {
        alugueres = lerAlugueresBinario();
    }

    grafo = lerGrafo("../db/grafo.txt");
    if (grafo == NULL)
    {
        grafo = lerGrafoBinario("../db/grafo.bin");
    }

    if (grafo == NULL)
    {
        menuCriarGrafo();
        grafo = lerGrafo("../db/grafo.txt");
        if (grafo == NULL)
        {
            grafo = lerGrafoBinario("../db/grafo.bin");
        }
    }

    bool exitLoop = false;

    exitLoop = false;

    system("cls"); /** Limpa o ecrã do console */

    if (alugueres == NULL)
    {
        printf("\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO HA REGISTOS DE ALUGUERES NESTE MOMENTO");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera o utilizador pressionar uma tecla */
        return;
    }

    Cliente *encontrarCliente = NULL;
    Aluguer *encontrarAluguer = NULL;

    printf("\n\n \033[7m Devolver meio de mobilidade eletrica \033[0m\n");
    printf(" \033[2m(Preencha os campos abaixo com as informacoes solicitadas)\033[0m\n\n");
    cliNif = intConfirmacao("Para devolver um meio, por favor insira o seu NIF: ", &exitLoop);
    if (exitLoop)
    {
        return;
    }
    encontrarCliente = procurarCliente(clientes, cliNif);
    encontrarAluguer = procurarAluguerPorNIF(alugueres, cliNif);
    if (encontrarAluguer)
    {
        system("cls"); /** Limpa o ecrã do console */
        printf("\n\n\033[1mBem-vindo(a) de volta, %s!\033[0m", encontrarCliente->clienteNome);
        printf("\nComo podemos ajuda-lo(a) a tornar sua proxima viagem com a \033[32mGreenGo\033[0m uma experiencia memoravel e agradavel?");
        printf("\n\n\n \033[2m(Introduza o valor \"S\" correspondente a Sim ou \"N\" correspondente a Nao)\033[0m");
        printf("\nDeseja ver a lista de meios alugados? (S/N): ");
        scanf(" %c", &resp);
        if (resp == 'S' || resp == 's')
        {
            listarMeiosPorNIF(alugueres, cliNif);
        }
        meCod = intConfirmacao("\n > Insira o codigo do meio que deseja devolver: ", &exitLoop);
        if (exitLoop)
        {
            return;
        }
        if (existeAluguer(alugueres, cliNif, meCod))
        {
            char geocodigoOrigem[100];
            char geocodigoDestino[100];

            /** Obter o geocódigo do meio selecionado */
            Meio *meioSelecionado = obterMeioPorCodigo(meios, meCod);
            if (meioSelecionado == NULL)
            {
                printf("Meio não encontrado.\n");
                return;
            }

            strcpy(geocodigoOrigem, meioSelecionado->meioGeocodigo);

            /** Criar uma lista de geocódigos adjacentes disponíveis */
            char *geocodigosAdjacentes[] = {
                "///davam.nele.solda",
                "///alpinos.contributivo.cintila",
                "///facial.jogam.chame",
                "///pediu.flui.bica",
                "///redor.belo.ligam",
                "///massas.faixa.selos",
                "///idosa.fraca.jogamos",
                "///merece.irem.alcancei",
                "///lesmas.chorar.folga",
                "///redor.olhe.atol",
                "///sulcar.desfastio.adubar"};
            int numAdjacentes = sizeof(geocodigosAdjacentes) / sizeof(geocodigosAdjacentes[0]);

            /** Exibir apenas os geocódigos adjacentes */
            printf("\nGeocodigos adjacentes:\n");
            int contador = 1;
            for (int i = 0; i < numAdjacentes; i++)
            {
                if (strcmp(geocodigosAdjacentes[i], geocodigoOrigem) != 0)
                {
                    printf(" %d. %s\n", contador, geocodigosAdjacentes[i]);
                    contador++;
                }
            }

            int opcao;
            do
            {
                opcao = intConfirmacao("\nEscolha a opcao correspondente ao geocodigo de destino desejado: ", &exitLoop);
                if (exitLoop)
                {
                    return;
                }

                if (opcao < 1 || opcao > numAdjacentes - 1)
                {
                    printf(" \033[2m(Valor do geocodigo invalido. Escolha uma das opcoes entre 1 e %d)\033[0m\n", numAdjacentes);
                }
                else
                {
                    strcpy(geocodigoDestino, geocodigosAdjacentes[opcao - 1]);
                }
            } while (opcao < 1 || opcao > numAdjacentes - 1);
            float distancia = obterDistanciaAdjacente(grafo, geocodigoOrigem, geocodigoDestino);
            tempoUtilizacao = intConfirmacao("\n > Insira quantos minutos utilizou o meio alugado: ", &exitLoop);
            printf("\n \033[2m(Introduza o valor \"S\" correspondente a Sim ou \"N\" correspondente a Nao)\033[0m");
            printf("\nConfirma o devolucao do meio %d? (S/N): ", meCod);
            scanf("%c", &confirma);
            if (confirma == 'S' || confirma == 's')
            {
                devolverMeio(meios, alugueres, clientes, cliNif, meCod, tempoUtilizacao, distancia, geocodigoDestino);
                printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                getch(); /** Espera que o utilizador pressionar uma tecla */
            }
        }
        else
        {
            printf("\n\n");
            imprimirLinha('\xC4');
            printf("\033[1m");
            imprimirCentrado(' ', "O MEIO ESPECIFICADO NAO FOI ALUGADO POR ESTE CLIENTE");
            printf("\033[0m\n");
            imprimirLinha('\xC4');
            printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
            getch(); /** Espera que o utilizador pressionar uma tecla */
            return;
        }
    }
    else if (encontrarAluguer == NULL)
    {
        printf("\n\n");
        imprimirLinha('\xC4');
        printf("\033[1m");
        imprimirCentrado(' ', "NAO HA ALUGUERES ASSOCIADOS A ESTE NIF");
        printf("\033[0m\n");
        imprimirLinha('\xC4');
        printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
        getch(); /** Espera que o utilizador pressionar uma tecla */
        return;
    }
}