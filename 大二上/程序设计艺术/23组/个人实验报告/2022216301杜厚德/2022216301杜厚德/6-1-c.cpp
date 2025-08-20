#include <iostream>
#include <string>
#define MAXLEN 255
using namespace std;

// 求next数组
void getNext(const string& T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0; // 初始化next数组的第一个值
    while (i < T.length()) {
        if (j == 0 || T[i-1] == T[j-1]) { // 如果匹配成功或j为0
            ++i;
            ++j;
            next[i] = j; // 更新next数组
        }
        else {
            j = next[j]; // 回溯
        }
    }
}

// 改进next数组
void getNextval(const string& T, int next[], int nextval[]) {
    nextval[1] = 0; // 初始化nextval数组的第一个值
    for (int j = 2; j <= T.length(); j++) {
        if (T[next[j]-1] == T[j-1]) { // 如果字符相等
            nextval[j] = nextval[next[j]]; // 使用nextval数组的值
        }
        else {
            nextval[j] = next[j]; // 使用next数组的值
        }
    }
}

// KMP算法
int KMP(const string& S, const string& T, int next[]) {
    int i = 1, j = 1;
    while (i <= S.length() && j <= T.length()) {
        if (j == 0 || S[i-1] == T[j-1]) { // 如果匹配成功或j为0
            ++i;
            ++j;
        }
        else {
            j = next[j]; // 回溯
        }
    }
    if (j > T.length()) { // 匹配成功,返回首字母位置
        return i - T.length();
    }
    else {
        return 0; // 匹配失败
    }
}

int main() {
    string S, T;
    cout << "输入字符串1：";//主串
    cin >> S;
    cout << "输入字符串2：";//子串
    cin >> T;
    int next[MAXLEN];
    int nextval[MAXLEN];
    // 求next数组
    getNext(T, next);
    for(int i=1; i<=T.length(); i++)
        cout << next[i]<< endl;
    cout << "value"<< endl;
    // 求nextval数组
    getNextval(T, next, nextval);
    for(int i=1; i<=T.length(); i++)
        cout << nextval[i]<< endl;
    // 判断是否匹配
    int res = KMP(S, T, nextval);
    if (res != 0) {
        cout << "存在匹配！" << endl;
        cout << "匹配位置：" << res << endl;
    }
    else {
        cout << "不存在匹配！" << endl;
    }
}
