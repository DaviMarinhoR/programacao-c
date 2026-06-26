#include <stdio.h>
#include <string.h>

struct Agenda{
    char nome[50];
    char endereco[50];
    char telefone[50];
};

void menu(){
    printf("\nMENU\n");
    printf("1. Cadastrar os 10 registros.\n");
    printf("2. Pesquisar registro por nome.\n");
    printf("3. Classificar por nome.\n");
    printf("4. Apresentar todos os registros.\n");
    printf("5. Sair.\n");

}
int main(){

    struct Agenda contatos[10];

    int opcao;
    int i, j;

    do{
        menu();
        scanf("\nEscolha uma opção: %d", &opcao);
        switch(opcao){
            case 1:
            for(i = 0; i < 10; i++){
                printf("Cadastro %d\n", i + 1);

                printf("Nome: ");
                scanf(" %[^\n]", contatos[i].nome);

                printf("Endereço: ");
                scanf(" %[^\n]", contatos[i].endereco);

                printf("Telefone: ");
                scanf(" %[^\n]", contatos[i].telefone);
            }
            break;

            case 2:

            char valor[50];
            int encontrou = 0;

            printf("Qual nome deseja pesquisar? ");
            scanf(" %[^\n]", valor);

            for(i = 0; i < 10; i++){
                if(strcmp(valor, contatos[i].nome) == 0){
                    printf("Encontrado na posição %d\n", i);
                    printf("Nome: %s", contatos[i].nome);
                    printf("Endereço: %s", contatos[i].endereco);
                    printf("Telefone: %s", contatos[i].telefone);
                    encontrou = 1;
                    break;
                }
            }
            if(encontrou == 0){
                printf("Registro não encontrado");
            }
            break;

            case 3: {
            struct Agenda aux;

            for(i = 0; i < 9; i++){
                for(j = i + 1; j < 10; j++){
                    if(strcmp(contatos[i].nome, contatos[j].nome) > 0){
                        aux = contatos[i];
                        contatos[i] = contatos[j];
                        contatos[j] = aux;
                    }
                }
            }
            printf("Ordenação concluída!\n");
            break;
        }
            case 4:

            printf("\nREGISTROS: \n");

            for(i = 0; i < 10; i++){
                printf("Registro %d\n", i + 1);
                printf("Nome: %s\n", contatos[i].nome);
                printf("Endereço: %s\n", contatos[i].endereco);
                printf("Telefone: %s\n", contatos[i].telefone);
            }
            break;

            case 5:
            printf("Saindo...\n");
            break;
            
            default:
            printf("Opção inválida!\n");
            break;
        }
    }while(opcao != 5);
    

    return 0;
}