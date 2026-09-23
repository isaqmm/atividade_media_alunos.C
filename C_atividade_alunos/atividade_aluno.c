#include <stdio.h>
#include <string.h>

#define MAX 50

// Cadastra os alunos
void cadastrar(char nomes[][100], float n1[], float n2[], float n3[], int *qtd) {
    int novos;

    printf("\nQuantos alunos deseja cadastrar? ");

    if (scanf("%d", &novos) != 1) {
        printf("Digite apenas um numero.\n");
        while (getchar() != '\n');
        return;
    }

    if (novos <= 0 || *qtd + novos > MAX) {
        printf("Quantidade invalida.\n");
        return;
    }

    for (int i = 0; i < novos; i++) {
        printf("\nNome: ");
        scanf(" %[^\n]", nomes[*qtd]);

        printf("Nota 1: ");
        scanf("%f", &n1[*qtd]);

        printf("Nota 2: ");
        scanf("%f", &n2[*qtd]);

        printf("Nota 3: ");
        scanf("%f", &n3[*qtd]);

        while (n1[*qtd] < 0 || n1[*qtd] > 10 ||
               n2[*qtd] < 0 || n2[*qtd] > 10 ||
               n3[*qtd] < 0 || n3[*qtd] > 10) {

            printf("Notas devem estar entre 0 e 10.\n");

            printf("Nota 1: ");
            scanf("%f", &n1[*qtd]);

            printf("Nota 2: ");
            scanf("%f", &n2[*qtd]);

            printf("Nota 3: ");
            scanf("%f", &n3[*qtd]);
        }

        (*qtd)++;
    }
}

// Calcula a media de um aluno
float media(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

// Mostra alunos, notas e medias
void listar(char nomes[][100], float n1[], float n2[], float n3[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- ALUNOS ---\n");

    for (int i = 0; i < qtd; i++) {
        printf("%d - %s | %.2f | %.2f | %.2f | Media: %.2f\n",
               i + 1, nomes[i], n1[i], n2[i], n3[i],
               media(n1[i], n2[i], n3[i]));
    }
}

// Calcula a media da turma
float mediaTurma(float n1[], float n2[], float n3[], int qtd) {
    float soma = 0;

    for (int i = 0; i < qtd; i++)
        soma += n1[i] + n2[i] + n3[i];

    return soma / (qtd * 3);
}

// Mostra maior e menor media
void maiorMenor(float n1[], float n2[], float n3[], int qtd) {
    float maior = media(n1[0], n2[0], n3[0]);
    float menor = maior;

    for (int i = 1; i < qtd; i++) {
        float m = media(n1[i], n2[i], n3[i]);

        if (m > maior)
            maior = m;

        if (m < menor)
            menor = m;
    }

    printf("\nMaior media: %.2f\n", maior);
    printf("Menor media: %.2f\n", menor);
}

// Mostra os aprovados
void aprovados(char nomes[][100], float n1[], float n2[], float n3[], int qtd) {
    int total = 0;

    printf("\n--- APROVADOS ---\n");

    for (int i = 0; i < qtd; i++) {
        float m = media(n1[i], n2[i], n3[i]);

        if (m >= 7) {
            printf("%s - %.2f\n", nomes[i], m);
            total++;
        }
    }

    printf("Total de aprovados: %d\n", total);
}

// Soma as notas usando recursividade
float somaRecursiva(float n1[], float n2[], float n3[], int qtd) {
    if (qtd == 0)
        return 0;

    return n1[qtd - 1] + n2[qtd - 1] + n3[qtd - 1]
           + somaRecursiva(n1, n2, n3, qtd - 1);
}

// Conta aprovados usando recursividade
int contarAprovados(float n1[], float n2[], float n3[], int qtd) {
    if (qtd == 0)
        return 0;

    if (media(n1[qtd - 1], n2[qtd - 1], n3[qtd - 1]) >= 7)
        return 1 + contarAprovados(n1, n2, n3, qtd - 1);

    return contarAprovados(n1, n2, n3, qtd - 1);
}

// Busca aluno pelo nome
void buscar(char nomes[][100], float n1[], float n2[], float n3[], int qtd) {
    char nome[100];

    printf("\nDigite o nome: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < qtd; i++) {
        if (strcmp(nome, nomes[i]) == 0) {
            printf("\nAluno: %s\n", nomes[i]);
            printf("Nota 1: %.2f\n", n1[i]);
            printf("Nota 2: %.2f\n", n2[i]);
            printf("Nota 3: %.2f\n", n3[i]);
            printf("Media: %.2f\n", media(n1[i], n2[i], n3[i]));
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

int main() {
    char nomes[MAX][100];
    float n1[MAX], n2[MAX], n3[MAX];
    int qtd = 0, opcao;

    do {
        printf("\n===== GERENCIAMENTO DE NOTAS =====\n");
        printf("1 - Cadastrar alunos\n");
        printf("2 - Exibir alunos\n");
        printf("3 - Media da turma\n");
        printf("4 - Maior e menor media\n");
        printf("5 - Alunos aprovados\n");
        printf("6 - Estatisticas recursivas\n");
        printf("7 - Buscar aluno\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Digite apenas um numero.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                cadastrar(nomes, n1, n2, n3, &qtd);
                break;

            case 2:
                listar(nomes, n1, n2, n3, qtd);
                break;

            case 3:
                if (qtd > 0)
                    printf("\nMedia da turma: %.2f\n",
                           mediaTurma(n1, n2, n3, qtd));
                else
                    printf("\nNenhum aluno cadastrado.\n");
                break;

            case 4:
                if (qtd > 0)
                    maiorMenor(n1, n2, n3, qtd);
                else
                    printf("\nNenhum aluno cadastrado.\n");
                break;

            case 5:
                if (qtd > 0)
                    aprovados(nomes, n1, n2, n3, qtd);
                else
                    printf("\nNenhum aluno cadastrado.\n");
                break;

            case 6:
                if (qtd > 0) {
                    float soma = somaRecursiva(n1, n2, n3, qtd);
                    int total = contarAprovados(n1, n2, n3, qtd);

                    printf("\nSoma das notas: %.2f\n", soma);
                    printf("Media da turma: %.2f\n", soma / (qtd * 3));
                    printf("Aprovados: %d\n", total);
                } else {
                    printf("\nNenhum aluno cadastrado.\n");
                }
                break;

            case 7:
                if (qtd > 0)
                    buscar(nomes, n1, n2, n3, qtd);
                else
                    printf("\nNenhum aluno cadastrado.\n");
                break;

            case 0:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}