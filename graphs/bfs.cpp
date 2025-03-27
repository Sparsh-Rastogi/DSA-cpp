#include <bits/stdc++.h>
using namespace std;
void bfs(queue<int> q,vector<int>* adj, bool* visited){
    while(q.size()!=0){
        int i = q.front();
        q.pop();
        if(visited[i]){continue;}
        cout << i << " ";
        visited[i]=1;
        for(auto u: adj[i]){
            q.push(u);
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
    for(int i =0;i<e;i++){
        cin >> e1 >> e2;
        adjList[e1].push_back(e2);
        adjList[e2].push_back(e1);
    }
    queue<int> q;
    q.push(1);
    bfs(q,adjList,visited);
    cout << endl;

}