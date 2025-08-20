#include <iostream>
#include <fstream>
using namespace std;

// 插入排序函数
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // 将 arr[i] 插入到已排序的序列 arr[0..i-1] 中
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    // 对数据进行处理（使用插入排序）
    insertionSort(a, n);

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
