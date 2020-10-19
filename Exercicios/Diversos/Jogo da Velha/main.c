#include <stdio.h>
#include <stdbool.h>

char squares[9] = {'1','2','3','4','5','6','7','8', '9'};
int lines[8][3] = {
   {1,2,3},
   {3,4,5},
   {6,7,8},
   {0,3,6},
   {1,4,7},
   {2,5,8},
   {0,4,8},
   {2,4,6}
};
int i = 0, position, roundGame = 0, iWinner, iReset;


int printBoard() {
   printf("\e[1;1H\e[2J");
   printf("\n");
   printf(" %c | %c | %c\n", squares[0] , squares[1] , squares[2] );
   printf("---+---+---\n");
   printf(" %c | %c | %c\n", squares[3], squares[4], squares[5]);
   printf("---+---+---\n");
   printf(" %c | %c | %c\n", squares[6], squares[7], squares[8]);
   
   return 0;
}

int reset() {
   for (iReset = 0; iReset < 9; iReset++) {
      squares[iReset] = ' ';
   }
   roundGame = 0;

   return 0;
}

int showRoundWinner(char winner) {
   printf("\e[1;1H\e[2J\n");
   printBoard();
   printf("\nVencedor: %c", winner);

   return 0;
}

char checkWinner() {
   printf("Chamou");
   for (iWinner = 0; iWinner < 8; iWinner++) {
      if (squares[lines[iWinner][0]] && squares[lines[iWinner][0]] == squares[lines[iWinner][1]] && squares[lines[iWinner][0]] == squares[lines[iWinner][2]] ) {
         i = 10;
         showRoundWinner(squares[lines[iWinner][0]]);
      }     
   }

   return 0;
}

int readSquare() {
   printBoard();
   do {
      printf("\nRodada: %i.\n", roundGame + 1);
      printf("Jogador Atual: %s.", roundGame % 2 == 0 ? "X" : "O");
      printf("\nEscolha uma Posição para Marcar: ");
      scanf("%i", &position);

      if (!(squares[position - 1] >='1' && squares[position - 1] <= '9')) {
         printf("Entrada inválida, Verifique a posição escolhida e tente novamente\n");
      }

   } while(!(squares[position - 1] >='1' && squares[position - 1] <= '9'));
   squares[position - 1] =  roundGame % 2 == 0 ? 'X' : 'O';
   roundGame++;
   return 0;
} 

int main() {
   char repeat;

   printf("Jogo da Velha - Leandro Ribeiro de Souza \n\n");
   do {
      do {
         readSquare();
         checkWinner();
         i++;
      } while(i < 9);
      printf("\nJogar Novamente? (S ou N)");
      scanf(" %c", &repeat);
      if (repeat == 'S') {
         reset();
      }
   } while(repeat == 'S');

   return 0;
}
