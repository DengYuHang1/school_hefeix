#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

int simulate(vector<int>& x, vector<int>& y, vector<int>& t, int A, int B, char direction) {
    int step = 0;
    int current_A = A;
    int current_B = B;
    set<pair<int, int> > visited;
    
    while (visited.find(make_pair(current_A, current_B)) == visited.end()) {
        if (t[current_A] != t[current_B]) {
            return step;
        }
        visited.insert(make_pair(current_A, current_B));
        
        int next_A, next_B;
        if (direction == 'X') {
            next_A = x[current_A];
            next_B = x[current_B];
        } else {
            next_A = y[current_A];
            next_B = y[current_B];
        }
        
        current_A = next_A;
        current_B = next_B;
        ++step;
    }
    return -1; // 表示没有检测到解决方案或循环
}

void processTestCase(int T, int idx) {
    int n, A, B;
    string line;
    getline(cin, line); // 读整行，包括空格
    istringstream iss(line);
    iss >> n >> A >> B;

    vector<int> x(n), y(n), t(n);
    int count = 0;
    while (count < n) {
        getline(cin, line); 
        istringstream iss(line);
        iss >> x[count] >> y[count] >> t[count];
        ++count;
    }

    int step_X = simulate(x, y, t, A, B, 'X');
    int step_Y = simulate(x, y, t, A, B, 'Y');

    // 确定最小步长
    int min_step = max(step_X, step_Y);
    if (min_step == -1) {
        cout << "GG" << endl;
    } else {
        cout << min_step << endl;
    }
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); 
    
    for (int i = 0; i < T; ++i) {
        processTestCase(T, i);
    }
    
    return 0;
}
