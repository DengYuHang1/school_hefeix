#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX
#define N 26

using namespace std;

void printPath(vector<int> parent, int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << (char)(j + 'A') << " ";
}

void dijkstra(vector<vector<int>> graph, int src, int dest) {
    int dist[N];
    vector<bool> sptSet(N, false);
    vector<int> parent(N);
    for (int i = 0; i < N; i++) {
        parent[i] = -1;
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int count = 0; count < N - 1; count++) {
        int u = -1;
        for (int i = 0; i < N; i++)
            if (!sptSet[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        sptSet[u] = true;
        for (int v = 0; v < N; v++)
            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    cout << "从" << (char)(src + 'A') << " 到 " << (char)(dest + 'A') << "的最短路径为: ";
    cout << (char)(src + 'A') << " ";
    printPath(parent, dest);
    cout << "\n最少花费为: " << dist[dest] << endl;
}

void floydWarshall(vector<vector<int>> graph) {
    int dist[N][N], i, j, k;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    cout << "可达矩阵为： \n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, INF, 1892, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, 0, 216, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {1892, 216, 0, 676, 1145, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, 676, 0, INF, INF, 511, 842, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, 1145, INF, 0, 668, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, 668, 0, 695, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 511, INF, 695, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 534, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, 842, INF, INF, INF, 0, 1100, 967, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, 1100, 0, 639, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, 967, 639, 0, 902, 607, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 902, 0, 672, INF, INF, INF, INF, INF, INF, 528, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, 607, 672, 0, 255, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 255, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 675, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 675, 0, 140, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 140, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, 534, INF, INF, INF, 528, INF, INF, INF, INF, INF, INF, INF, 0, 375, 622, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 375, 0, INF, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 622, INF, 0, INF, INF, INF, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 674, 704, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 674, 0, 651, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 704, 651, 0, INF, INF},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 550},
        {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 550, 0}
    };

    int mode;
    cout << "请选择模式，0表示单源模式，1表示多源模式： ";
    cin >> mode;
    if (mode == 0) {
        char source, destination;
        cout << "请输入起始的城市： ";
        cin >> source;
        cout << "请输入终止的城市：";
        cin >> destination;
        dijkstra(graph, source - 'A', destination - 'A');
    }
    else if (mode == 1) {
        floydWarshall(graph);
    }
    return 0;
}