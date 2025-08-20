#include <iostream>
#include <limits> // for numeric_limits
using namespace std;

double map[8][8] = { /* 初始化邻接矩阵 */
    {0  ,1.3,2.1,0.9,0.7,1.8,2.0,1.8},
    {1.3,0  ,0.9,1.8,1.2,2.8,2.3,1.1},
    {2.1,0.9,0  ,2.6,1.7,2.5,1.9,1.0},
    {0.9,1.8,2.6,0  ,0.7,1.6,1.5,0.9},
    {0.7,1.2,1.7,0.7,0  ,0.9,1.1,0.8},
    {1.8,2.8,2.5,1.6,0.9,0  ,0.6,1.0},
    {2.0,2.3,1.9,1.5,1.1,0.6,0  ,0.5},
    {1.8,1.1,1.0,0.9,0.8,1.0,0.5,0  }
};

// 函数用于打印邻接矩阵
void printAdjMatrix(double adjMatrix[8][8]) {
    cout << "最小生成树邻接矩阵：" << endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (adjMatrix[i][j] == 0 && i != j)
                cout << "-\t"; // 表示没有直接连接
            else
                cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void MiniSpanTree_Prim(double mstMatrix[8][8]) {
    double lowcost[8]; // 储存最小边 
    int adjvex[8]; // 储存顶点 
    int k = 0;
    double min_length = 0; // 储存最短距离

    // 初始化mstMatrix为全0
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            mstMatrix[i][j] = 0;

    for (int i = 1; i < 8; i++) {
        lowcost[i] = map[k][i];
        adjvex[i] = 0; // 初始化adjvex
    }

    for (int i = 1; i < 8; i++) {
        double min = numeric_limits<double>::max(); // 使用最大值代替硬编码的大数
        int minIndex = -1;

        for (int j = 1; j < 8; j++) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                minIndex = j;
            }
        }

        if (minIndex == -1) break; // 如果找不到有效的最小边，则退出循环

        // 添加到MST中
        mstMatrix[adjvex[minIndex]][minIndex] = lowcost[minIndex];
        mstMatrix[minIndex][adjvex[minIndex]] = lowcost[minIndex];

        min_length += min;
        lowcost[minIndex] = 0; // 将当前顶点的权值设置为0

        for (int j = 1; j < 8; j++) {
            if (lowcost[j] != 0 && map[minIndex][j] < lowcost[j]) {
                lowcost[j] = map[minIndex][j];
                adjvex[j] = minIndex;
            }
        }
    }

    cout << "最短距离：" << min_length << endl; // 输出最短距离
}

int main() {
    double mstMatrix[8][8];
    cout << "最小生成树相应的边:" << endl;
    MiniSpanTree_Prim(mstMatrix); // 调用最小生成树算法 

    printAdjMatrix(mstMatrix);

    return 0;
}