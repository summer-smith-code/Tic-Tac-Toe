#include <stdio.h>

void print_board(char b[3][3]);
int check_win(char b[3][3]);

void print_board(char b[3][3]) {
    printf("Tic Tac Toe Board\n");
    for (int r= 0; r < 3; r++) {
        for (int c=0; c<3; c++) {
            if (c == 2)
                printf("%c", b[r][c]);
            else
                printf("%c|", b[r][c]);
        }
        if (r==2)
            printf("\n");
        else
            printf("\n-+-+-\n");
    }
}
// return 0 for no winner, 1 for X win, and 2 for O win
int check_win(char b[3][3]) {
    for (int i = 0; i<3; i++) {
        if (b[i][0] == 'X' && b[i][1] == 'X' && b[i][2] == 'X') return 1;
        if (b[i][0] == 'O' && b[i][1] == 'O' && b[i][2] == 'O') return 2;

        if (b[0][i] == 'X' && b[1][i] == 'X' && b[2][i] == 'X') return 1;
        if (b[0][i] == 'O' && b[1][i] == 'O' && b[2][i] == 'O') return 2;

        if (b[0][0] == 'X' && b[1][1] == 'X' && b[2][2] == 'X') return 1;
        if (b[0][0] == 'O' && b[1][1] == 'O' && b[2][2] == 'O') return 2;

        if (b[2][0] == 'X' && b[1][1] == 'X' && b[0][2] == 'X') return 1;
        if (b[2][0] == 'O' && b[1][1] == 'O' && b[0][2] == 'O') return 2;
    }
    // else
    return 0;
}

int main(void) {
    char board[3][3];
    int turn = 0, x, y;

    for (int r= 0; r < 3; r++) {
        for (int c=0; c<3; c++) {
            board[r][c] = ' ';
        }
    }
    print_board(board);

    while (turn < 9 && check_win(board) != 1 && check_win(board) != 2) {
        if (turn % 2 == 0 && check_win(board) == 0) {
            printf("Player X's turn.\n");
        } else printf("Player O's turn\n");

        print_board(board);

        printf("What position would you like to put your piece in?\n");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        // Check to see if it's a valid move
        if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[y][x] == ' ') {
            if (turn % 2 == 0) {
                board[y][x] = 'X';
            } else {
                board[y][x] = 'O';
            }
            turn++;
        } else {
            printf("Please put a value between 1 and 3\n");
        }
        check_win(board);
        if (check_win(board) == 1) {
            printf("X wins!\n");
        } else if (check_win(board) == 2) {
            printf("Y wins!\n");
        } else {
            printf("Tied game!\n");
        }
    }

    return 0;
}