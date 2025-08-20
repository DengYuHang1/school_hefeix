#include <iostream>
#include <vector>

using namespace std;

// 检查是否可以在棋盘的 board[row][col] 位置放置皇后
bool isSafe(const vector<vector<int> > & board, int row, int col) {
    // 检查此列是否有皇后互相冲突
    for (int i = 0; i < row; ++i) {
        if (board[i][col]) return false;
    }

    // 检查左上方是否有皇后互相冲突
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j]) return false;
    }

    // 检查右上方是否有皇后互相冲突
    for (int i = row, j = col; i >= 0 && j < 8; --i, ++j) {
        if (board[i][j]) return false;
    }

    return true;
}

// 使用回溯法尝试在第row行放置皇后
bool solveNQueens(vector<vector<int> > & board, int row, int &solutionsCount) {
    if (row == 8) {  // 找到了一种解法
        solutionsCount++;
        // 打印当前找到的解
        // 打印当前找到的解
		for (int i = 0; i < 8; ++i) { // 遍历行
		    for (int j = 0; j < 8; ++j) { // 遍历列
		        cout << (board[i][j] ? "Q " : ". ");
		    }
		    cout << endl;
		}
		cout << endl;
        return true;
    }

    bool solutionExists = false;
    for (int col = 0; col < 8; ++col) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // 放置皇后
            solutionExists |= solveNQueens(board, row + 1, solutionsCount);  // 尝试下一行
            board[row][col] = 0;  // 回溯，移除皇后
        }
    }
    return solutionExists;
}

int main() {
    vector<vector<int> > board(8, vector<int>(8, 0));
    int solutionsCount = 0;

    // 开始从第0行放置皇后
    if (!solveNQueens(board, 0, solutionsCount)) {
        cout << "没有找到解决方案" << endl;
    } else {
        cout << "总共找到 " << solutionsCount << " 种解决方案" << endl;
    }

    return 0;
}
