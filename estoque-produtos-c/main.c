#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

// Requisitos:

    // Criar um struct Produto com:
    // nome (string)
    // código (int)
    // preço (float)
    // quantidade (int)
    // Criar um vetor de Produto com até 10 unidades.
    
    // Criar um menu com as opções:
    // Cadastrar novo produto
    // Listar todos os produtos
    // Buscar produto por código
    // Atualizar quantidade de um produto
    // Sair
    // Cada opção deve ser uma função separada, e o programa principal só chama as funções.

int totalProdutos = 0;
int proximoIdentificador = 1;

struct produto{
    char nome[15];
    int codigo;
    float preco;
    int quantidade;
    int identificador;
};

struct produto produtos[10];

void cadastrarProduto(){
    if(totalProdutos >= 10){
        printf("\nErro! O limite de produtos registrado foi atingido\n");
        return;
    }

    printf("\nDigite o nome do produto: \n");
    fgets(produtos[totalProdutos].nome, 15, stdin);
    produtos[totalProdutos].nome[strcspn(produtos[totalProdutos].nome, "\n")] = '\0';

    printf("Digite o código do produto: \n");
    scanf("%d", &produtos[totalProdutos].codigo);

    printf("Digite o preço do produto: \n");
    scanf("%f", &produtos[totalProdutos].preco);

    printf("Digite a quantidade deste produto no estoque: \n");
    scanf("%d", &produtos[totalProdutos].quantidade);
    while(getchar() != '\n'); 
    
    produtos[totalProdutos].identificador = proximoIdentificador;
    proximoIdentificador++;
    totalProdutos++;

    printf("O identificador do produto é: %d \n", produtos[totalProdutos].identificador);
    
    system("cls");

    printf("\nProduto cadastrado com sucesso!\n");
}

void listarProdutos(){
    int i;

    if(totalProdutos == 0){
        printf("\nNenhum produto cadastrado! \n");
        return;
    }

    for(i = 0; i < totalProdutos; i++){
        printf("\n Produto %d \n", i + 1);
        printf("nome: %s \n", produtos[i].nome);
        printf("código: %d \n", produtos[i].codigo);
        printf("preço: %.2f \n", produtos[i].preco);
        printf("quantidade: %d \n", produtos[i].quantidade);
        printf("O identificador do produto é: %d \n", produtos[i].identificador);
        printf("----------------------------------------------------------- \n");
    }
}

void buscarProduto(){
    int codigo;
    int i;
    int encontrado = 0;
    printf("\nDigite o código do produto que você deseja buscar: \n");
    scanf("%d", &codigo);
    while(getchar() != '\n');

    for(i = 0; i < totalProdutos; i++){
        if(codigo == produtos[i].codigo){
            printf("\n Produto: \n");
            printf("Nome: %s \n", produtos[i].nome);
            printf("Código: %d \n", produtos[i].codigo);
            printf("Preço: %.2f \n", produtos[i].preco);
            printf("Quantidade: %d \n", produtos[i].quantidade);
            printf("O identificador do produto é: %d \n", produtos[i].identificador);
            encontrado = 1;
        }
    
    }

    if(encontrado == 0){
        printf("\nCódigo digitado inválido! \n");
    }
}

void atualizarQuantidade(){
    int identificador;
    int i;
    int achou = 0;
    printf("\nDigite o identificador do produto: \n");
    scanf("%d", &identificador);
    for(i = 0; i < totalProdutos; i++){
        if(identificador == produtos[i].identificador){
            printf("\nDigite o valor atualizado da quantidade do produto %s: \n", produtos[i].nome);
            scanf("%d", &produtos[i].quantidade);
            achou = 1;
            printf("\nQuantidade atualizada com sucesso!\n");
            return;
        }
    }

    if(identificador <= 0 || identificador > totalProdutos){
        printf("\nO identificador é inválido! \n");
        return;
    }

}

void excluirProduto(){
    int identificador;
    int i, j, achou;

    printf("\nDigite o identificador do produto que deseja excluir \n");
    scanf("%d", &identificador);

    for(i = 0; i < totalProdutos; i++){
        if(produtos[i].identificador == identificador){
            achou = 1;

            printf("O produto %s com o identificador %d será excluído \n", produtos[i].nome, identificador);

            for(j = i; j < totalProdutos - 1; j++){
                produtos[j] = produtos[j + 1];
            }

            totalProdutos--;

            printf("\nO Produto foi excluído com sucesso \n");
            return;
        }
    }

    if(achou == 0){
        printf("\nIdentificador %d inválido\n", identificador); 
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);

    int opcao;

    while(1){

        printf("\n\t\t Menu \n");
        printf("\nDigite 1 para cadastrar um novo produto \n");
        printf("Digite 2 para mostrar todos os produtos \n");
        printf("Digite 3 para buscar um produto pelo código \n");
        printf("Digite 4 para atualizar a quantidade de um produto em estoque \n");
        printf("Digite 5 para a exclusão de algum produto desejado \n");
        printf("Digite 6 para sair \n");
        scanf("%d", &opcao);
        while(getchar() != '\n');

        switch(opcao){
            case 1: {
                cadastrarProduto();
                break;
            }
            case 2: {
                listarProdutos();
                break;
            }
            case 3: {
                buscarProduto();
                break;
            }
            case 4: {
                atualizarQuantidade();
                break;
            }
            case 5: {
                excluirProduto();
                break;
            }
            case 6: {
                printf("\nEncerrando o sistema! \n");
                return;
            }
            default: {
                printf("\nOpção digitada inválida! \n");
            }
        }
    }
    

    return 0;
}
