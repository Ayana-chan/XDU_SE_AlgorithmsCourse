//
// Created by DeathWind on 2023/6/9.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;


vector<int> Dijkstra(vector<vector<int>> *graphMatrix, int source) {

}

int main() {
    string inputStr =
            R"(7 12 0
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

    int nodeNum, edgeNum, source;
    inputStream >> nodeNum;
    inputStream >> edgeNum;
    inputStream >> source;

    //邻接矩阵，行号为from，列号为to
    auto *graphMatrix = new vector<vector<int>>(nodeNum, vector<int>(nodeNum, 0));

    int from, to, dis;
    for (int i = 0; i < edgeNum; i++) {
        inputStream >> from;
        inputStream >> to;
        inputStream >> dis;
        cout << from << "--" << dis << "-->" << to << endl;
        (*graphMatrix)[from][to] = dis;
    }


    delete (graphMatrix);
    return 0;
}







