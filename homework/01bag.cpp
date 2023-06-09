//
// Created by DeathWind on 2023/6/9.
//

#include <iostream>
#include <vector>

using namespace std;

void dfsBag(int index, int &restBagSize, int &currValue, int &maxValue, const vector<int> &weight,
            const vector<int> &value) {
    if (index >= weight.size()) {
        return;
    }
    //不塞
//    cout<<"no  currValue: "<<currValue<<" index: "<<index<<endl;
    dfsBag(index + 1, restBagSize, currValue, maxValue, weight, value);
    //能塞
//    cout<<"restBagSize: "<<restBagSize<<endl;
    if (restBagSize >= weight[index]) {
        //塞
        restBagSize -= weight[index];
        currValue += value[index];
//        cout<<"yes currValue: "<<currValue<<" index: "<<index<<endl;
        //检测是否最大，更新结果
        if (currValue > maxValue) {
            maxValue = currValue;
        }
        dfsBag(index + 1, restBagSize, currValue, maxValue, weight, value);
        restBagSize += weight[index];
        currValue -= value[index];
    }
}

int solveBagRecursion(const vector<int> &weight, const vector<int> &value, int bagSize) {
    int currValue = 0;
    int maxValue = 0;
    dfsBag(0, bagSize, currValue, maxValue, weight, value);
    return maxValue;
}

int solveBagDP(const vector<int> &weight, const vector<int> &value, const int &bagSize) {
    int itemNum = weight.size();
    if (itemNum == 0) {
        return 0;
    }
//    cout << "itemNum: " << itemNum << " bagSize: " << bagSize << endl;

    //dp矩阵，行号为物品号，列号为背包容量
    //j=0时，值都为0
    vector<vector<int>> dpm = vector<vector<int>>(itemNum, vector<int>(bagSize + 1, 0));

    //对物品i=0，可以直接初始化j，塞得下的都变成value[0]
    for (int j = weight[0]; j <= bagSize; j++) {
        dpm[0][j] = value[0];
    }

    // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])
    for (int i = 1; i < itemNum; i++) {
        for (int j = 1; j <= bagSize; j++) {

            if (weight[i] > j) {
//                cout << "hello1 " << i << " " << j << endl;
                //塞不下了
                dpm[i][j] = dpm[i - 1][j];
            } else {
//                cout << "hello2 " << i << " " << j << endl;
                //不放这个东西
                int notPutValue = dpm[i - 1][j];
                //放这个东西，则还剩j-weight[i]的容量来放前面的物品
                int putValue = dpm[i - 1][j - weight[i]] + value[i];
                dpm[i][j] = max(notPutValue, putValue);
            }
        }
    }

    return dpm[itemNum - 1][bagSize];
}

int main() {
//    vector<int> weight = {1, 3, 4};
//    vector<int> value = {15, 20, 30};
//    int bagSize = 4;
    vector<int> weight = {3, 5, 1, 2, 2};
    vector<int> value = {4, 5, 2, 1, 3};
    int bagSize = 8;

    int ansDP = solveBagDP(weight, value, bagSize);
    cout << "ansDP: " << ansDP << endl;

    int ansRecursion = solveBagRecursion(weight, value, bagSize);
    cout << "ansRecursion: " << ansRecursion << endl;

    return 0;
}
