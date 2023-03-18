#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> // inclua esta biblioteca para usar a função kbhit()

#include "meio.h"
#include "gestor.h"
#include "cliente.h"

/*int lerCodigo() {
    FILE *fp = fopen("meios.txt", "r");
    int cod = 1, max_cod = 0;
    if (fp) {
        while (fscanf(fp, "%d", &cod) == 1) { // lê cada número do arquivo
            if (cod > max_cod) { // verifica se é maior que o valor máximo encontrado até agora
                max_cod = cod; // atualiza o valor máximo encontrado
            }
        }
        fclose(fp);
    }
    return max_cod;
}*/

/*int lerCodigo() {
    FILE *fp = fopen("meios.txt", "r");
    int cod = 1;
    if (fp) {
        fscanf(fp, "%d", &cod);
        fclose(fp);
    }
    return cod;
}*/

/*void gravarCodigo(int cod) {
    FILE *fp = fopen("meios.txt", "w");
    if (fp) {
        fprintf(fp, "%d", cod);
        fclose(fp);
    }
}*/

void loading()
{
	printf("\033[32m\n\n\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd Bem-vindo(a) a GreenGo! \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\033[0m\n");
	printf("\nA GreenGo e uma empresa de mobilidade eletrica que oferece solucoes de transporte sustentavel para pessoas e empresas. \nCom a nossa frota de veiculos eletricos, ajudamos a reduzir as emissoes de CO2 e a preservar o meio ambiente.\n\n\n");
	printf("2023 - Todos os direitos reservados");

	// Inicialize a variável "time_elapsed" com 0
	int time_elapsed = 0;

	// Execute o loop do sleep até que 10 segundos sejam alcançados ou o usuário pressione uma tecla
	while (time_elapsed < 10000 && !kbhit()) {
		Sleep(100); // Aguarde 100 milissegundos de cada vez
		time_elapsed += 100; // Atualize o tempo decorrido
	}

	// Limpe o buffer do teclado
	if (kbhit()) {
		_getch();
	}

	system("cls");
}


int menu_principal()
{
    int op_p;
    system("cls");
	printf("\n\n\t=====================================\n");
    printf("\t|          Menu  Principal          |\n");
    printf("\t=====================================\n");
    printf("\t| 1. Meio de mobilidade eletrica    |\n");
    printf("\t| 2. Cliente                        |\n");
    printf("\t| 3. Gestor                         |\n");
    printf("\t|                                   |\n");
	printf("\t|                           \033[31m0. Sair\033[0m |\n");
    printf("\t=====================================\n");
	printf("\n > Digite a sua escolha: ");
    scanf("%d",&op_p);
    return(op_p);
}

int menu_meio()
{
    int op_meio;
    system("cls");
	printf("\n\n\t=====================================\n");
	printf("\t|    Meio de mobilidade eletrica    |\n");
	printf("\t=====================================\n");
	printf("\t| 1. Adicionar Meio                 |\n");
	printf("\t| 2. Remover Meio                   |\n");
	printf("\t| 3. Listar Todos os Meios          |\n");
	printf("\t|                                   |\n");
	printf("\t| 9. Anterior               \033[31m0. Sair\033[0m |\n");
	printf("\t=====================================\n");
	printf("\n > Digite a sua escolha: ");
   	scanf("%d",&op_meio);
    return op_meio;
}

int main()
{
    loading();
    Meio *meios = NULL; // Lista ligada vazia
	Cliente *clientes = NULL; // Lista ligada vazia
	struct Gestor gestor_admin = {"admin", "admin"};
    int op_p, op_meio, op_cliente, numcliente;
    float bat, aut;
    char tipo[50], input_username[20], input_password[20], nome[50], email[50], tel[15], morada[100];
    int cod = 1;

    do
    {
        op_p = menu_principal();
        switch(op_p)
        {
			case 1:
                do
                {
                    meios = lerMeios();
                    meios = lerMeiosBinario();
                    op_meio = menu_meio();
                    switch(op_meio)
                    {
                        case 1: // Inserir meio
                            system("cls");
                            printf("\n\n\t\tNovo Meio de mobilidade eletrica\n");
                            printf("\t\033[2m(preencha os campos abaixo com as informacoes solicitadas)\033[0m\n\n");
                            printf(" > Tipo de mobilidade eletrica: ");
                            scanf("%s", &tipo);
                            printf(" > Nivel da bateria: ");
                            do {
                                getchar();
                                scanf("%f", &bat);
                                if (bat < 0 || bat > 100) 
                                {
                                    printf("\033[2mValor invalido para o nivel da bateria. O nivel da bateria e representado em percentagem de 0 a 100%%\033[0m\n");
                                    printf(" > Reintroduza o nivel da bateria: ");
                                } 
                            } while (bat < 0 || bat > 100);
                            printf(" > Autonomia: ");
                            scanf("%f", &aut);
                            cod = inserirMeio(&meios, cod, tipo, bat, aut);
                            printf("\n\t\033[5m\033[4m%d\033[0m é o código atribuído a este meio de mobilidade elétrica!\n", cod);
                            guardarMeios(meios);
                            guardarMeiosBinario(meios);
                            printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                            getch(); // Espera o usuário pressionar uma tecla
                            getchar();
                            break;
                        case 2: // Remover meio
                            printf("Codigo do meio de mobilidade a remover?\n");
                            scanf("%d",&cod);
                            meios = removerMeio(meios, cod);
                            guardarMeios(meios);
                            guardarMeiosBinario(meios);
                            getchar();
                            break;
                        case 3: // Listar meios
                            system("cls");
                            if (meios == NULL)
                            {
                                printf("Nao ha\n");
                            }
                            else
                            {
                                printf("\nLista de meios de mobilidade eletrica\n");
                                listarMeios(meios);
                            }
                            printf("\n\033[31mPressione qualquer tecla para continuar...\033[0m");
                            getch(); // Espera o usuário pressionar uma tecla
                            getchar();
                            break;           
                        case 9: break; // Voltar para o menu anterior
                    }
                }
                while(op_meio != 0 && op_meio != 9);
                if (op_meio != 9)
                {
                    return 0;
                }
                break;
        }
    }
    while (op_p!=0);
 }