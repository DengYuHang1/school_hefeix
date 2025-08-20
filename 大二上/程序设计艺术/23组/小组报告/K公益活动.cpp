#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 2005; // 最大的数轴长度
const int INF = 1e9;    // 用一个足够大的数表示无穷大，表示无法到达

int n, m; // n为数轴长度，m为志愿者数量，q为任务数量
int dist[MAXN][MAXN]; // dist[i][j]表示从起点到位置i且在时间j时的最小志愿者数量

struct Edge {
    int to, time; // to表示目标节点，time表示到达目标节点所需的时间
};

vector<Edge> graph[MAXN]; // 邻接表表示图

// 添加边，表示志愿者的移动
void addEdge(int from, int to, int time) {
    graph[from].push_back((Edge){to, time});
}

// 使用Dijkstra算法找到从1号点到p号点在最晚e时刻的最短路径
void dijkstra(int p, int e) {
    memset(dist, INF, sizeof(dist)); // 初始化dist数组为无穷大
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pq.push(make_pair(0, make_pair(1, 1))); // 起点(1, 1)，即位置1，时间1
    dist[1][1] = 0;

    while (!pq.empty()) {
        pair<int, pair<int, int> > front = pq.top();
        pq.pop();
        int d = front.first, u = front.second.first, t = front.second.second;

        if (d > dist[u][t]) continue; // 如果当前点的距离不是最短，跳过

        // 遍历所有邻接点
        for (size_t i = 0; i < graph[u].size(); i++) {
            Edge edge = graph[u][i];
            int v = edge.to, next_t = (t + edge.time) % e; // 计算下一个时间点，确保在0到e-1之间
            int new_d = d + 1; // 新的距离是当前距离加1

            // 如果找到了更短的路径，更新dist数组，并入队
            if (new_d < dist[v][next_t]) {
                dist[v][next_t] = new_d;
                pq.push(make_pair(new_d, make_pair(v, next_t)));
            }
        }
    }

    // 找到最小的志愿者数量
    int min_volunteers = INF;
    for (int i = 0; i < e; i++) {
        if (dist[p][i] != INF) {
            min_volunteers = min(min_volunteers, dist[p][i]);
        }
    }

    if (min_volunteers == 0) {
        cout << "-1\n"; // 如果无法到达，输出-1
    } else {
        cout << min_volunteers << "\n"; // 否则输出最少志愿者数量
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t, c, p;
        cin >> t >> c >> p;
        // 分别表示志愿者的起始位置、开始时间、移动距离
        if (c >= 0) {
            addEdge(p, min(p + c, n), c); // 向右移动
        } else {
            addEdge(p, max(p + c, 1), -c); // 向左移动
        }
    }
	int q;
	cin>>q;
    for (int i = 0; i < q; i++) {
        int e, p;
        cin >> e >> p;
        dijkstra(p, e); // 对每个任务执行Dijkstra算法
    }

    return 0;
}
