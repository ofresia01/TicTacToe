/*
    Author: Owen Fresia
    Date: 16/07/2022
    Purpose: Tic-tac-toe game, played on a 3x3 grid by two players, who take turns.
*/
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice, player;

// Function prototypes
int checkForWin();
void displayBoard();
void markBoard(char);

int main() {
    int gameStatus;
    char mark;
    player = 1;

    // Do loop that runs until gameStatus returns other than -1, indicating win or draw
    do {
        displayBoard();

        player = (player % 2) ? 1 : 2; // Change turns between players

        printf("PLAYER %d, ENTER A NUMBER: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        markBoard(mark); // Set board for player choice

        gameStatus = checkForWin();
        player++;
    }while (gameStatus == -1);

    if (gameStatus == 1)
        printf("PLAYER %d WINS!", --player);
    else
        printf("THE GAME IS A DRAW!");
    return 0;
}

int checkForWin() {
    int returnValue = 0;

    // Check for all win conditions
    if (square[1] == square[2] && square[2] == square[3])
        returnValue = 1;
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;
    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;
    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;
    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;
    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;
    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;
    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;
    // Check for board misalignment
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5'
             && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        returnValue = 0;
    else
        returnValue = -1;

    return returnValue;
}

void displayBoard() {
    // Menu for board
    system("clear"); // Clears console after each iteration
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n\n");

}

void markBoard(char mark) {
    // If index value is available in square, mark that index value with player choice
    if (choice == 1 && square[1] == '1')
        square[1] = mark;
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    // Invalid input
    else {
        printf("INVALID MOVE!");
        player--;
        getchar();
    }
}
