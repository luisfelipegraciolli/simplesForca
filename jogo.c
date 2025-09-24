#include <stdio.h>  // printf e scanf
#include <stdlib.h> // Srand
#include <string.h> // strcpy e strlen
#include <time.h>   // time
// Bonus
/*
1. Dizer na tela quais letras já foram usadas e pedir para o usuário digitar uma letra diferente
2. Perguntar ao usuário ao final do jogo se ele deseja jogar novamente
3. De uma olhada e mexa um pouco com o meu projeto final dessa disciplina!
*/

int main() {
    // 1° Escolher palavras!
    int erros = 0;
    int acertos = 0;

    char palavras[5][20] = {"luis", "abc"};

    srand(time(NULL)); // Reinicia o rand a cada execução

    int indiceAleatorio = rand() % 2;

    // 2° ter a palavra em uma variável
    char palavraSorteada[20];

    // Isso daqui não pode -> palavra = palavras[indiceAleatorio];
    // Introduzir strcpy e como copiar uma string para outra string

    strcpy(palavraSorteada, palavras[indiceAleatorio]);

    // Precisamos mostrar na tela as letras secretas _ _ _, mas pra isso precisamos saber o tamanho
    // palavra para o programa
    // 3° Descobrir qual o tamanho da palavra escolhida para usar no for loop

    int tamanho = strlen(palavraSorteada);

    // pegar o chute da pessoa e armazenar

    char chute;

    // 4° Ter o vetor inicialmente com _ _ _ para podermos trocarmos ao acerto do chute
    char palavraSecreta[tamanho];
    for (int i = 0; i < tamanho; i++) {
        palavraSecreta[i] = '_';
    }

    palavraSecreta[tamanho] = '\0'; // Saber onde a string termina com um char nulo

    // 5° Loop principal
    // Ou dá forca, ou você acerta a palavra
    while (erros < 6 && acertos < tamanho) {
        printf("Palavra: %s\n\n", palavraSecreta);
        printf("Escolha uma letra: \n");
        scanf(" %c", &chute); // -> ESPAÇO É IMPORTANTE "ignora qualquer quantidade de espaços em branco até ver um espaço válido"
        

        int encontrou = 0;

        for (int i = 0; i < tamanho; i++) {
            // Percorre o vetor da palavra escolhida e verifica se é igual ao chute
            // Verifica se a letra escolhida já foi usada
            if (palavraSorteada[i] == chute && palavraSecreta[i] == '_') {
                palavraSecreta[i] = chute;
                acertos++;
                encontrou = 1;
            }
        }

        if (encontrou == 0) {
            erros++;
            printf("Errou! Tentativas restantes: %d\n", 6 - erros);
        }
    }

    if (acertos == tamanho) {
        printf("\nParabéns! :D Você acertou a palavra: %s\n", palavraSorteada);
    }
    else {
        printf("\nVocê perdeu! D: A palavra era: %s\n", palavraSorteada);
    }

    return 0;
}