#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;
    int e1,e2,w;
    // <from,to,weight>
    long long int dist[n+1];
    for(int i = 0;i<n+1;i++){
        if(i==0){dist[i]=0;}
        else{
            dist[i]=1e9;
        }
    }
    int parent[n+1];
    for(int i = 0;i<n+1;i++){
        parent[i] = i;
    }
    vector<tuple<int,int,int>> edgeList;
    cout << "Enter edges: " << endl;
    for(int i =0;i<e;i++){
        cin >> e1 >> e2 >> w;
        edgeList.push_back({e1,e2,w});
        edgeList.push_back({e2,e1,w});
    }
    for(int i = 0;i<n+1;i++){
        for(auto u: edgeList){
            if(dist[get<0>(u)]+get<2>(u) < dist[get<1>(u)]){
                dist[get<1>(u)] = dist[get<0>(u)]+get<2>(u);
                parent[get<1>(u)] = get<0>(u);
            }
        }
    }
    for(int i = 0;i<n+1;i++){
        if(dist[i]==1e9){
            cout << "Infinite";
            continue;
        }
        cout << dist[i] << ": ";
        int j = i;
        while(j!=0){
            cout << j << " -> ";
            j = parent[j];
        }
        cout << endl;
    }
    cout << endl;
}