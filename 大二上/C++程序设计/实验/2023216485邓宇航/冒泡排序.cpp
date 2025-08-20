#include <iostream>
#include <fstream>
using namespace std;

// 冒泡排序函数
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // 如果在某次内循环中没有发生任何交换，则说明数组已经排序完成，可以提前结束排序
        if (!swapped)
            break;
    }
}

int main() {
    // 读取数据
    ifstream read("data.txt");
    const  int n = 100000;
    int a[100000];
    for (int i = 0; i < n; i++) {
        read >> a[i];
    }
    read.close();

    // 对数据进行处理（使用冒泡排序）
    bubbleSort(a, n);

    // 将运算结果存放到文件里
    ofstream result;
    result.open("sort.txt");
    for (int i = 0; i < n; i++) {
        result << a[i] << " ";
    }
    result.close();
/* 
    // 打印排序结果（可选）
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
*/
    return 0;
}
