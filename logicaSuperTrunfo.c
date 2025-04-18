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
    scanf("%lu", &val->populacao);
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
    printf("Populacao: %lu\n", val->populacao);
    printf("Area: %.2f KM²\n", val->area);
    printf("PIB: %.2f bilhões de reais\n", val->pib);
    printf("Pontos Turisticos: %d\n", val->numPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", val->densidadePopulacional);
    printf("PIB Per Capita: %.2f reais\n", val->pibPerCapita);
    printf("Super Poder: %.2f\n", val->superPoder);
}

void comparacao(struct carta *val1, struct carta *val2) {
    int opcao, resultado1, resultado2, atributo1, atributo2;;
    
    do {
        printf("\nComparação das Cartas\n\n");
        printf("Escolha uma opção a seguir: \n\n");
        printf("1 - Exibir Paises\n");
        printf("2 - Comparar População\n");
        printf("3 - Comparar Área\n");
        printf("4 - Comparar PIB\n");
        printf("5 - Comparar Pontos Turísticos\n");
        printf("6 - Comparar Densidade Populacional\n");
        printf("7 - Disputa de atributos\n");
        printf("8 - Vencedor do jogo Completo\n\n");
        printf("Escolha uma opção (digite o numero da opção correspondente): ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\nPaises: Carta 1 - %s e Carta 2 - %s\n", val1->cidade, val2->cidade);
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
            do {
                printf("\nDisputa de atributos:\n\n");
                printf("Escolha o primerio atributo para comparar:\n");
                printf("1 - População\n");
                printf("2 - Área\n");
                printf("3 - PIB\n");
                printf("4 - Pontos Turísticos\n");
                printf("5 - Densidade Populacional\n");
                printf("6 - PIB Per Capita\n");
                printf("7 - Super Poder\n\n");
                printf("Escolha uma opção (digite o numero da opção correspondente): ");
                scanf("%d", &atributo1);

                switch (atributo1) {
                case 1:
                    resultado1 = val1->populacao > val2->populacao ? 1 : 0;
                    break;

                case 2:
                    resultado1 = val1->area > val2->area ? 1 : 0;
                    break;

                case 3:
                    resultado1 = val1->pib > val2->pib ? 1 : 0;
                    break;

                case 4:
                    resultado1 = val1->numPontosTuristicos > val2->numPontosTuristicos ? 1 : 0;
                    break;

                case 5:
                    resultado1 = val1->densidadePopulacional < val2->densidadePopulacional ? 1 : 0;
                    break;

                case 6:
                    resultado1 = val1->pibPerCapita > val2->pibPerCapita ? 1 : 0;
                    break;

                case 7:
                    resultado1 = val1->superPoder > val2->superPoder ? 1 : 0;
                    break;

                default:
                    printf("\nOpção inválida. Tente novamente.\n");
                    break;
                }
            } while (atributo1 < 1 || atributo1 > 7);

            do {
                do{
                    printf("\nEscolha o segundo atributo para comparar:\n");
                    printf("1 - População\n");
                    printf("2 - Área\n");
                    printf("3 - PIB\n");
                    printf("4 - Pontos Turísticos\n");
                    printf("5 - Densidade Populacional\n");
                    printf("6 - PIB Per Capita\n");
                    printf("7 - Super Poder\n\n");
                    printf("Escolha uma opção (digite o numero da opção correspondente): ");
                    scanf("%d", &atributo2);

                    atributo1 == atributo2 ? printf("\nAtributos iguais, escolha outros atributos.\n") : 0;
                } while (atributo1 == atributo2);

                switch (atributo2) {
                case 1:
                    resultado2 = val1->populacao > val2->populacao ? 1 : 0;
                    break;

                case 2:
                    resultado2 = val1->area > val2->area ? 1 : 0;
                    break;

                case 3:
                    resultado2 = val1->pib > val2->pib ? 1 : 0;
                    break;

                case 4:
                    resultado2 = val1->numPontosTuristicos > val2->numPontosTuristicos ? 1 : 0;
                    break;

                case 5:
                    resultado2 = val1->densidadePopulacional < val2->densidadePopulacional ? 1 : 0;
                    break;

                case 6:
                    resultado2 = val1->pibPerCapita > val2->pibPerCapita ? 1 : 0;
                    break;

                case 7:
                    resultado2 = val1->superPoder > val2->superPoder ? 1 : 0;
                    break;

                default:
                    printf("\nOpção inválida. Tente novamente.\n");
                    break;
                }
            } while (atributo2 < 1 || atributo2 > 7);

            printf("\nO Vencedor dessa disputa é...\n\n");
            if (resultado1 && resultado2) {
                printf("Resultado: Carta 1 (%s) - Venceu a disputa\n", val1->cidade);
            } else if (!resultado1 && !resultado2) {
                printf("Resultado: Carta 2 (%s) - Venceu a disputa\n", val2->cidade);
            } else {
                printf("Resultado: Empate\n");
            }
            break;

        case 8:
            printf("\nO vencedor do jogo é...\n\n");

            if (val1->superPoder > val2->superPoder) {
                printf("Resultado: Carta 1 (%s) - Venceu o jogo\n", val1->cidade);
            } else if (val1->superPoder < val2->superPoder) {
                printf("Resultado: Carta 2 (%s) - Venceu o jogo\n", val2->cidade);
            } else {
                printf("Resultado: Empate (%.2f)\n", val1->superPoder);
            }
            break;

        default:
            printf("\nOpção inválida. Tente novamente.\n\n");
        }
    } while (opcao != 8 || opcao > 8 || opcao < 1);
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
                    printf("\nEssas são as Cartas:\n");

                    printf("\nCarta 1\n");
                    saida(&cartaUm);

                    printf("\nCarta 2\n");
                    saida(&cartaDois);
                    break;

                case 0:
                    printf("\nProceguindo...\n");
                    break;
                
                default:
                    printf("\nOpção inválida. Tente novamente.");
                } 
            } while (opcao != 0 && opcao != 1);

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