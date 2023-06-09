//
// Created by DeathWind on 2023/6/8.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * 将根结点置换到它该在的地方
 * @param aimIndex 根结点下标
 * @param maxLen 堆的最大下标
 */
void adjustHeap(vector<int> &arr, int aimIndex, int maxLen) {
    int aimValue = arr[aimIndex];
    int k = 2 * aimIndex + 1;//左孩子

    while (k < maxLen) {
        //取孩子中最大的
        if (k + 1 < maxLen) { //有右孩子
            if (arr[k] < arr[k + 1]) {
                k++;
            }
        }
        //置换
        if (arr[k] > aimValue) {
            arr[aimIndex] = arr[k];
            aimIndex = k;
        } else {
            break; //未发生交换，结束
        }

        k = 2 * k + 1; //取左孩子
    }

    arr[aimIndex] = aimValue;
}

void heapSort(vector<int> &arr) {
    int len = arr.size();

    //自下而上构建大顶堆
    for (int i = len / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, i, len);
    }

//    cout << endl << "init heap: ";
//    for (int i : arr) {
//        cout << i << " ";
//    }
//    cout << endl;

    //逐个提取最大值
    for (int i = len - 1; i > 0; i--) {
        //将最大值和堆最后一个交换
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        //让新的堆顶置换到该去的地方
        adjustHeap(arr, 0, i);
    }
}

int main() {
    vector<int> arr = {8, 6, 13, 7, 5, 4, 11, 14};
    cout << "origin: ";
    for (int i : arr) {
        cout << i << " ";
    }

    heapSort(arr);
    cout << endl << "result: ";
    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}
