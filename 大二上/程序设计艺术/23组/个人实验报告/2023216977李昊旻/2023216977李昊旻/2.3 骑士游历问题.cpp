#include<iostream>
#include<iomanip>
using namespace std;
const int N = 8;//棋盘大小
int travel[8][8] = { 0 };//棋盘初始化
int record = 0;//下棋的步数
bool isVisited(int i, int j)//该位置是否下过棋
{
	if (travel[i][j] == 0) return false;
	else return true;
}
bool inChessBoard(int i, int j)//是否还在棋盘中
{
	if (i >= 0 && i < N && j >= 0 && j < N) return true;
	else return false;
}
void play(int x, int y) //下棋
{		
	if (record == N * N)  return;//棋盘已经下满了
	if (!isVisited(x, y) && inChessBoard(x, y)) {
		record++;//步数加一
		travel[x][y] = record;//将步数填进下棋的位置
		//下棋的位置
		play(x + 1, y + 2);
		play(x + 2, y + 1);
		play(x + 2, y - 1);
		play(x + 1, y - 2);
		play(x - 1, y - 2);
		play(x - 2, y - 1);
		play(x - 2, y + 1);
		play(x - 1, y + 2);
		return;
	}
	return;
}
int main() {
	int x, y;
	cin >> x;
	cin >> y;//下第一步棋
	play(x, y);//开始下棋
	for (int row = 0; row < N; row++)//每行
	{
		for (int column = 0; column < N; column++)//一行中的每一列
		{
			cout << setw(2) << travel[row][column] << " ";
		}
		cout << endl;//每一行下完棋之后换行
	}
	return 0;
}
