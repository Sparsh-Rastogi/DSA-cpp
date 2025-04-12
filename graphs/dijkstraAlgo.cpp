#include <bits/stdc++.h>
using namespace std;
struct isGreater {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return get<0>(a) > get<0>(b);  // Min-heap based on first element
    }
};
int main(){
    priority_queue<int> q;
    int n,e;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;
    long long int dist[n+1];
    for(int i = 0;i<n+1;i++){
        if(i==0){dist[i]=0;}
        else{
            dist[i]=1e9;
        }
    }
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
    priority_queue<pair<int,int>,vector<pair<int,int>>,isGreater> pQ;
    pQ.push({0,0});
    pair<int,int> temp; //weight node
    while(!pQ.empty()){
        temp = pQ.top(); pQ.pop();
        for(auto u: adjList[get<1>(temp)]){
            if(get<0>(temp)+u.second<dist[u.first]){
                dist[u.first] = get<0>(temp)+u.second;
                pQ.push({dist[u.first],u.first});
            }
        }
    }
    for(int i = 0;i<n+1;i++){
        if(dist[i]==1e9){
            cout << "Infinite" << endl;
            continue;
        }
        cout << dist[i] << " ";
    }
    cout << endl;
    
    
}