#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char segmento[30];
    float preco_compra;
    float preco_venda;
    char unidade_comercial[10];
    int qtd_estoque;
} produtos;
produtos estoque[10];

void limparBufferEntrada() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void cadastrar_produto(){
    for(int i = 0; i < 1; i++){
            printf("informe o nome do produto: ");
            fgets(estoque[i].nome, sizeof(estoque[i].nome), stdin);

            printf("informe segmento do produto [Com ponto para o valor ex: 1000.00 inves de 10000 ]: ");
            fgets(estoque[i].segmento, sizeof(estoque[i].segmento), stdin);

            printf("informe o preco de compra: ");
            scanf(" %f", &estoque[i].preco_compra);
            limparBufferEntrada();

            printf("informe o preco de venda [Com ponto para o valor ex: 1000.00 inves de 10000 ]: ");
            scanf(" %f", &estoque[i].preco_venda);
            limparBufferEntrada();

            printf("informe a unidade de medida: ");
            fgets(estoque[i].unidade_comercial, sizeof(estoque[i].unidade_comercial), stdin);

            printf("informe a quantidade em estoque: ");
            scanf(" %d", &estoque[i].qtd_estoque);
            printf("\n");
            limparBufferEntrada();
    } 
    system("clear");
}
int main () {

    cadastrar_produto();
    printf("\nSeus Produtos Criados\n");
    for(int i = 0; i < 1; i++){
        printf("\nProduto %d: \n", i+1);
        printf("Nome do produto: %s\n", estoque[i].nome);
        printf("segmento do produto: %s\n", estoque[i].segmento);
        printf("preco de compra: %f\n", estoque[i].preco_compra);
        printf("preco de venda: %f\n", estoque[i].preco_venda);
        printf("unidade_comercial: %s\n", estoque[i].unidade_comercial);
        printf("quantidade de estoque: %d", estoque[i].qtd_estoque);
    }

    return 0;
}