#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector <pair<int, int>> Runpath;
vector <vector<char>> Map;
vector <vector<bool>> isvisited;

void getHowRobotWork(vector <vector<char>> Map, int x, int y) {
	if (x < 0 || x >= Map.size() || y < 0 || y >= Map[0].size()) {
		return;
	}
	if (isvisited[x][y]) {
		cout << "进行循环运动" << endl;
	}
	if (!isvisited[x][y]) {
		isvisited[x][y] = true;
		if (Map[x][y] == 'w' || Map[x][y] == 'W') {
			Runpath.push_back(make_pair(x, y));
			getHowRobotWork(Map, x, --y);
		}
		else if (Map[x][y] == 's' || Map[x][y] == 'S') {
			Runpath.push_back(make_pair(x, y));
			getHowRobotWork(Map, ++x, y);
		}
		else if (Map[x][y] == 'e' || Map[x][y] == 'E') {
			Runpath.push_back(make_pair(x, y));
			getHowRobotWork(Map, x, ++y);
		}
		else if (Map[x][y] == 'n' || Map[x][y] == 'N') {
			Runpath.push_back(make_pair(x, y));
			getHowRobotWork(Map, --x, y);
		}
	}
}

int main() {
	int x, y;
	char data;
	cout << "请输入地图的水平长度x与竖直长度y" << endl;
	cin >> x >> y;
	for (int i = 0; i < y; i++) {
		cout << "请依次输入第" << i + 1 << "行的字母:" << endl;
		vector <char> v1;
		vector <bool> v2;
		for (int j = 0; j < x; j++) {
			cin >> data;
			v1.push_back(data);
			v2.push_back(false);
		}
		Map.push_back(v1);
		isvisited.push_back(v2);
	}
	cout << "请输入机器人起始坐标x2,y2" << endl;
	int x2, y2;
	cin >> x2 >> y2;
	getHowRobotWork(Map, x2, y2);
	for (vector<pair<int, int>> ::iterator it = Runpath.begin(); it != Runpath.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
