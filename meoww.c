#include <stdio.h>

void tic_tac(char tic[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", tic[i][j]);
        }
        printf("\n");
    }
}

int end(char tic[3][3], char symbol) {

    for (int i = 0; i < 3; i++) {
        if (tic[i][0] == symbol && tic[i][1] == symbol && tic[i][2] == symbol) {
            return 1; 
        }
        if (tic[0][i] == symbol && tic[1][i] == symbol && tic[2][i] == symbol) {
            return 1; 
        }
    }
    if (tic[0][0] == symbol && tic[1][1] == symbol && tic[2][2] == symbol) {
        return 1;
    }
    if (tic[0][2] == symbol && tic[1][1] == symbol && tic[2][0] == symbol) {
        return 1;
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tic[i][j] == ' ') {
                return 0;
            }
        }
    }
    
    return -1;
}

int main() {
    char tic[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col;
    char player = 'A';
    int cont = 0; // 0: Ongoing, 1: X wins, 2: O wins, -1: Draw
    
    while (cont == 0) {
        tic_tac(tic);
        printf("Player %c, enter row (0-2) and column (0-2) separated by a space: ", player);
        scanf("%d %d", &row, &col);
        
        if (row < 0 || row > 2 || col < 0 || col > 2 || tic[row][col] != ' ') {
            printf("Invalid move.\n");
            continue;
        }
        
        tic[row][col] = player;
        cont = end(tic, player);
        
        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }
    
    tic_tac(tic);
    if (cont == 1) {
        printf("Player A wins!\n");
    } else if (cont == 2) {
        printf("Player B wins!\n");
    } else {
        printf("It's a draw!\n");
    }
    
    return 0;
}