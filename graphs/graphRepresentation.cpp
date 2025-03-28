#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;
    vector<pair<int,int>> adjList[n+1];
    vector<vector<int>> adjMatrix(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)adjMatrix[i][j]==0;
    }
    vector<tuple<int,int,int>> edgeList;

    int e1,e2,w;
    cout << "Enter edges: " << endl;
    for(int i =0;i<e;i++){
        cin >> e1 >> e2 >> w;
        adjList[e1].push_back({e2,w});
        adjList[e2].push_back({e1,w});
        edgeList.push_back({e1,e2,w});
        adjMatrix[e1][e2]=w;
    }
}