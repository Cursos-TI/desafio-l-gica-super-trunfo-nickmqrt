#include <stdio.h>
#include <string.h>


// Desafio Super Trunfo 
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado[3];          // Ex: "SP"
    char codigo[10];         // Ex: "C01"
    char nomeCidade[50];     // Ex: "Sao Paulo"
    int populacao;           // Em número de habitantes
    float area;              // Em kilometros
    float pib;               // Em bilhoes
    int pontosTuristicos;    // Quantidade de pontos Turisticos

    float densidadePopulacional; // População / Area
    float pibPerCapita;          // PIB / População
};

// Função para calcular densidade populacional e PIB per capita
void calcularIndicadores(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os dados da carta
void exibirCarta(struct Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f metros\n", carta.area);
    printf("PIB: %.2f bilhoes\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("\n");
}

int main() {
    // Definindo as duas cartas manualmente
    struct Carta carta1 = {"SP", "C01", "Sao Paulo", 12300000, 1521.0, 700.0, 25};
    struct Carta carta2 = {"RJ", "C02", "Rio de Janeiro", 6748000, 1182.3, 420.0, 20};

    // Calculando os indicadores para cada carta
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibindo os dados das cartas
    printf("=== Carta 1 ===\n");
    exibirCarta(carta1);
    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Atributo escolhido para comparação: PIB
    printf("Comparacao de cartas (Atributo: PIB)\n\n");
    printf("Carta 1 - %s (%.2f bilhoes)\n", carta1.nomeCidade, carta1.pib);
    printf("Carta 2 - %s (%.2f bilhoes)\n", carta2.nomeCidade, carta2.pib);

    // Comparando os valores do PIB
    if (carta1.pib > carta2.pib) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pib > carta1.pib) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
