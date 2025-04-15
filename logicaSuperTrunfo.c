#include <stdio.h>

struct carta {
    char estado[2];
    char codigoCarta[3];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

void calculo(struct carta *val) {
    val->densidadePopulacional = (float)val->populacao / val->area;
    val->pibPerCapita = val->pib / (float)val->populacao;

    val->superPoder = (float)val->populacao + val->area + val->pib + (float)val->numPontosTuristicos + val->pibPerCapita + (1.0 / val->densidadePopulacional);
}

void entrada(struct carta *val) {
    printf("Escolha um estado (Uma letra de A a H): ");
    scanf("%s", val->estado);
    printf("Escolha um codigo da carta (01 a 04): ");
    scanf("%s", val->codigoCarta);
    printf("Escolha uma cidade: ");
    scanf("%s", val->cidade);
    printf("Digite a quantidade de populacao: ");
    scanf("%d", &val->populacao);
    printf("Digite a area em KM (somente o numero): ");
    scanf("%f", &val->area);
    printf("Digite o pib: ");
    scanf("%f", &val->pib);
    printf("Escolha um numero de pontos turisticos: ");
    scanf("%d", &val->numPontosTuristicos);
    calculo(val);
}

void saida(struct carta *val) {
    printf("Estado: %s\n", val->estado);
    printf("Codigo da Carta: %s%s\n", val->estado, val->codigoCarta);
    printf("Cidade: %s\n", val->cidade);
    printf("Populacao: %d\n", val->populacao);
    printf("Area: %.2f KM²\n", val->area);
    printf("PIB: %.2f bilhões de reais\n", val->pib);
    printf("Pontos Turisticos: %d\n", val->numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", val->densidadePopulacional);
    printf("PIB Per Capita: %.2f reais\n", val->pibPerCapita);
    printf("Super Poder: %.2f", val->superPoder);
}

void comparacao(struct carta *val1, struct carta *val2) {
    int opcao;
    
    do {
        printf("Escolha uma opção a seguir: \n\n");
        printf("1 - Exibir Paises\n");
        printf("2 - Comparar População\n");
        printf("3 - Comparar Área\n");
        printf("4 - Comparar PIB\n");
        printf("5 - Comparar Pontos Turísticos\n");
        printf("6 - Comparar Densidade Populacional\n");
        printf("7 - Vencedor do jogo\n\n");
        printf("Escolha uma opção (digite o numero da opção correspondente): ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nPaises: Carta 1 - %s e Carta 2 - %s\n\n", val1->cidade, val2->cidade);
            break;

        case 2:
            if (val1->populacao > val2->populacao) {
                printf("\nPopulacao: Carta 1 (%s) Venceu - %lu\n", val1->cidade, val1->populacao);
            } else if (val1->populacao < val2->populacao) {
                printf("\nPopulacao: Carta 2 (%s) Venceu - %lu\n", val2->cidade, val2->populacao);
            } else {
                printf("\nPopulacao: Empate (%lu)\n", val1->populacao);
            }
            break;

        case 3:
            if (val1->area > val2->area) {
                printf("\nÁrea: Carta 1 (%s) Venceu - %.2f\n", val1->cidade, val1->area);
            } else if (val1->area < val2->area) {
                printf("\nÁrea: Carta 2 (%s) Venceu - %.2f\n", val2->cidade, val2->area);
            } else {
                printf("\nÁrea: Empate (%.2f)\n", val1->area);
            }
            break;

        case 4:
            if (val1->pib > val2->pib) {
                printf("\nPIB: Carta 1 (%s) Venceu - %.2f\n", val1->cidade, val1->pib);
            } else if (val1->pib < val2->pib) {
                printf("\nPIB: Carta 2 (%s) Venceu - %.2f\n", val2->cidade, val2->pib);
            } else {
                printf("\nPIB: Empate (%.2f)\n", val1->pib);
            }
            break;

        case 5:
            if (val1->numPontosTuristicos > val2->numPontosTuristicos) {
                printf("\nPontos Turisticos: Carta 1 (%s) Venceu - %d\n", val1->cidade, val1->numPontosTuristicos);
            } else if (val1->numPontosTuristicos < val2->numPontosTuristicos) {
                printf("\nPontos Turisticos: Carta 2 (%s) Venceu - %d\n", val2->cidade, val2->numPontosTuristicos);
            } else {
                printf("\nPontos Turisticos: Empate (%d)\n", val1->numPontosTuristicos);
            }
            break;

        case 6:
            if (val1->densidadePopulacional < val2->densidadePopulacional) {
                printf("\nDensidade Populacional: Carta 1 (%s) Venceu - %.2f\n", val1->cidade, val1->densidadePopulacional);
            } else if (val1->densidadePopulacional > val2->densidadePopulacional) {
                printf("\nDensidade Populacional: Carta 2 (%s) Venceu - %.2f\n", val2->cidade, val2->densidadePopulacional);
            } else {
                printf("\nDensidade Populacional: Empate (%.2f)\n", val1->densidadePopulacional);
            }
            break;

        case 7:
            printf("\nO vencedor do jogo é...\n\n");

            if (val1->superPoder > val2->superPoder) {
                printf("Resultado: Carta 1 (%s) - Venceu o jogo\n", val1->cidade, val1->superPoder);
            } else if (val1->superPoder < val2->superPoder) {
                printf("Resultado: Carta 2 (%s) - Venceu o jogo\n", val2->cidade, val2->superPoder);
            } else {
                printf("Resultado: Empate (%.2f)\n", val1->superPoder);
            }
            break;

        default:
            printf("\nOpção inválida. Tente novamente.\n\n");
        }
    } while (opcao != 7 || opcao > 7 || opcao < 1);

    /*if (val1->pibPerCapita > val2->pibPerCapita) {
        printf("PIB Per Capita: Carta 1 (%s) Venceu - %.2f\n", val1->cidade, val1->pibPerCapita);
    } else if (val1->pibPerCapita < val2->pibPerCapita) {
        printf("PIB Per Capita: Carta 2 (%s) Venceu - %.2f\n", val2->cidade, val2->pibPerCapita);
    } else {
        printf("PIB Per Capita: Empate (%.2f)\n", val1->pibPerCapita);
    }

    if (val1->superPoder > val2->superPoder) {
        printf("Super Poder: Carta 1 (%s) Venceu - %.2f\n", val1->cidade, val1->superPoder);
    } else if (val1->superPoder < val2->superPoder) {
        printf("Super Poder: Carta 2 (%s) Venceu - %.2f\n", val2->cidade, val2->superPoder);
    } else {
        printf("Super Poder: Empate (%.2f)\n", val1->superPoder);
    }*/
}

int main() {
    struct carta cartaUm, cartaDois;
    int opcao;

    do{
        printf("\nSuper Trunfo de Países\n\n");
        printf("1 - iniciar o jogo\n");
        printf("2 - regras do jogo\n");
        printf("3 - sair do jogo\n\n");
        printf("Escolha uma opção (digite o numero da opção correspondente): ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nIniciando Carta Um\n\n");
            entrada(&cartaUm);

            printf("\nIniciando Carta Dois\n\n");
            entrada(&cartaDois);

            printf("\nAs cartas foram criadas com sucesso!");
            do {
                printf("\n\nDeseja exibir os detalhes das cartas? (1 - Sim, 0 - Não): ");
                scanf("%d", &opcao);

                switch (opcao) {
                case 1:
                    printf("\nEssas são as Cartas:");

                    printf("\n\nCarta 1\n");
                    saida(&cartaUm);

                    printf("\n\nCarta 2\n");
                    saida(&cartaDois);
                    break;

                case 0:
                    printf("\nProceguindo...");
                    break;
                
                default:
                    printf("\nOpção inválida. Tente novamente.");
                } 
            } while (opcao != 0 && opcao != 1);

            printf("\n\nComparação das Cartas\n\n");
            comparacao(&cartaUm, &cartaDois);
            printf("\nDeseja continuar jogando? (1 - Sim, 0 - Não): ");
            scanf("%d", &opcao);
            if (opcao == 1) {
                printf("\nReiniciando o jogo...\n");
                main();
            } else {
                printf("\nSaindo do jogo...");
                return 0;
            }
            break;

        case 2:
            printf("\nEsse jogo é baseado no Super Trunfo de Países, onde você pode comparar cartas de diferentes países.\n\n");
            printf("As cartas são compostas por informações como: Estado, Código da Carta, Cidade, População, Área, PIB, Pontos Turísticos e Densidade Populacional.\n\n");
            printf("O objetivo do jogo é comparar as cartas e ver qual delas tem o maior valor em cada categoria.");
            break;
            
        case 3:
            printf("\nSaindo do jogo...");
            break;
        
        default:
            printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao == 2 || opcao > 3 || opcao < 1);

    return 0;
}