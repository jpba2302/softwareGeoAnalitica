#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto {
    char nome;
    float x;
    float y;
};
typedef struct Ponto Ponto;

Ponto *registraPonto (Ponto *pontos, int *pTamanhoAtual) {
    int tamanhoAtual = *pTamanhoAtual;
    getchar();
    Ponto *ponteiro;
    ponteiro = pontos;
    printf("Digite o nome do ponto: ");
    scanf("%c",&pontos[tamanhoAtual].nome);
    for (int i = 0; i < tamanhoAtual;i++) {
        if (pontos[tamanhoAtual].nome == pontos[i].nome) {
            printf("\nNOME JÁ REGISTRADO\n");
            return ponteiro;
        }
    }
    printf("Digite a coordenada x do ponto: ");
    scanf("%f",&pontos[tamanhoAtual].x);
    printf("Digite a coordenada y do ponto: ");
    scanf("%f",&pontos[tamanhoAtual].y);
    printf("\nPONTO REGISTRADO COM SUCESSO\n");
    *pTamanhoAtual = tamanhoAtual + 1;
    return ponteiro;
}

float calculaDet(float matriz[3][5]) {
    float det;
    float soma = 1;
    float diagonal1 = 0;
    float diagonal2 = 0;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 5;j++) {
            if (i == j) {
                soma = soma * matriz[i][j];
            }
        }
    }
    diagonal1 = diagonal1 + soma;
    soma = 1;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 5;j++) {
            if (i == j - 1) {
                soma = soma * matriz[i][j];
            }
        }
    }
    diagonal1 = diagonal1 + soma;
    soma = 1;
    for (int i = 0;i < 3; i++) {
        for (int j = 0;j < 5;j++) {
            if (i == j - 2) {
                soma = soma * matriz[i][j];
            }
        }
    }
    diagonal1 = diagonal1 + soma;
    soma = 1;
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j == 4) {
                soma = soma * matriz[i][j];
            }
        }
    }
    diagonal2 = diagonal2 + soma;
    soma = 1;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 5;j++) {
            if (i + j == 3) {
                soma = soma * matriz[i][j];
            }
        }
    }
    diagonal2 = diagonal2 + soma;
    soma = 1;
    for (int i = 0;i < 3;i++) {
        for (int j = 0; j < 5; j++) {
            if (i + j == 2) {
                soma = soma * matriz[i][j];
            }
        }
    }
    diagonal2 = diagonal2 + soma;

    det = diagonal1 - diagonal2;
    return det;
}

int procuraPonto (Ponto *pontos, int *pTamanhoAtual, char nomePonto) {

    int tamanhoAtual = *pTamanhoAtual;
    for (int i = 0;i < tamanhoAtual;i++) {
        if (pontos[i].nome == nomePonto) {
            printf("\nPONTO ENCONTRADO COM SUCESSO\n\n");
            return i;
        }
    }
    printf("\nNENHUM PONTO ENCONTRADO\n");
    return -1;
}

