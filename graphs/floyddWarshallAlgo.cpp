#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;
    vector<vector<int>> adjMatrix(n+1,vector<int>(n+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==j){
                adjMatrix[i][j]=0;
            }
            else{
                adjMatrix[i][j]=1e9;
            }
        }
    }
    int e1,e2,w;
    cout << "Enter edges: " << endl;
    for(int i =0;i<e;i++){
        cin >> e1 >> e2 >> w;
        adjMatrix[e1][e2]=w;
        // adjMatrix[e2][e1]=w;  uncomment for undirected graph
    }
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<n+1;j++){
            for(int k = 0;k<n+1;k++){
                adjMatrix[j][k] = min(adjMatrix[j][k],adjMatrix[j][i] + adjMatrix[i][k]); 
            }
        }
    }
    for(int i = 0;i<n+1;i++){
        for(int j = 0; j<n+1;j++){
            if(adjMatrix[i][j]>=1e9){
                cout << "inf ";
                continue;
            }
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}