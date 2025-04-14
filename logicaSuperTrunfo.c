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
    if (val1->populacao > val2->populacao) {
        printf("Populacao: Carta 1 (%s) Venceu - %lu\n", val1->cidade, val1->populacao);
    } else if (val1->populacao < val2->populacao) {
        printf("Populacao: Carta 2 (%s) Venceu - %lu\n", val2->cidade, val2->populacao);
    } else {
        printf("Populacao: Empate (%lu)\n", val1->populacao);
    }

    if (val1->area > val2->area) {
        printf("Área: Carta 1 (%s) Venceu - %.2f\n", val1->cidade, val1->area);
    } else if (val1->area < val2->area) {
        printf("Área: Carta 2 (%s) Venceu - %.2f\n", val2->cidade, val2->area);
    } else {
        printf("Área: Empate (%.2f)\n", val1->area);
    }

    if (val1->pib > val2->pib) {
        printf("PIB: Carta 1 (%s) Venceu - %.2f\n", val1->cidade, val1->pib);
    } else if (val1->pib < val2->pib) {
        printf("PIB: Carta 2 (%s) Venceu - %.2f\n", val2->cidade, val2->pib);
    } else {
        printf("PIB: Empate (%.2f)\n", val1->pib);
    }

    if (val1->numPontosTuristicos > val2->numPontosTuristicos) {
        printf("Pontos Turisticos: Carta 1 (%s) Venceu - %d\n", val1->cidade, val1->numPontosTuristicos);
    } else if (val1->numPontosTuristicos < val2->numPontosTuristicos) {
        printf("Pontos Turisticos: Carta 2 (%s) Venceu - %d\n", val2->cidade, val2->numPontosTuristicos);
    } else {
        printf("Pontos Turisticos: Empate (%d)\n", val1->numPontosTuristicos);
    }

    if (val1->densidadePopulacional < val2->densidadePopulacional) {
        printf("Densidade Populacional: Carta 1 (%s) Venceu - %.2f\n", val1->cidade, val1->densidadePopulacional);
    } else if (val1->densidadePopulacional > val2->densidadePopulacional) {
        printf("Densidade Populacional: Carta 2 (%s) Venceu - %.2f\n", val2->cidade, val2->densidadePopulacional);
    } else {
        printf("Densidade Populacional: Empate (%.2f)\n", val1->densidadePopulacional);
    }

    if (val1->pibPerCapita > val2->pibPerCapita) {
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
    }

    if (val1->superPoder > val2->superPoder) {
        printf("Resultado: Carta 1 (%s) - Venceu o jogo\n", val1->cidade);
    } else if (val1->superPoder < val2->superPoder) {
        printf("Resultado: Carta 2 (%s) - Venceu o jogo\n", val2->cidade);
    } else {
        printf("Resultado: Empate\n");
    }
}

int main() {
    struct carta cartaUm, cartaDois;

    printf("Super Trunfo de Países");
    
    printf("\n\nIniciando Carta Um\n\n");
    entrada(&cartaUm);

    printf("\n\nIniciando Carta Dois\n\n");
    entrada(&cartaDois);

    printf("\n\nEssas são as Cartas\n\n");

    printf("\n\nCarta 1\n");
    saida(&cartaUm);

    printf("\n\nCarta 2\n");
    saida(&cartaDois);

    printf("\n\nComparação das Cartas\n");
    comparacao(&cartaUm, &cartaDois);
}