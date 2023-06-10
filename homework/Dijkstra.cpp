//
// Created by DeathWind on 2023/6/9.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> findPathFromPreArray(const vector<int> &preArray, const int &sink) {
    int len = preArray.size();
    vector<int> path;

    int currNode = sink;
    while (currNode >= 0) {
        path.emplace_back(currNode);
        currNode = preArray[currNode];
    }
    reverse(path.begin(), path.end());

    return path;
}

/**
 * Dijkstra算法
 * @param graphMatrix 邻接矩阵
 * @param source 起点
 * @return 前驱数组
 */
vector<int> dijkstra(vector<vector<int>> *graphMatrix, const int &source) {
    int nodeNum = graphMatrix->size();
    //是否为最短路径
    vector<bool> marked(nodeNum, false);
    //到源点距离
    vector<int> dis(nodeNum, -1);
    //前驱点
    vector<int> pre(nodeNum, -1);

    dis[source] = 0;

    //计算最短路径
    //每次都会算出一个最短路径，因此只会循环这么多次
    for (int i = 1; i < nodeNum; i++) {
        //取出未被标记的点中最短的
        int minDis = -1;
        int minIdx = -1;
        for (int index = 0; index < nodeNum; index++) {
            if (!marked[index] && dis[index] != -1 && (minIdx == -1 || dis[index] < minDis)) {
                minIdx = index;
                minDis = dis[index];
            }
        }
        //标记此点
//        cout<<"mark: "<<minIdx<<" dis: "<<minDis<<endl;
        marked[minIdx] = true;
        //松弛相邻点
        for (int aim = 0; aim < nodeNum; aim++) {
            int deltaDis = (*graphMatrix)[minIdx][aim];
            if (deltaDis < 0) {
                continue;
            }
            int newDis = minDis + deltaDis;
            if (!marked[aim] && (dis[aim] == -1 || newDis < dis[aim])) {
                dis[aim] = newDis;
                //标记前驱
                pre[aim] = minIdx;
            }
        }
    }

    return pre;
}

int main() {
    string inputStr =
            R"(7 12 0 6
    0 1 20
    0 2 50
    0 3 30
    1 2 25
    1 5 70
    2 3 40
    2 5 50
    2 4 25
    3 4 55
    4 5 10
    4 6 70
    5 6 50
)";
    stringstream inputStream(inputStr);

    int nodeNum, edgeNum, source, sink;
    inputStream >> nodeNum;
    inputStream >> edgeNum;
    inputStream >> source;//起点
    inputStream >> sink;//终点
    cout << "calculate from " << source << " to " << sink << endl;

    //邻接矩阵，行号为from，列号为to
    auto *graphMatrix = new vector<vector<int>>(nodeNum, vector<int>(nodeNum, -1));

    int from, to, dis;
    for (int i = 0; i < edgeNum; i++) {
        inputStream >> from;
        inputStream >> to;
        inputStream >> dis;
        cout << from << "--" << dis << "-->" << to << endl;
        (*graphMatrix)[from][to] = dis;
    }

    //Dijkstra------------------
    cout << endl << "--- Dijkstra begin ---" << endl << endl;

    auto preArray = dijkstra(graphMatrix, source);
    cout << "preArray: ";
    for (int p : preArray) {
        cout << p << " ";
    }
    cout << endl;

    auto path = findPathFromPreArray(preArray, sink);
    cout << "path: ";
    for (int p : path) {
        cout << p << " ";
    }
    cout << endl;

    cout << endl << "--- Dijkstra end   ---" << endl << endl;

    delete (graphMatrix);
    return 0;
}







