#include <iostream>
#include <fstream>
using namespace std;

int partition(int arr[], int low, int high);

// 快速排序函数
void quickSort(int arr[], int low, int high) {
	int pivot; 
    if (low < high) {
         pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// 分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择最后一个元素作为枢轴
    int i = (low - 1);  // i是小于枢轴的元素的索引

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
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

    // 对数据进行处理（使用快速排序）
    quickSort(a, 0, n - 1);

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
