#include <iostream>
#include <stdlib.h>
using namespace std;

void pourWater(int a, int b, int L);

int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


void pourWater(int a, int b, int L) {
    // 检查是否可以达到 L 升
    if (L > a && L > b || L % gcd(a, b) != 0) {
        cout<<"No Solution"<<endl;
        return;
    }

    // 使用变量来模拟两个容器的水量
    int x = 0; // 容器 A
    int y = 0; // 容器 B
	int t = 0; //步骤数量 
    // 过程步骤
    while (x != L && y != L) {
        // 如果容器 A 为空，则填满 A
        if (x == 0) {
        	t++; 
            x = a;
            cout<<"步骤"<<t<<":装满A"<<endl;
            cout<<"此时各容器容量为：A="<<x<<" ,B="<<y<<endl<<endl; 
        }
        // 如果容器 B 满了，则清空 B
        else if (y == b) {
            y = 0;
            t++;
            cout<<"步骤"<<t<<":清空B"<<endl;
            cout<<"此时各容器容量为：A="<<x<<" ,B="<<y<<endl<<endl; 
        }
        // 倒水：从 A 倒入 B
        else {
            int pour = (x < (b - y)) ? x : (b - y); // 能倒入 B 的水量
            t++;
            x -= pour;
            y += pour;
            cout<<"步骤"<<t<<":将A中的水倒入B中"<<endl;
            cout<<"此时各容器容量为：A="<<x<<" ,B="<<y<<endl<<endl; 
        }
    }

}

int main() {
    int a, b, L;
    cout<<"请输入两个容器的容积以及所求体积L：";
    cin>>a>>b>>L;

    pourWater(a, b, L);
    return 0;
}

