#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// 网络
class Graph {
private:
    int V;
    vector<vector<int>> capacity;
    vector<vector<int>> adjList;

public:
    // 邻接表
    Graph(int V) : V(V) 
    {
        capacity.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    void addEdge(int u, int v, int cap) 
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        capacity[u][v] += cap;
    }

    // 广度优先搜索找最短路径
    int bfs(int s, int t, vector<int> &parent) 
    {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INT_MAX});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : adjList[cur]) 
            {
                if (parent[next] == -1 && capacity[cur][next]) 
                {
                    parent[next] = cur;
                    int new_flow = min(flow, capacity[cur][next]);
                    if (next == t)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }

        return 0;
    }

    int maxFlow(int s, int t) 
    {
        int flow = 0;
        vector<int> parent(V);
        int new_flow;

        while (new_flow = bfs(s, t, parent)) 
        {
            flow += new_flow;
            int cur = t;
            while (cur != s) 
            {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;   //反向路径
                cur = prev;
            }
        }

        return flow;
    }
};

int main() 
{
    int N, M;
    cin >> N >> M;

    Graph g(N);

    for (int i = 0; i < M; i++) 
    {
        int u, v, cap;
        cin >> u >> v >> cap;
        u--; v--;   // 将输入的编号转为数组的索引
        g.addEdge(u, v, cap);
    }

    cout << g.maxFlow(0, N-1) << endl;

    return 0;
}