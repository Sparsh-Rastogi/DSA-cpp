#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MOD = 998244353;

int qpow(int a, int x = MOD - 2) {
    int res = 1;
    for (; x; x >>= 1, a = 1ll * a * a % MOD) if (x & 1) res = 1ll * res * a % MOD;
    return res;
}

vector<int> sieve(int n){
    //LPrime is the lowest prime factor of the number
    vector<int> Lprime(n+1,1);
    for(int i=2;i<=n;i++){
        if(Lprime[i]!=INT_MAX){continue;}
        Lprime[i]=i;
        for(int j=i*i;j<=n;j+=i){
            Lprime[j] = min(Lprime[j],i);
        }
    }

    return Lprime;
    
}
long long sqrRoot(long long a, int isFloor=1){
    if(a==0){return a;}
    long long l = 1;
    long long h = min(3037000499ll,a); //root of LONG_LONG_MA
    long long mid;
    // long long ctr=0;
    while(l<=h){
        // ctr++;
        mid = l + ((h-l)/2);
        //cout << l << endl;
        if(mid*mid==a){
            return mid;
        }
        else{
            if(mid*mid>a){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
    }
    return h+(isFloor&&(h*h!=a)?0:1);
}

vector<int> dijkstra(vector<vector<pair<int,int>>> &adjList){
    int n = adjList.size()-1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1,LONG_LONG_MAX);
    vector<int> par(n+1,-1);
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        // if(dist[n]!=INT_MAX){break;}
        auto pp = pq.top(); pq.pop();
        int nd = pp.second;
        int d = pp.first;
        if(dist[nd]<d){continue;}
        for(auto &u: adjList[nd]){
            if(dist[u.second]>d+u.first){
                dist[u.second] = d+u.first;
                pq.push({d+u.first,u.second});
                par[u.second] = nd;
            }
        }
    }
    return dist;
}

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

signed main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
