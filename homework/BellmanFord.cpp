//
// Created by DeathWind on 2023/6/10.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Edge {
public:
    int from;
    int to;
    int dis;

    Edge(int from, int to, int dis) : from(from), to(to), dis(dis) {}
};

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
 * Bellman-Ford算法
 * @param graphMatrix 邻接矩阵
 * @param source 起点
 * @return 前驱数组
 */
vector<int> bellmanFord(const int &nodeNum, vector<Edge> *edgeArray, const int &source, const int &maxTime) {
    //是否为最短路径
    vector<bool> marked(nodeNum, false);
    //到源点距离
    vector<int> dis(nodeNum, -1);
    //前驱点
    vector<int> pre(nodeNum, -1);

    dis[source] = 0;

    //迭代|V|-1次(maxTime)
    for (int i = 0; i < maxTime; i++) {
        int isChanged = false;//若迭代一次之后什么都不改变，则可以退出

        for (Edge e:*edgeArray) {

        }
    }


    return pre;
}

int main() {
    string inputStr =
            R"(7 12 0 6 11
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

    int nodeNum, edgeNum, source, sink, maxTime;
    inputStream >> nodeNum;
    inputStream >> edgeNum;
    inputStream >> source;//起点
    inputStream >> sink;//终点
    inputStream >> maxTime;//迭代次数，一般为|V|-1
    cout << "calculate from " << source << " to " << sink << " in " << maxTime << "times" << endl;

    auto *edgeArray = new vector<Edge>(edgeNum);

    int from, to, dis;
    for (int i = 0; i < edgeNum; i++) {
        inputStream >> from;
        inputStream >> to;
        inputStream >> dis;
        cout << from << "--" << dis << "-->" << to << endl;
        (*edgeArray)[i] = Edge(from, to, dis);
    }

    //BellmanFord------------------
    cout << endl << "--- BellmanFord begin ---" << endl << endl;

    auto preArray = bellmanFord(nodeNum, edgeArray, source, maxTime);
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

    cout << endl << "--- BellmanFord end   ---" << endl << endl;

    delete (edgeArray);
    return 0;
}
