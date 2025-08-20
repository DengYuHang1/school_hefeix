#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int MOD = 1e9 + 7;

// 计算两个数的最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 判断两个数是否互质
bool areCoprime(int a, int b) {
    return gcd(a, b) == 1;
}

// 计算符合条件的方案数
int countMaxPowerWays(int n, vector<int>& a) {
    // 计算所有互质的位置对
    int coprimePairs = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (areCoprime(i, j)) {
                coprimePairs++;
            }
        }
    }

    // 统计已知的互质新能源量对
    int knownCoprimeCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > 0 && a[j] > 0 && areCoprime(a[i], a[j])) {
                knownCoprimeCount++;
            }
        }
    }

    // 如果没有已知的互质对，则方案数等于位置对数
    int result = coprimePairs;
    if (knownCoprimeCount > 0) {
        result = knownCoprimeCount;
    }

    return result % MOD;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << countMaxPowerWays(n, a) << endl;
    }
    return 0;
}
