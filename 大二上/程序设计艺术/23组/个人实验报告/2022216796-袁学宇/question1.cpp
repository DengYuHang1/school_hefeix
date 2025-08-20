#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int maze[5][7] = { {1,1,0,0,1,0,0},
                   {0,1,1,1,1,1,1},
                   {0,0,1,1,1,0,1},
                   {0,0,1,0,1,0,0},
                   {0,0,1,0,1,0,1} };

vector<pair<int, int>> path;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
bool isvisited[5][7];


void searchInMaze(vector<pair<int, int>>tpath, int x, int y, bool(*isvisited)[7]) {   //走迷宫
    if (x > 4 || x < 0 || y > 6 || y < 0) {
        return;
    }
    if (x == 4 && y == 4) {
        path = tpath;
        return;
    }
    isvisited[x][y] = true;
    for (int ix = 0; ix < 4; ix++)//四个方向搜索 
    {
        if (maze[x + dir[ix][0]][y + dir[ix][1]] == 1 && !isvisited[x + dir[ix][0]][y + dir[ix][1]])
        {
            tpath.push_back(make_pair(x, y));  
            searchInMaze(tpath, x + dir[ix][0], y + dir[ix][1], isvisited);
            tpath.pop_back();
        }
    }
}

int main() {
    vector<pair<int, int>>tpath;
    searchInMaze(tpath, 0, 0, isvisited);
    cout << "走出迷宫的遍历坐标为:" << endl;
    for (vector<pair<int, int>> ::iterator it = path.begin(); it != path.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
