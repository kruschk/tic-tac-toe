// Simple game of Tic-Tac-Toe

#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

void drawBoard(void);
int getChoiceXO(void);
int getCoords(void);
int checkWinner(void);
int compCoords(void);
//int checkValidMove(int, int);
int boardPlayable(void);

char computer = '\0';
char player = '\0';
char garbage = '\0';

static char board[9] = {	// possibilities are 'x', 'o', or blank
	'1', '2', '3',	// index 0 1 2
	'4', '5', '6',	//		 3 4 5
	'7', '8', '9'	//		 6 7 8
};

int main(void) {
	printf("Welcome to Tic-Tac-Toe! Would you like to play as 'x' or 'o'? ");

	while (getChoiceXO() != 0) {
		;
	}

	srand((unsigned int)time(NULL));
	drawBoard();
	int keepPlaying;
	/* 1. get coordinates 2. check for winner 3. computer's turn 4. check for
		winner 5. repeat */
	while (!(keepPlaying = checkWinner())) {
		printf("Enter the number of the tile that you would like to play: ");
		getCoords();
		drawBoard();
		if (!(keepPlaying = checkWinner())) {
			printf("Computer's choice:\n");
			compCoords();
			drawBoard();
		}
	}
	switch (keepPlaying) {
		case (1):
			printf("Congratulations, you win!\n");
			break;
		case (2):
			printf("Sorry, the computer won!\n");
			break;
		case (3):
			printf("Looks like it was a tie!\n");
			break;
		default:
			printf("This shouldn't be possible...\n");
			break;
	}
}

// get the player's choice (whether they wish to play as 'x' or 'o')
int getChoiceXO(void) {
	scanf("%c%c", &player, &garbage);	// this needs lots of work
	if (isalpha(player)) {	// get a character from stdin
		player = tolower(player);
		if (player == 'x') {
			computer = 'o';
		}
		else if (player == 'o') {
			computer = 'x';
		}
		else {
			printf("Please enter an 'x' or an 'o' (or choose 'q' to quit): ");
			return -1;
		}
		return 0;
	}
	else {
		return -1;
	}
}

// draw the board on the screen
void drawBoard(void) {
	for (int i = 0; i <= 8; i++) {
		if ((i + 1) % 3 == 0) {
			printf("|%c|\n", board[i]);
		}
		else {
			printf("|%c", board[i]);
		}
	}
}

// get the coordinates of where the player wishes to play
int getCoords() {
	if (boardPlayable()) {
		static int playerChoice;
		scanf("%d%c", &playerChoice, &garbage);
		while (board[playerChoice-1] == 'o' || board[playerChoice-1] == 'x') {
			printf("Invalid input. Please try again: ");
			scanf("%d%c", &playerChoice, &garbage);
		}
		board[playerChoice-1] = player;
		return 0;
	}
	else {
		return -1;
	}
}

// checks for a winner
int checkWinner() {
	if (
	(board[0] == player && board[1] == player && board[2] == player) ||	// hor
	(board[3] == player && board[4] == player && board[5] == player) ||	// hor
	(board[6] == player && board[7] == player && board[8] == player) ||	// hor
	(board[0] == player && board[3] == player && board[6] == player) ||	// vert
	(board[1] == player && board[4] == player && board[7] == player) ||	// vert
	(board[2] == player && board[5] == player && board[8] == player) || // vert
	(board[0] == player && board[4] == player && board[8] == player) || // diag
	(board[6] == player && board[4] == player && board[2] == player)) { // diag
		return 1;
	}
	else if (
	(board[0] == computer && board[1] == computer && board[2] == computer) ||
	(board[3] == computer && board[4] == computer && board[5] == computer) ||
	(board[6] == computer && board[7] == computer && board[8] == computer) ||
	(board[0] == computer && board[3] == computer && board[6] == computer) ||
	(board[1] == computer && board[4] == computer && board[7] == computer) ||
	(board[2] == computer && board[5] == computer && board[8] == computer) ||
	(board[0] == computer && board[4] == computer && board[8] == computer) ||
	(board[6] == computer && board[4] == computer && board[2] == computer)) {
		return 2;
	}
	else if (!boardPlayable()) {
		return 3;
	}
	else {
		return 0;
	}
}

// generate the coordinates for the computer's move
int compCoords() {
	static int compChoice;
	do {
		compChoice = rand() % 9;	// random number between 0 and 8
	}
	while (board[compChoice] == 'o' || board[compChoice] == 'x');
	board[compChoice] = computer;
	return 0;
}

// checks to see if there is a free spot on the board
int boardPlayable(void) {
	for (int i = 0; i <= 8; i++) {
		if (isdigit(board[i])) {
			return 1;
		}
	}
	return 0;
}
