#include <stdio.h>
#define N 9

int isRowValid(int board[N][N])
{
    int i, j, seen[10];

    for (i = 0; i < N; i++) {
        for (j = 0; j < 10; j++)
            seen[j] = 0;

        for (j = 0; j < N; j++) {
            int val = board[i][j];

            if (val != 0) {
                if (seen[val])
                    return 0;
                seen[val] = 1;
            }
        }
    }
    return 1;
}

int isColValid(int board[N][N])
{
    int i, j, seen[10];

    for (j = 0; j < N; j++) {
        for (i = 0; i < 10; i++)
            seen[i] = 0;

        for (i = 0; i < N; i++) {
            int val = board[i][j];

            if (val != 0) {
                if (seen[val])
                    return 0;
                seen[val] = 1;
            }
        }
    }
    return 1;
}

int isBoxValid(int board[N][N])
{
    int r, c, i, j, seen[10];

    for (r = 0; r < N; r += 3) {
        for (c = 0; c < N; c += 3) {
            for (i = 0; i < 10; i++)
                seen[i] = 0;

            for (i = r; i < r + 3; i++) {
                for (j = c; j < c + 3; j++) {
                    int val = board[i][j];

                    if (val != 0) {
                        if (seen[val])
                            return 0;
                        seen[val] = 1;
                    }
                }
            }
        }
    }
    return 1;
}

int main(void)
{
    int board[N][N];
    int i, j, valid = 1;

    printf("Enter the Sudoku board (0 for empty cells):\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (scanf("%d", &board[i][j]) != 1) {
                printf("Invalid input\n");
                return 1;
            }

            if (board[i][j] < 0 || board[i][j] > 9)
                valid = 0;
        }
    }

    if (valid && isRowValid(board) &&
        isColValid(board) && isBoxValid(board))
        printf("Valid Sudoku Board\n");
    else
        printf("Invalid Sudoku Board\n");

    return 0;
}
