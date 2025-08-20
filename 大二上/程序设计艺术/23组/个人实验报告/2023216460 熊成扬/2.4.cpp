#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct State 
{
    int x, y;       // 两个容器的当前水量
    vector<string> steps;  // 到达该状态的步骤
    
    State(int x, int y) : x(x), y(y) {}
    State(int x, int y, const vector<string> &s) : x(x), y(y), steps(s) {}
};

class BFSSolver {
private:
    int jug1, jug2, target;

    // 检查状态是否有效
    bool isValid(int x, int y)
    {
        return x >= 0 && x <= jug1 && y >= 0 && y <= jug2;
    }

    // 生成下一个可能的状态
    vector<State> getNextStates(const State &current) 
    {
        vector<State> nextStates;
        vector<string> steps = current.steps;

        // 填满jug1
        if (current.x < jug1) 
        {
            steps.push_back("Fill jug1");
            nextStates.emplace_back(jug1, current.y, steps);
            steps.pop_back();
        }

        // 填满jug2
        if (current.y < jug2) 
        {
            steps.push_back("Fill jug2");
            nextStates.emplace_back(current.x, jug2, steps);
            steps.pop_back();
        }

        // 清空jug1
        if (current.x > 0) 
        {
            steps.push_back("Empty jug1");
            nextStates.emplace_back(0, current.y, steps);
            steps.pop_back();
        }

        // 清空jug2
        if (current.y > 0) 
        {
            steps.push_back("Empty jug2");
            nextStates.emplace_back(current.x, 0, steps);
            steps.pop_back();
        }

        // 从jug1倒入jug2
        if (current.x > 0 && current.y < jug2) 
        {
            int pour = min(current.x, jug2 - current.y);
            steps.push_back("Pour jug1 to jug2");
            nextStates.emplace_back(current.x - pour, current.y + pour, steps);
            steps.pop_back();
        }

        // 从jug2倒入jug1
        if (current.y > 0 && current.x < jug1) 
        {
            int pour = min(current.y, jug1 - current.x);
            steps.push_back("Pour jug2 to jug1");
            nextStates.emplace_back(current.x + pour, current.y - pour, steps);
            steps.pop_back();
        }

        return nextStates;
    }

public:
    BFSSolver(int j1, int j2, int t) : jug1(j1), jug2(j2), target(t) {}

    vector<string> bfs() 
    {
        queue<State> q;
        set<pair<int, int>> visited;

        q.emplace(0, 0);
        visited.insert({0, 0});

        while (!q.empty()) 
        {
            State current = q.front();
            q.pop();

            // 检查是否达到目标
            if (current.x == target || current.y == target) 
            {
                return current.steps;
            }

            // 生成下一步可能的状态
            for (const auto &next : getNextStates(current)) 
            {
                if (isValid(next.x, next.y) && visited.find({next.x, next.y}) == visited.end()) 
                {
                    q.push(next);
                    visited.insert({next.x, next.y});
                }
            }
        }

        // 返回空vector
        return {};
    }
};

int main() 
{
    int jug1, jug2, target;
    cout << "jug1: ";
    cin >> jug1;
    cout << "jug2: ";
    cin >> jug2;
    cout << "target: ";
    cin >> target;

    BFSSolver solver(jug1, jug2, target);
    vector<string> solution = solver.bfs();

    if (solution.empty()) 
    {
        cout << "No Solution" << endl;
    } 
    else 
    {
        cout << solution.size() << " steps:" << endl;
        for (const auto &step : solution) 
        {
            cout << step << endl;
        }
    }

    return 0;
}