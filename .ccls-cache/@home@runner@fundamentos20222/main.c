#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
#define facin 20
#define marronMeno 10
#define paulera 6
  int jogar = 0;
  int replay;
while (jogar <= 1) { 
  printf("\n************************************");
  printf("\n* Bem vindo ao jogo de adivinhação *");
  printf("\n************************************");

  int numerosecreto, n1, n2, op, chuterep;
  srand(time(NULL));
  printf("\n\nEscolha 2 números para serem os\nlimites para o Número Secreto.\n-- (Exemplo: 0 e 99) --");
  printf("\n\n ~~~ O número secréto estará dentro desse limite\n");
  printf("\nEscolha o primeiro número: ");
  scanf("%d", &n1);
  printf("Agora, o segundo número: ");
  scanf("%d", &n2);
  if (n2 > n1) {
    op = (n2 - n1) + 1;
    numerosecreto = abs(n1 + rand() % op);
  } else if (n1 > n2) {
    op = (n1 - n2) + 1;
    numerosecreto = abs(n2 + rand() % op);
  }
  //printf("\no número %d é secreto!\n", numerosecreto);
  int chute, acertou, maior;
  int ganhou = 0;
  int i = 1;
  double pontos = 1000;
  int nivel, totaldetentativas;
  printf("Em qual nível você quer jogar?\n\n");
  printf("--------------------\n");
  printf(" Fácil (Digite 1)\n Médio (Digite 2)\n Difícil (Digite 3)");
  printf("\n--------------------\n\n");
  printf("Digite: ");
  scanf("%d", &nivel);
    switch(nivel) {
      case 1:
        totaldetentativas = facin;
        break;
      case 2:
        totaldetentativas = marronMeno;
        break;
      default:
        totaldetentativas = paulera;
        break;
      
    }
  do {
      if (chuterep == chute) {
        printf("\nVocê não pode chutar um número igual ao anterior.\nTente novamente!\n");
        i--;
      }
    chuterep = chute;
    printf("Tentativa %d de %d\n", i, totaldetentativas);
    printf("Qual o seu %do. chute?", i);
    scanf("%d", &chute);

    if (chute < 0) {
      printf("\nvocê não pode chutar números negativos\n\n");
      i--;
      continue;
    }
    printf("\nO seu %do. chute foi: %d\n", i, chute);
    acertou = chute == numerosecreto;
    maior = chute > numerosecreto;
    if (acertou) {
      break;
    } else if (maior) {
      printf("\nVocê chutou um número maior que o número secreto.\n\n");
    } else {
      printf("\nVocê chutou um número menor do que o número secreto\n\n");
    }

    double pontosperdidos = abs(chute - numerosecreto) / 2.0;
    pontos = pontos - pontosperdidos;
    i++;
  } while(i <= totaldetentativas);
  if (acertou) {
    printf("\nFim de jogo!\nParabéns, você ganhou!\n\n");
  } else{
  printf("\nFim de jogo!\nVocê perdeu :/");
  }
  printf("\nObrigado por jogar!");
  printf("\nVocê obteve: %.2f pontos!", pontos);
  printf("\nVocê quer jogar denovo?");
  printf("\n--- Digite [1] se sim ---\n--- Digite [2] se não ---\n");
  scanf("%d", &replay);
  if (replay == 2) {
    jogar = 2;
  } else {
    jogar = 0;
  }
}
}