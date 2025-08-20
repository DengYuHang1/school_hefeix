#include <iostream>
#include <vector>

using namespace std;

// 定义骑士可以移动的方向
const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool solveKT(int x, int y, int movei, vector<vector<int> >& board, int& n) {
    // 将当前步数放置在棋盘上
    board[x][y] = movei;

    // 如果已经完成了所有步骤，则返回true
    if (movei == n * n)
        return true;

    // 尝试所有的可能方向
    for (int i = 0; i < 8; ++i) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        // 检查下一步是否合法
        if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && board[next_x][next_y] == -1) {
            // 递归地尝试下一个位置
            if (solveKT(next_x, next_y, movei + 1, board, n)) {
                return true;
            }
        }
    }

    // 如果没有成功，则回溯
    board[x][y] = -1; // 清除当前步数

    return false;
}

void printSolution(const vector<vector<int> >& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout.width(3);  // 设置输出宽度为3个字符
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 8; // 棋盘大小
    vector<vector<int> > board(n, vector<int>(n, -1)); // 初始化棋盘

    // 从任意给定的顶点开始
    int start_x = 0; // 起始行
    int start_y = 0; // 起始列

    if (solveKT(start_x, start_y, 1, board, n)) {
        cout << "解决方案：" << endl;
        printSolution(board, n);
    } else {
        cout << "没有找到解决方案" << endl;
    }

    return 0;
}
