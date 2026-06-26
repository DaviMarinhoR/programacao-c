#include <stdio.h>

struct registro{
    char nome[50];
    float altura;
};

void menu(){
    printf("\n=====MENU=====\n");
    printf("1.Cadastrar os 15 registros.\n");
    printf("2.Apresentar os registros das pessoas com 1.50 m ou menores.\n");
    printf("3.Apresentar os registros das pessoas maiores que 1.50 m.\n");
    printf("4.Apresentar os registros das pessoas com mais de 1.50 m e menos de 2.0 m.\n");
    printf("5.Apresentar todos os registros com a média extraída detodas as alturas armazenadas.\n");
    printf("6.Sair do programa.\n");
}
int main(){

    struct registro cadastro[15];
    float mediaDeTodasAsAlturas, soma = 0;
    int opcao, cadastrado = 0;
    int i;

    do{
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
        case 1:
            printf("\nCadastro a seguir:\n");
            for(i = 0; i < 15; i++){
                printf("Cadastro %d\n", i + 1);
                printf("\nNome: ");
                scanf(" %[^\n]", cadastro[i].nome);

                printf("Altura: ");
                scanf("%f", &cadastro[i].altura);
            }

            for(i = 0; i < 15; i++){
                soma += cadastro[i].altura;
            }
                mediaDeTodasAsAlturas = soma / 15.0;
            
            cadastrado = 1;
            break;
        
            case 2:
            if(cadastrado == 0){
            printf("\nCadastre os alunos primeiro!\n");
            break;
            }
            for(i = 0; i < 15; i++){
            if(cadastro[i].altura <= 1.50){
            printf("\nNome: %s", cadastro[i].nome);
            printf("Altura: %.2f", cadastro[i].altura);
            }
            }
            break;
            
            case 3:
            if(cadastrado == 0){
            printf("\nCadastre os alunos primeiro!\n");
            break;
            }
            for(i = 0; i < 15; i++){
                if(cadastro[i].altura > 1.50){
                    printf("\nNome: %s", cadastro[i].nome);
                    printf("Altura: %.2f", cadastro[i].altura);
                }
            }
            break;
            case 4:
            if(cadastrado == 0){
            printf("\nCadastre os alunos primeiro!\n");
            break;
            }
            for(i = 0; i < 15; i++){
                if(cadastro[i].altura > 1.50 && cadastro[i].altura < 2.00){
                    printf("\nNome: %s", cadastro[i].nome);
                    printf("Altura: %.2f", cadastro[i].altura);
                }
            }
            break;

            case 5:
            if(cadastrado == 0){
                printf("\nCadastre os alunos primeiro!\n");
                break;
            }

                for(i = 0; i < 15; i++){
                    printf("\nNome: %s", cadastro[i].nome);
                    printf("Altura: %.2f", cadastro[i].altura);
                }
                printf("\nMédia de todas as alturas: %.2f", mediaDeTodasAsAlturas);
            
            break;

            case 6:
            printf("\nSaindo...");

            break;

            default:
            printf("\nOpção inválida!\n");

            break;
        }
        
    }while(opcao != 6);

    return 0;
}