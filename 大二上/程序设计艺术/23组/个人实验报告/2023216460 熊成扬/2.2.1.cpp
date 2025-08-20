#include <iostream>
#include <vector>

using namespace std;

// 检查当前位置是否可以放置皇后
bool is_safe(const vector<string> &board, int row, int col, int n) 
{
    for (int i = 0; i < row; i++)       // 列
        if (board[i][col] == 'Q')
            return false;
    
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)      //对角线
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}


void solves(vector<string> &board, int row, int n, vector<vector<string>> &solutions) 
{
    if (row == n) 
    {
        solutions.push_back(board);         //添加到解决方案列表
        return;
    }

    //在当前行的每一列放置皇后
    for (int col = 0; col < n; col++) 
    {
        if (is_safe(board, row, col, n)) 
        {
            board[row][col] = 'Q';
            solves(board, row + 1, n, solutions);
            board[row][col] = '.';           // 回溯
        }
    }
}

vector<vector<string>> solve_n_queens(int n) 
{
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solves(board, 0, n, solutions);
    return solutions;
}

int main() {
    int n = 8;  // N皇后问题
    vector<vector<string>> solutions = solve_n_queens(n);

    cout << solutions.size() << "solutions" << endl;

    for (int i = 0; i < solutions.size(); i++) 
    {
        cout << i+1 << ":" << endl;
        for (const string &row : solutions[i]) 
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}