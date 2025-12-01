#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_STRING 100

typedef struct{
    int matricula;
    char nome[TAM_STRING];
    char curso[TAM_STRING];
    char endereco[TAM_STRING];
    bool ativo; 
}Aluno;

void limpabufferEntrada() {
    char c;
    while((c = getchar()) !='\n' && c != EOF); 
}

void cadastrar_aluno(Aluno **lista_alunos, int *cont_alunos){

    (*cont_alunos)++;
    
    *lista_alunos = (Aluno *)realloc(*lista_alunos, (*cont_alunos + 1) * sizeof(Aluno));
    
    if(*lista_alunos == NULL){
        printf("Erro ao alocar memoria\n");
        (*cont_alunos)--; 
        return;
    } else {
        printf("\n----Cadastrando aluno----\n");
        printf("\nInforme a matricula:");
        scanf(" %d", &((*lista_alunos)[(*cont_alunos)-1].matricula));
        limpabufferEntrada();
    
        printf("\nInforme nome: ");
        fgets((*lista_alunos)[(*cont_alunos)-1].nome, TAM_STRING, stdin);
        
        printf("\nInforme curso: ");
        fgets((*lista_alunos)[(*cont_alunos)-1].curso, TAM_STRING , stdin);
        
        printf("\nInforme endereco: ");
        fgets((*lista_alunos)[(*cont_alunos)-1].endereco, TAM_STRING, stdin);

        (*lista_alunos)[(*cont_alunos)-1].ativo = true;
        printf("\nAluno cadastrado com sucesso!\n");
    }
}

void remover_aluno(Aluno *alunos, int cont_alunos){
    printf("\n----Remover aluno----\n");
    
    int aluno_encontrado = 0;
    int matricula = 0;
    
    printf("\nInforme a matricula do aluno que deseja remover: ");
    scanf(" %d", &matricula);

    for(int i = 0; i < cont_alunos; i++){
        if(alunos[i].matricula == matricula){
            aluno_encontrado++;
            alunos[i].ativo = false;
            printf("Aluno da matricula %d removido com sucesso!\n", matricula);
            break;
        }
    }
    
    if(aluno_encontrado == 0){
        printf("Nenhum aluno encontrado com essa matricula\n");
    }
}

void alterar_curso(Aluno *alunos, int cont_alunos){
    printf("\n----Alterar curso----\n");
    
    int aluno_encontrado = 0;
    int matricula = 0;
    
    printf("\nInforme a matricula do aluno que deseja alterar o curso: ");
    scanf(" %d", &matricula);
    limpabufferEntrada();
    
    for(int i = 0; i < cont_alunos; i++){
        if(alunos[i].matricula == matricula && alunos[i].ativo == false){
            printf("Aluno inativo. Nao e possivel ser alterado!\n");
            aluno_encontrado++;
            break;
        }
        else if(alunos[i].matricula == matricula){
            aluno_encontrado++;
            printf("Informe o novo curso: ");
            fgets(alunos[i].curso, TAM_STRING, stdin);
            printf("Curso alterado com sucesso!\n");
            break;      
        } 
    }
    if(aluno_encontrado == 0) {
        printf("Nenhum aluno encontrado com essa matricula\n");
    }
}
    
void alterar_endereco(Aluno *alunos, int cont_alunos){
    printf("\n----Alterar endereco----\n");
    
    int aluno_encontrado = 0;
    int matricula = 0;
    
    printf("\nInforme a matricula do aluno que deseja alterar o seu endereco: ");
    scanf(" %d", &matricula);
    limpabufferEntrada();
    
    for(int i = 0; i < cont_alunos; i++){
        if(alunos[i].matricula == matricula && alunos[i].ativo == false){
            printf("Aluno inativo. Nao e possivel ser alterado\n");
            aluno_encontrado++;
            break;
        }
        else if(alunos[i].matricula == matricula){
            aluno_encontrado ++;
            printf("Informe o novo endereco: ");
            fgets(alunos[i].endereco, TAM_STRING, stdin);
            printf("Endereco alterado com sucesso!\n");
            break;
        } 
    }
    if(aluno_encontrado==0){
        printf("Nenhum aluno encontrado com essa matricula\n");
    }
}
    
void relatorio_aluno(Aluno *alunos, int cont_alunos){
    printf("\n-----Lista de alunos----\n");
    
    if(alunos == NULL){
        printf("Nao ha alunos cadastrados\n");
        return;
    } else {
            for(int i = 0; i < cont_alunos ; i++) {
                printf("\n------------------------------------\n");
                printf("\nMatricula: %d\n", alunos[i].matricula);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Curso: %s\n", alunos[i].curso);
                printf("Endereco: %s\n", alunos[i].endereco);
                if(alunos[i].ativo == true){ 
                    printf("Ativo\n");
                    printf("------------------------------------\n");
                } else{
                    printf("F\n");
                    printf("------------------------------------\n");
                }
        }
    }
}


void menu(char *escolha){
    printf("\nDigite o numero correspondente para o que voce deseja:\n1 - Cadastrar\n2 - Remover\n3 - Relatório\n4 - Alterar curso\n5 - Alterar endereco\n0 - Sair do programa\n");
    scanf(" %c", escolha);
    limpabufferEntrada();
}

int main() {
    Aluno *alunos = NULL;
    int num_alunos = 0;
    char opcao;

        while (true){
            menu(&opcao);
            switch(opcao){

                case '1':
                    cadastrar_aluno(&alunos, &num_alunos);
                    break;

                case '2':
                    remover_aluno(alunos, num_alunos);
                    break;

                case '3':
                    relatorio_aluno(alunos, num_alunos);
                    break;

                case '4':
                    alterar_curso(alunos, num_alunos);
                    break;

                case '5':
                    alterar_endereco(alunos, num_alunos);
                    break;

                case '0':
                    printf("\nSaindo...\n");
                    free(alunos);
                    return 0;

                default:
                    printf("\nOpção invalida tente novamente\n");
                    break;
            }
        }    
        return 0;
}

