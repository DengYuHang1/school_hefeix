#include <iostream>
#include <fstream>
using namespace std;

// 选择排序函数
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    // 读取数据
    ifstream read("data.txt");
    const int n = 100000;
    int a[100000];
    for (int i = 0; i < n; i++) {
        read >> a[i];
    }
    read.close();

    // 对数据进行处理（使用选择排序）
    selectionSort(a, n);

    // 将运算结果存放到文件里
    ofstream result;
    result.open("sort.txt");
    if (result.is_open()) {
        for (int i = 0; i < n; i++) {
            result << a[i] << " ";
        }
        result.close();
    } else {
        cerr << "Unable to open file sort.txt" << endl;
    }
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