int main () {

    int opcao = 1;
    int tamanho = 50;
    int indice[3];
    float temp = 0;
    Ponto *pontos;
    pontos = (Ponto*)malloc(sizeof(Ponto) * tamanho);
    int tamanhoAtual = 0;
    int *pTamanhoAtual;
    pTamanhoAtual = &tamanhoAtual;
    char nomePonto;
    float matriz[3][5];
    printf("========SOFTWARE GEOMETRIA ANALÍTICA==========\n");
    while (opcao != 0) {
        printf("\n1- Registrar ponto\n2- Calcular distância entre dois pontos\n3- Calcular ponto médio entre dois pontos\n4- Calcular área do triângulo\n0- Encerrar programa\n");
        printf("\nDIGITE SUA OPÇÃO: ");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                printf("\n=====REGISTRAR PONTO========\n");
                pontos = registraPonto(pontos, pTamanhoAtual);
                break;
            case 2:
                getchar();
                printf("\n=====CALCULAR DISTÂNCIA ENTRE DOIS PONTOS=======\n");
                printf("Digite o nome do primeiro ponto: ");
                scanf("%c",&nomePonto);
                getchar();
                indice[0] = procuraPonto(pontos, pTamanhoAtual, nomePonto);
                if (indice[0] == -1) {
                    printf("\nNÃO EXISTE UM PONTO COM ESSE NOME\n");
                    break;
                }
                printf("Digite o nome do segundo ponto: ");
                scanf("%c",&nomePonto);
                getchar();
                indice[1] = procuraPonto(pontos, pTamanhoAtual, nomePonto);
                if (indice[1] == -1) {
                    printf("\nNÃO EXISTE UM PONTO COM ESSE NOME\n");
                    break;
                }
                printf("\nA distância de %c até %c é: %.2f\n",pontos[indice[0]].nome, pontos[indice[1]].nome, sqrt(pow(pontos[indice[1]].x - pontos[indice[0]].x, 2) + pow((pontos[indice[1]].y - pontos[indice[0]].y), 2)));
                break;
            case 3:
                getchar();
                printf("\n=======DESCOBRIR PONTO MÉDIO ENTRE DOIS PONTOS=======\n");
                printf("Digite o nome do primeiro ponto: ");
                scanf("%c",&nomePonto);
                getchar();
                indice[0] = procuraPonto(pontos, pTamanhoAtual, nomePonto);
                if (indice[0] == -1) {
                    printf("\nNÃO EXISTE UM PONTO COM ESSE NOME\n");
                    break;
                }
                printf("Digite o nome do segundo ponto: ");
                scanf("%c",&nomePonto);
                getchar();
                indice[1] = procuraPonto(pontos, pTamanhoAtual, nomePonto);
                if (indice[1] == -1) {
                    printf("\nNÃO EXISTE UM PONTO COM ESSE NOME\n");
                    break;
                }
                printf("\nPONTO MÉDIO DE %c e %c = (%.2f, %.2f)\n",pontos[indice[0]].nome, pontos[indice[1]].nome, (pontos[indice[0]].x + pontos[indice[1]].x) / 2, (pontos[indice[0]].y + pontos[indice[1]].y) / 2);
                break;
            case 4:
                                getchar();
                printf("\n=======CALCULAR A ÁREA DO TRIÂNGULO=======\n");
                printf("Digite o nome do primeiro ponto: ");
                scanf("%c",&nomePonto);
                getchar();
                indice[0] = procuraPonto(pontos, pTamanhoAtual, nomePonto);
                if (indice[0] == -1) {
                    printf("\nNÃO EXISTE UM PONTO COM ESSE NOME\n");
                    break;
                }
                printf("Digite o nome do segundo ponto: ");
                scanf("%c",&nomePonto);
                getchar();
                indice[1] = procuraPonto(pontos, pTamanhoAtual, nomePonto);
                if (indice[1] == -1) {
                    printf("\nNÃO EXISTE UM PONTO COM ESSE NOME\n");
                    break;
                }
                printf("Digite o nome do terceiro ponto: ");
                scanf("%c",&nomePonto);
                getchar();
                indice[2] = procuraPonto(pontos, pTamanhoAtual, nomePonto);
                if (indice[2] == -1) {
                    printf("\nNÃO EXISTE UM PONTO COM ESSE NOME\n");
                    break;
                }
                for (int i = 0; i < 3;i++) {
                    for (int j = 0;j < 5;j++) {
                        if (j == 2) {
                            matriz[i][j] = 1;
                        } else if (j == 0 || j == 3) {
                            matriz[i][j] = pontos[indice[i]].x;
                        } else {
                            matriz[i][j] = pontos[indice[i]].y;
                        }
                    }
                }
                temp = calculaDet(matriz);
                temp = temp / 2;
                if (temp < 0) {
                    temp = temp * -1;
                    printf("\nA ÁREA DO TRIÂNGULO É DE %.2f\n",temp);
                } else if (temp == 0) {
                    printf("\nNÃO É UM TRIÂNGULO POIS OS PONTOS ESTÃO ALINHADOS\n");
                } else {
                    printf("\nA ÁREA DO TRIÂNGULO É DE %.2f\n",temp);
                }
                break;
            default:
                if (opcao != 0) {
                    printf("\nOpção inválida\n");
                }
        }
    }

    printf("\nPROGRAMA ENCERRADO COM SUCESSO\n");
    return 0;
}
