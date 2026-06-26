#include <stdio.h>

struct registroFuncionarios{
    char nome[50];
    int matricula;
    float salario;
};

void menu(){
    printf("\n==========MENU==========\n");
    printf("1.Cadastrar os 20 empregados.\n");
    printf("2.Classificar os registros por número de matrícula.\n");
    printf("3.Pesquisar um determinado empregado pelo número de matrícula.\n");
    printf("4.Apresentar de forma ordenada os registros dos empregados que recebem salários acima de R$ 1.000.\n");
    printf("5.Apresentar de forma ordenada os registros dos empregados que recebem salários abaixo de R$ 1.000.\n");
    printf("6.Apresentar de forma ordenada os registros dos empregados que recebem salários iguais a R$ 1.000.\n");
    printf("7.Sair do programa de cadastro.\n");

}

int main(){

    struct registroFuncionarios cadastro[20];
    struct registroFuncionarios aux;
    int opcao, pesquisa, ordenado = 0, cadastrado = 0;
    int inicio, meio, fim, encontrou = 0;
    int achouSalario = 0;
    int i, j;

    do{
        menu();
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
            for(i = 0; i < 20; i++){
                printf("\nCADASTRO %d", i + 1);

                printf("\nNome: ");
                scanf(" %[^\n]", cadastro[i].nome);

                printf("\nMatrícula: ");
                scanf("%d", &cadastro[i].matricula);

                printf("\nSalário: ");
                scanf("%f", &cadastro[i].salario);
            }
            cadastrado = 1;
            ordenado = 0;

            break;

            case 2:
            if(cadastrado == 0){
                printf("\nCadastre os funcionários primeiro!\n");

                break;
            }

            for(i = 0; i < 19; i++){
                for(j = i + 1; j < 20; j++){
                    if(cadastro[i].matricula > cadastro[j].matricula){
                        aux = cadastro[i];
                        cadastro[i] = cadastro[j];
                        cadastro[j] = aux;
                    }
                }
            }
            printf("\nOrdem estabelecida!\n");

            ordenado = 1;
            break;

            case 3:
             if(cadastrado == 0){
                printf("\nCadastre os funcionários primeiro!\n");
                break;
            }
            if(ordenado == 0){
                printf("\nUtilize a opção 2 para organizar os registros primeiro.\n");
                break;
            }

            printf("\n\nQual registro deseja ver (matrícula): ");
            scanf("%d", &pesquisa);

            encontrou = 0;
            inicio = 0;
            fim = 19;

            while(inicio <= fim){
                meio = (inicio + fim) / 2;

                if(cadastro[meio].matricula == pesquisa){
                    encontrou = 1;
                    break;
                }
                else if(pesquisa < cadastro[meio].matricula){
                    fim = meio - 1;
                }
                else{
                    inicio = meio + 1;
                }
            }
            if(encontrou == 1){
                printf("\nNome: %s\n", cadastro[meio].nome);
                printf("Matrícula: %d\n", cadastro[meio].matricula);
                printf("Salário: %.2f\n", cadastro[meio].salario);
            }
            else{
                printf("\nMatrícula não encontrada!\n");
            }

            break;

            case 4:
             if(cadastrado == 0){
                printf("\nCadastre os funcionários primeiro!\n");
                break;
            }
            achouSalario = 0;

            for(i = 0; i < 20; i++){
                if(cadastro[i].salario > 1000.0){
                    printf("\nNome: %s\n", cadastro[i].nome);
                    printf("Matrícula: %d\n", cadastro[i].matricula);
                    printf("Salário: %.2f\n", cadastro[i].salario);
                    achouSalario = 1;
                }
            }            
            if(achouSalario == 0){
                printf("\nNão há funcionários com salário acima de R$ 1000.\n");
            }

            break;

            case 5:
             if(cadastrado == 0){
                printf("\nCadastre os funcionários primeiro!\n");
                break;
            }
            achouSalario = 0;

            for(i = 0; i < 20; i++){
                if(cadastro[i].salario < 1000.0){
                    printf("\nNome: %s\n", cadastro[i].nome);
                    printf("Matrícula: %d\n", cadastro[i].matricula);
                    printf("Salário: %.2f\n", cadastro[i].salario);
                    achouSalario = 1;
                }
            }            
            if(achouSalario == 0){
                printf("\nNão há funcionários com salário menor de R$ 1000.\n");
            }

            break;

            case 6:
             if(cadastrado == 0){
                printf("\nCadastre os funcionários primeiro!\n");
                break;
            }
             achouSalario = 0;

            for(i = 0; i < 20; i++){
                if(cadastro[i].salario == 1000.0){
                    printf("\nNome: %s\n", cadastro[i].nome);
                    printf("Matrícula: %d\n", cadastro[i].matricula);
                    printf("Salário: %.2f\n", cadastro[i].salario);
                    achouSalario = 1;
                }
            }
            if(achouSalario == 0){
                printf("\nNão há funcionários com salário igual à R$ 1000.\n");
            }

            break;

            case 7:
            printf("\nSaindo...\n");

            break;

            default:
            printf("\nOpção inválida!\n");

            break;
        }

    }while(opcao != 7);

    return 0;
}