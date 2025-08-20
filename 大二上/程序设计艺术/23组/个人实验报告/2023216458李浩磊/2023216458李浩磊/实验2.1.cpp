#include <stdio.h>
#define N 8

void print(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 检查放置在 board[row][col] 的皇后是否安全
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // 检查这一列是否有其他皇后
    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    // 检查左上对角线是否有其他皇后
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // 检查右上对角线是否有其他皇后
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

// 递归回溯函数，深度优先的递归调用，若不满足则回溯
int solve(int board[N][N], int row) {
    // 如果所有皇后都被放置好了，则返回真
    if (row == N) {
        print(board); // 打印解决方案
        return 1; // 返回1表示找到解决方案
    }

    // 尝试在这一行的所有列中放置皇后，并递归检查放置是否安全
    int count = 0;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // 放置皇后
            count+=solve(board, row + 1); // 递归放置下一个皇后
            board[row][col] = 0;  // 如果放置下一个皇后失败则回溯
        }
    }
    return count;
}

int main() {
    int board[N][N] = {0};  // 初始化棋盘为 0
    int solutionCount = solve(board, 0);
    if (solutionCount == 0) { // 如果没有找到解决方案
        printf("No");
    }
    return 0;
}

