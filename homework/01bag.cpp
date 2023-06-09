//
// Created by DeathWind on 2023/6/9.
//

#include <iostream>
#include <vector>

using namespace std;

int solveBagDP(const vector<int> &weight,const vector<int> &value,const int &size) {
    int len = weight.size();
    //dp矩阵，行号为物品号，列号为背包容量
    vector<vector<int>> dpm = vector<vector<int>>(len, vector<int>(size, 0));



}

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};

    int ansDP = solveBagDP(weight, value,4);
    cout << "ansDP: " << ansDP << endl;
}
