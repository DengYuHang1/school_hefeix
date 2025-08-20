#include <stdio.h>
#define N 8 
int board[N][N];
// 定义骑士可以移动的8个方向
int move_x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int move_y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
// 检查当前位置是否有效
int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}
void prints() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            printf("%2d ", board[x][y]);
        }
        printf("\n");
    }
}
int solve(int x, int y, int move_number) {
    if (move_number == N * N) {
        return 1; // 所有格子都已访问
    }

    // 尝试所有可能的移动
    for (int i = 0; i < 8; i++) {
        int next_x = x + move_x[i];
        int next_y = y + move_y[i];
        if (isSafe(next_x, next_y)) {
            board[next_x][next_y] = move_number; // 标记当前位置
            if (solve(next_x, next_y, move_number + 1)) {
                return 1; // 找到解决方案
            }
            // 如果当前位置没有找到解决方案，回溯
            board[next_x][next_y] = -1;
        }
    }
    return 0; // 如果没有解决方案，返回0
}
int main() {
    int start_x, start_y;
    // 初始化棋盘，所有位置设置为未访问
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            board[x][y] = -1;
        }
    }
    start_x=0;
    start_y=0;
    board[start_x][start_y] = 0;
    if (solve(start_x, start_y, 1) == 0) {
        printf("不存在\n");
        return 1;
    }
    prints();
    return 0;
}

