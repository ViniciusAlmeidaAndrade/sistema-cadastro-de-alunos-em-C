# 🎓 Sistema de Gerenciamento de Alunos em C (CRUD Simples)

## 📌 Visão Geral

Este programa, desenvolvido em C, é um sistema básico de Gerenciamento de Registros de Alunos (CRUD - Create, Read, Update, Delete) utilizando structs e alocação dinâmica de memória (realloc).
O objetivo é fornecer uma interface de linha de comando para cadastrar, remover (inativar), alterar informações e listar todos os registros de alunos de uma escola.

## ✨ Funcionalidades e Implementação

O sistema gerencia uma lista dinâmica de alunos, onde cada registro é representado pela struct Aluno.

### Estrutura de Dados (struct Aluno)

Cada aluno possui os seguintes campos:

- matricula (int)
- nome (string)
- curso (string)
- endereco (string)
- ativo (bool) - Indica se o aluno está ativo ou foi removido (inativado).

### Principais Funções

| Função | Propósito | Detalhes da Implementação |
|--------|-----------|---------------------------|
| cadastrar_aluno | Adiciona um novo aluno. | Utiliza realloc para expandir a lista dinamicamente e fgets para leitura segura de strings. |
| remover_aluno | Inativa um aluno. | Não remove o aluno da memória; apenas define o campo ativo como false. |
| alterar_curso | Atualiza o curso de um aluno. | Requer a matrícula e verifica se o aluno está ativo antes da alteração. |
| alterar_endereco | Atualiza o endereço de um aluno. | Requer a matrícula e verifica o status de atividade. |
| relatorio_aluno | Lista todos os alunos. | Percorre a lista e exibe todos os dados, incluindo o status de atividade. |
| limpabufferEntrada | Limpa o buffer de entrada. | Essencial após scanf (para inteiros/chars) para garantir que fgets leia corretamente as strings subsequentes. |

## 🛠️ Como Compilar e Executar

### 1. Compilação

Salve o código como, por exemplo, gestao_alunos.c e compile usando o GCC:

```
gcc gestao_alunos.c -o gestao_alunos
```

### 2. Execução

Execute o programa e utilize o menu para interagir:

```
./gestao_alunos
```

### Menu de Opções

O programa é controlado pelo seguinte menu principal:

- Cadastrar
- Remover
- Relatório
- Alterar curso
- Alterar endereco
- Sair do programa (libera a memória alocada com free(alunos))

## 💻 Tecnologia Envolvida

- Linguagem: C
- Bibliotecas Padrão: stdio.h, stdlib.h (para realloc), string.h, stdbool.h
