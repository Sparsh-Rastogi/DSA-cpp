#include <bits/stdc++.h>
using namespace std;

void lca_init(int v, int p,vector<int> &h, vector<vector<int>> &adj, vector<vector<int>> &up) {
    up[v][0] = p;
    for (int i = 1; i < 32; i++) {
        up[v][i] = up[ up[v][i-1] ][i-1];
    }

    for (int to : adj[v]) {
        if (to == p) continue;
        h[to] = h[v] + 1;
        lca_init(to, v,h,adj,up);
    }
}

int lca(int a, int b, vector<int> &depth, vector<vector<int>> &up) {
    if (depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = 0; i < 32; i++) {
        if (diff & (1 << i))
            a = up[a][i];
    }

    if (a == b)
        return a;

    for (int i = 31; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adjList(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> h(n+1);
    h[1] = 1;
    vector<vector<int>> up(n+1,vector<int>(32,0)); 
    lca_init(1,0,h,adjList,up);
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b,h,up) << endl;
    }

    
}