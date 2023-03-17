#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> // inclua esta biblioteca para usar a função kbhit()

#include "meio.h"
#include "gestor.h"
#include "cliente.h"


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
	printf("\t| 1. Inserir Meio                   |\n");
	printf("\t| 2. Remover Meio                   |\n");
	printf("\t| 3. Listar Meios                   |\n");
	printf("\t| 4. Guardar Meios                  |\n");
	printf("\t| 5. Ler Meios                      |\n");
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
    static int cod = 1;

    do
    {
        op_p = menu_principal();
        switch(op_p)
        {
			case 1:
                meios = lerMeios();
                meios = lerMeiosBinario();
                do
                {
                    op_meio = menu_meio();
                    switch(op_meio)
                    {
                        case 1: // Inserir meio
                            printf("Tipo\n");
                            scanf("%s",tipo);
                            printf("Nivel da bateria?\n");
                            scanf("%f",&bat);
                            printf("Autonomia\n");
                            scanf("%f",&aut);
                            meios = inserirMeio(meios,cod,tipo,bat,aut);
                            printf("O seu codigo e %d\n", cod);
                            cod++;
                            printf("Pressione qualquer tecla para continuar...");
                            getch(); // Espera o usuário pressionar uma tecla
                            break;
                        case 2: // Remover meio
                            printf("Codigo do meio de mobilidade a remover?\n");
                            scanf("%d",&cod);
                            meios = removerMeio(meios, cod);
                            break;
                        case 3: // Listar meios
                            if (meios == NULL)
                            {
                                printf("Nao ha\n");
                            }
                            else
                            {
                                listarMeios(meios);
                            }
                            printf("Pressione qualquer tecla para continuar...");
                            getch(); // Espera o usuário pressionar uma tecla
                            break;
                        case 4: // Guardar meios
                            guardarMeios(meios);
                            guardarMeiosBinario(meios);
                            break;
                        case 5: // Ler meios
                            meios = lerMeios();
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