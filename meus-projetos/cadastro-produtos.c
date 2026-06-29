#include <stdio.h>

struct cadastroProdutos{
    int codigo;
    char nome[50];
    float preco;
};

void menu(){
    printf("\n======MENU======\n");
    printf("1.Cadastrar os 20 produtos.\n");
    printf("2.Classificar os registros por codigo.\n");
    printf("3.Pesquisar por um produto.\n");
    printf("4.Apresentar, de forma ordenada, os registros dos produtos com preço acima de R$ 100,00\n");
    printf("5.Apresentar, de forma ordenada, os registros dos produtos com preço entre R$ 50,00 e R$ 100,00.\n");
    printf("6.Apresentar, de forma ordenada, os registros dos produtos com preço abaixo de R$ 50,00\n");
    printf("7.Apresentar todos os registros e informar o preço médio dos produtos cadastrados.\n");
    printf("8.Sair do programa\n");
}

int main(){

    struct cadastroProdutos registro[20];
    struct cadastroProdutos aux;
    float precoMedio, somaPrecos;
    int opcao, pesquisa, cadastrado = 0, ordenado = 0;
    int inicio, meio, fim, encontrou;
    int achouRegistro;
    int i, j;

    do{
        menu();
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
            for(i = 0; i < 20; i++){
                printf("\nCADASTRO %d:\n", i + 1);
                printf("\nCódigo: ");
                scanf("%d", &registro[i].codigo);

                printf("\nNome: ");
                scanf(" %[^\n]", registro[i].nome);

                printf("\nPreço: ");
                scanf("%f", &registro[i].preco);
            }

            somaPrecos = 0;
            for(i = 0; i < 20; i++){
                somaPrecos += registro[i].preco;
            }
            precoMedio = somaPrecos / 20.0;

            cadastrado = 1;
            ordenado = 0;

            break;

            case 2:
            
            if(cadastrado == 0){
                printf("\nCadastre os produtos primeiro!\n");
                
                break;
            }

            for(i = 0; i < 19; i++){
                for(j = i + 1; j < 20; j++){
                    if(registro[i].codigo > registro[j].codigo){
                        aux = registro[i];
                        registro[i] = registro[j];
                        registro[j] = aux;
                    }
                }
            }

            printf("\nOrdenação concluída.\n");
            ordenado = 1;
        
            break;

            case 3:

            if(cadastrado == 0){
                printf("\nCadastre os produtos primeiro!\n");
                
                break;
            }

            if(ordenado == 0){
                printf("\nUtilize a opção 2 para ordenar os registros.\n");

                break;
            }
            printf("\nPesquise por um produto (codigo): ");
            scanf("%d", &pesquisa);

            encontrou = 0;
            inicio = 0;
            fim = 19;

            while(inicio <= fim){
                meio = (inicio + fim) / 2;

                if(registro[meio].codigo == pesquisa){
                    encontrou = 1;
                    break;
                }
                else if(pesquisa < registro[meio].codigo){
                    fim = meio - 1;
                }
                else{
                    inicio = meio + 1;
                }
            }

            if(encontrou == 1){
                printf("\nCódigo: %d\n", registro[meio].codigo);
                printf("Nome: %s\n", registro[meio].nome);
                printf("Preço: %.2f\n", registro[meio].preco);
            }
            else{
                printf("\nProduto não encontrado entre os registros.\n");
            }

            break;

            case 4: 

            if(cadastrado == 0){
                printf("\nCadastre os produtos primeiro!\n");
                
                break;
            }
            if(ordenado == 0){
                printf("\nUtilize a opção 2 para ordenar os registros.\n");

                break;
            }
            achouRegistro = 0;

            for(i = 0; i < 20; i++){
                if(registro[i].preco > 100.0){
                    printf("\nCódigo: %d\n", registro[i].codigo);
                    printf("Nome: %s\n", registro[i].nome);
                    printf("Preço: %.2f\n", registro[i].preco);
                    achouRegistro = 1;
                }
            }

            if(achouRegistro == 0){
                printf("\nSem registros.\n");
            }

            break;

            case 5:

            if(cadastrado == 0){
                printf("\nCadastre os produtos primeiro!\n");
                
                break;
            }

            if(ordenado == 0){
                printf("\nUtilize a opção 2 para ordenar os registros.\n");

                break;
            }
            achouRegistro = 0;

            for(i = 0; i < 20; i++){
                if(registro[i].preco > 50.0 && registro[i].preco < 100.0){
                    printf("\nCódigo: %d\n", registro[i].codigo);
                    printf("Nome: %s\n", registro[i].nome);
                    printf("Preço: %.2f\n", registro[i].preco);
                    achouRegistro = 1;
                }
            }

            if(achouRegistro == 0){
                printf("\nSem registros.\n");
            }


            break;

            case 6:

            if(cadastrado ==0){
                printf("\nCadastre os produtos primeiro!\n");
                
                break;
            }
                        if(ordenado == 0){
                printf("\nUtilize a opção 2 para ordenar os registros.\n");

                break;
            }
            achouRegistro = 0;

            for(i = 0; i < 20; i++){
                if(registro[i].preco < 50.0){
                    printf("\nCódigo: %d\n", registro[i].codigo);
                    printf("Nome: %s\n", registro[i].nome);
                    printf("Preço: %.2f\n", registro[i].preco);
                    achouRegistro = 1;
                }
            }

            if(achouRegistro == 0){
                printf("\nSem registros.\n");
            }

            break;

            case 7:

            if(cadastrado == 0){
                printf("\nCadastre os produtos primeiro!\n");
                
                break;
            }

            for(i = 0; i < 20; i++){
                printf("\nCADASTRO %d\n", i + 1);
                printf("Código: %d\n", registro[i].codigo);
                printf("Nome: %s\n", registro[i].nome);
                printf("Preço: %.2f\n", registro[i].preco);
            }
            printf("\nMédia do preço dos produtos: %.2f\n", precoMedio);

            break;

            case 8:

            printf("\nSaindo...\n");

            break;

            default:

            printf("\nOpção inválida.\n");

            break;
        }
    }while(opcao != 8);
    return 0;
}