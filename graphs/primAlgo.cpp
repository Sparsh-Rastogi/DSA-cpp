#include <bits/stdc++.h>
using namespace std;
void printEdgeList(vector<tuple<int,int,int>> edgeList){
    for(auto u: edgeList){
        cout << get<0>(u) << " " << get<1>(u) << " " << get<2>(u) << endl;
    }
    return;
}
struct isGreater {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<0>(a) > get<0>(b);  // Min-heap based on first element
    }
};
int main(){
    int n,e;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;
    vector<pair<int,int>> adjList[n+1];
    bool visited[n+1] = {0};
    vector<tuple<int,int,int>> edgeList;
    int e1,e2, w;
    cout << "Enter edges: " << endl;
    for(int i =0;i<e;i++){
        cin >> e1 >> e2 >> w;
        adjList[e1].push_back({e2,w});
        adjList[e2].push_back({e1,w});
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,isGreater> pQ;
    
    pQ.push({0,0,-1});
    tuple<int,int,int> temp;
    while(!pQ.empty()){
        temp = pQ.top(); pQ.pop();
        if(visited[get<1>(temp)]){continue;}
        if(get<2>(temp)!=-1){
            edgeList.push_back(temp);
        }
        visited[get<1>(temp)] = 1;
        for(auto i: adjList[get<1>(temp)]){
            if(!visited[i.first]){
                // cout << "pushing: " << i.second << " " << i.first << " " << get<1>(temp) << endl;
                pQ.push({i.second,i.first,get<1>(temp)});
            }
        }
    }
    printEdgeList(edgeList);

}