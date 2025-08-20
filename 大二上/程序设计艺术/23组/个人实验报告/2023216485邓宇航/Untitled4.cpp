#include <iostream>
#include <vector>
#include <algorithm>  // 用于max函数

using namespace std;

// Kadane's算法：计算一维数组的最大子数组和
int kadane(const vector<int>& arr) {
    int maxSoFar = INT_MIN, maxEndingHere = 0;
    
    for (int i = 0; i < arr.size(); ++i) {
        maxEndingHere += arr[i];
        if (maxSoFar < maxEndingHere)
            maxSoFar = maxEndingHere;
        
        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }
    
    return maxSoFar;
}

// 计算所有子矩阵中和的最大值
int maxSubmatrixSum(vector<vector<int> >& matrix) {
    int rows = matrix.size();
    if (rows == 0) return 0;
    int cols = matrix[0].size();
    
    int maxSum = INT_MIN;
    
    // 遍历所有可能的起始行
    for (int startRow = 0; startRow < rows; ++startRow) {
        vector<int> temp(cols, 0);
        
        // 遍历所有可能的结束行
        for (int endRow = startRow; endRow < rows; ++endRow) {
            // 更新临时数组
            for (int col = 0; col < cols; ++col) {
                temp[col] += matrix[endRow][col];
            }
            
            // 应用Kadane's算法在临时数组上
            int currentMax = kadane(temp);
            maxSum = max(maxSum, currentMax);
        }
    }
    
    return maxSum;
}

int main() {
    int rows, cols;
    cout << "请输入矩阵的行数: ";
    cin >> rows;
    cout << "请输入矩阵的列数: ";
    cin >> cols;

    vector<vector<int> > matrix(rows, vector<int>(cols, 0));
    
    cout << "请输入矩阵元素:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = maxSubmatrixSum(matrix);
    cout << "所有子矩阵中和的最大值为: " << result << endl;

    return 0;
}
