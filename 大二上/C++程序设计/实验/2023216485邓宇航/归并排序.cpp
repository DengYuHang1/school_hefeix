#include <iostream>
#include <fstream>
using namespace std;

void merge(int arr[], int l, int m, int r);

 
// 归并排序函数
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;  // 计算中间索引
        mergeSort(arr, l, m);     // 递归排序左半部分
        mergeSort(arr, m + 1, r); // 递归排序右半部分
        merge(arr, l, m, r);      // 合并两个已排序的部分
    }
}

// 合并函数
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // 左半部分的长度
    int n2 = r - m;      // 右半部分的长度

    // 创建临时数组
    int L[n1], R[n2];

    // 复制数据到临时数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 合并临时数组到原数组
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余的元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
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

    // 对数据进行处理（使用归并排序）
    mergeSort(a, 0, n - 1);

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
