#include <stdio.h>
#include <string.h>

struct registroEscolar{

    char nome[50];
    float notas[4];

};

void menu(){
        printf("\n====MENU====\n");
        printf("1 - Cadastrar um aluno.\n");
        printf("2 - Pesquisar situação de um aluno.\n");
        printf("3 - Mostrar todos os registros.\n");
        printf("4 - Sair.\n");
}

int main(){

    struct registroEscolar registro[20];
    struct registroEscolar aux;

    int inicio, meio, fim, encontrou = 0;
    float mediaDosAlunos[20], media, soma;
    char pesquisa[50];
    int opcao;
    int i, j;
    int cadastrado = 0;

    do{

        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
            printf("\nCadastro com nome e notas bimestrais a seguir: \n");
            for(i = 0; i < 20; i++){
            printf("Nome[%d]: ", i + 1);
            scanf(" %[^\n]", registro[i].nome);

            for(j = 0; j < 4; j++){
            printf("Bimestre %d: ", j + 1);
            scanf("%f", &registro[i].notas[j]);
            }
            }

            for(i = 0; i < 19; i++){
            for(j = i + 1; j < 20; j++){
            if(strcmp(registro[i].nome, registro[j].nome) > 0){
                aux = registro[i];
                registro[i] = registro[j];
                registro[j] = aux;
                }
            }
        }
            
            for(i = 0; i < 20; i++){
            soma = 0;
            for(j = 0; j < 4; j++){
            soma +=registro[i].notas[j];
            }
            mediaDosAlunos[i] = soma / 4;
            }
            cadastrado = 1;
            break;
            
            case 2:
            if(cadastrado == 0){
            printf("Cadastre os alunos primeiro!\n");
            break;
            }

            printf("\nNome dos alunos em ordem alfábetica:\n");
            for(i = 0; i < 20; i++){
                printf("Aluno %d: %s\n", i + 1, registro[i].nome);
            }

            printf("Apresentar a média de qual aluno? ");
            scanf(" %[^\n]", pesquisa);

            encontrou = 0;
            inicio = 0;
            fim = 19;

            while(inicio <= fim){

            meio = (inicio + fim) / 2;

            if(strcmp(registro[meio].nome, pesquisa ) == 0){
            encontrou = 1;
            break;
            }
            else if(strcmp(pesquisa, registro[meio].nome) < 0){
            fim = meio - 1;
            }
            else{
            inicio = meio + 1;      
            }
        }
    
            if(encontrou == 1){
                printf("Média: %f", mediaDosAlunos[meio]);
    
                printf("\nSituação: \n");
            if(mediaDosAlunos[meio] >= 5){
                printf("Aprovado");
            }else{
                printf("Reprovado");
            }
        }

            if(encontrou == 0){
                printf("\nAluno não encontrado entre os registros.\n");
            }
            break;

            case 3: 
            if(cadastrado == 0){
            printf("Cadastre os alunos primeiro!\n");
            break;
            }
                printf("\nTODOS OS REGISTROS: \n");
            for(i = 0; i < 20; i++){
                printf("Nome: %s\n", registro[i].nome);
                printf("Média: %.2f\n", mediaDosAlunos[i]);
                printf("Situação: ");
            if(mediaDosAlunos[i] >= 5){
                printf("Aprovado\n");
            }else{
                printf("Reprovado\n");
            }
            }   
            break;

            case 4:

                printf("Saindo...\n");
            break;

            default:
                printf("Opção inválida!");
            break;

        }

    } while(opcao != 4);

    return 0;
}