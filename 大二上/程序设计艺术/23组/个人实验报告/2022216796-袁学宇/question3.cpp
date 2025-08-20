#include <iostream>
#include <math.h>
using namespace std;

int dp[1000][1000]; 

void getLongest(string str1, string str2) {
	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {//三种情况，第一个字符串的第i个字母与第二个的第j个字母没有一个是在最长序列里面的，或者第一个字符串的第i个字母在最长序列里面，或者第二个字符串的第j个字母在最长序列里面
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
}

void findLongestString(string str1, string str2, int i, int j) {//i和j是第几个字母的编号，因为已知最长序列是多少，所以只要碰到一样的字母就可以输出
	if (i == 0 || j == 0) {
		return;
	}
	if (str1[i - 1] == str2[j - 1]) {
		findLongestString(str1, str2, i - 1, j - 1);
		cout << str1[i - 1];
	}
	else if (dp[i - 1][j] > dp[i][j - 1]) {//说明第二个字符串的第j个字符就在最长序列里面
		findLongestString(str1, str2, i - 1, j);
	}
	else {//说明第一个字符串的第i个字符就在最长序列里面或者若等于则都不在最长序列里面
		findLongestString(str1, str2, i, j - 1);
	}
}

int main() {
	string str1, str2;
	cout << "请输入第一个字符串" << endl;
	cin >> str1;
	cout << "请输入第二个字符串" << endl;
	cin >> str2;
	getLongest(str1, str2);
	cout << "最大子串长度为:";
	cout << dp[str1.size()][str2.size()] << endl;
	findLongestString(str1, str2, str1.size(), str2.size());
	return 0;
}
