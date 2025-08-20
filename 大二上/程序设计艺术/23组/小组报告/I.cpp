#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Cup {
    int p;
    int l;
    double expectedValue(int beta) const {
        return p * (double)beta / (l + beta);
    }
};

int main() {
    int n, t, q;
    cin >> n >> t >> q;
    vector<Cup> cups(n);
    for (int i = 0; i < n; ++i) {
        cin >> cups[i].p;
    }
    for (int i = 0; i < n; ++i) {
        cin >> cups[i].l;
    }

    vector<double> dp(t + 1, 0.0);
    for (int i = 0; i < n; ++i) {
        for (int j = t; j >= 0; --j) {
            for (int beta = 1; beta <= min(cups[i].l, j); ++beta) {
                dp[j] = max(dp[j], dp[j - beta] + cups[i].expectedValue(beta));
            }
        }
    }

    cout << fixed << setprecision(9) << dp[t] << endl;

    for (int i = 0; i < q; ++i) {
        int tj, rj;
        cin >> tj >> rj;
        --rj;
        if (tj == 1) {
            cups[rj].l++;
        }
        else {
            cups[rj].l--;
        }
        fill(dp.begin(), dp.end(), 0.0);
        for (int i = 0; i < n; ++i) {
            for (int j = t; j >= 0; --j) {
                for (int beta = 1; beta <= min(cups[i].l, j); ++beta) {
                    dp[j] = max(dp[j], dp[j - beta] + cups[i].expectedValue(beta));
                }
            }
        }
        cout << fixed << setprecision(9) << dp[t] << endl;
    }

    return 0;
}
