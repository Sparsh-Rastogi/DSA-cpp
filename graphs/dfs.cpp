#include <bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>* adj, bool* visited){
    if(visited[i]){return;}
    else{
        visited[i] = true;
        cout << i << " ";
        for(auto j: adj[i]){
            dfs(j,adj,visited);
        }
    }
}
int main(){
    int n,e;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;
    vector<int> adjList[n+1];
    bool visited[n+1] = {0};
    int e1,e2;
    cout << "Enter edges: " << endl;
    for(int i =1;i<n;i++){
        cin >> e1 >> e2;
        adjList[e1].push_back(e2);
        adjList[e2].push_back(e1);
    }
    dfs(1,adjList,visited);
    cout << endl;

}