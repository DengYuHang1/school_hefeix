#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <string> Cha;

bool cmp1(string x, string y) {
	return x.at(0) < y.at(0);
}

bool cmp2(char x, char y) {
	return x < y;
}

void encryption() {
	string a;
	for (int i = 0; i < Cha.size(); i++) {
		a.push_back(Cha[i].back());//取尾部字母放入a中
	}
	cout << "加密结果为" << a << endl;
}

void decryption(char head, string ciphertext) {
	string S = ciphertext;
	string ans;
	vector <bool> isvisited(S.length());
	sort(S.begin(), S.end(), cmp2); //由密文得到稳定排序后的字符串的首字母序列,aeelmpx放入S中
	int i = S.find_first_of(head);   //在S中找到首字符第一次出现的位置，因为是稳定排序，所以一定是第一次出现的位置，此位置的字符串就是原字符串
	for (int j = 0; j < S.length(); j++) {
		ans = ciphertext[i] + ans;//第一次循环的时候找到的就是原字符串的尾字符
		i = S.find_last_of(ciphertext[i]); //找到以原字符串中以ciphertext[i]为开头的那个字符串在排序后序列中的位置        
		//此位置在密文中相对应的位置就是其前面一个字符
		while (isvisited[i]) {  //因为字符可能是重复的，而i = S.find_last_of(ciphertext[i]);则会一直找到一个重复的位置i，所以我们要标记已经被访问过的位置
			--i;
		}
		isvisited[i] = true;
	}
	cout << ans << endl;
}


int main() {
	string str;
	cout << "请输入一个字符串" << endl;
	cin >> str;
	cout << "输入1选择加密，输入2选择解密" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		for (int i = 0; i < str.length(); i++) {
			string a = str.substr(i);
			string b = str.substr(0, i);
			a += b;
			Cha.push_back(a);
		}
		stable_sort(Cha.begin(), Cha.end(), cmp1);
		/*for (int i = 0; i < Cha.size(); i++) {
			cout << Cha[i] << endl;
		}*/
		encryption();
	}
	else if (x == 2) { //对密文进行解密，需要知道原字符的首字母，不然无法正确解密
		cout << "请输入原字符的首字母在密文中的下标位置" << endl;
		int index;
		cin >> index;
		char ch = str[index];
		decryption(ch, str);
	}
	return 0;
}
