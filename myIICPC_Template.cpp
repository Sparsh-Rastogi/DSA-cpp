#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MOD = 998244353;

int qpow(int a, int x = MOD - 2) {
    // if MOD is prime
    //  qpow(a) = invModulo of a 
    // (a^b)%(MOD) = ( a^( b%(MOD-1) ) )%MOD
    int res = 1;
    for (; x; x >>= 1, a = 1ll * a * a % MOD) if (x & 1) res = 1ll * res * a % MOD;
    return res;
}

vector<int> factt;

int nCr(int n, int r){
    int ans = factt[n];
    ans %=MOD;
    ans *= qpow(factt[r]);
    ans %=MOD;
    ans *= qpow(factt[n-r]);
    ans %=MOD;
    return ans;
}

vector<int> spf(int n){
    //LPrime is the lowest prime factor of the number
    vector<int> Lprime(n+1,1);
    for(int i=1;i<=n;i++)Lprime[i]=i;
    for(int i=2;i<=n;i++){
        if(Lprime[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(Lprime[j]==j){
                    Lprime[j]=i;
                }
            }
        }
    }
    return Lprime;
}

void sieve(int n, vector<vector<int>> &factors){
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            factors[j].push_back(i);
        }
    }
    return;
}

struct SegTree {
    int n;
    vector<long long> tree, lazy;
    
    SegTree(int n) : n(n) {
        tree.assign(4*n+5, 0); //identity element
        lazy.assign(4*n+5, 0);
    }

    void build(int node, int l, int r, const vector<long long> &v) {
        if (l == r) {
            tree[node] = v[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node<<1, l, mid, v);
        build(node<<1|1, mid+1, r, v);
        tree[node] = tree[node<<1] + tree[node<<1|1]; //operation
    }

    inline void apply(int node, int l, int r, long long val) {
        tree[node] += (r - l + 1) * val; //operation
        if (l != r) {
            lazy[node<<1] += val; //operation
            lazy[node<<1|1] += val;
        }
    }

    void push(int node, int l, int r) {
        if (lazy[node]) {
            apply(node, l, r, lazy[node]);
            lazy[node] = 0; //identity
        }
    }

    void range_add(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        int mid = (l + r) >> 1;
        range_add(node<<1, l, mid, ql, qr, val);
        range_add(node<<1|1, mid+1, r, ql, qr, val);
        tree[node] = tree[node<<1] + tree[node<<1|1]; //operation
    }

    long long range_sum(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql) return 0; //identity
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) >> 1;
        return range_sum(node<<1, l, mid, ql, qr)
             + range_sum(node<<1|1, mid+1, r, ql, qr); //operation
    }

    void build(const vector<long long> &v) {
        build(1, 1, n, v);
    }

    void range_add(int l, int r, long long val) {
        range_add(1, 1, n, l, r, val);
    }

    long long range_sum(int l, int r) {
        return range_sum(1, 1, n, l, r);
    }
};

struct Fenwick {
    int n;
    vector<long long> bit; // 1-indexed

    Fenwick(int n) : n(n), bit(n+1, 0) {}

    // add val to index idx
    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    // sum from 1 to idx
    long long query(int idx) const {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    // sum from l to r
    long long range_query(int l, int r) const {
        return query(r) - query(l-1);
    }

    // build in O(n)
    void build(const vector<long long> &a) {
        for (int i = 1; i <= n; i++) {
            bit[i] += a[i];
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }
};

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

long long merging(vector<int> &v, int start, int mid, int end){
    vector <int> temp;
    int i = start; int j = mid+1;
    long long count_inv = 0;
    while(i<=mid && j<=end){
        if(v[i]<=v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            count_inv += mid-i+1;
            // cout << i << " " << j << " " << count_inv << endl;
            j++;
        }
    }
    while(i<=mid){
            temp.push_back(v[i]);
            i++;
    }
    while(j<=end){
        temp.push_back(v[j]);
        j++;
    }
    for(int i = start;i<=end;i++){
        v[i] = temp[i-start];
    }
    return count_inv;
}
long long recursive_merge(vector<int> &v, int start, int end){
    long long count_inv = 0;
    if(start<end){
        int mid = start + (end-start)/2;
        count_inv += recursive_merge(v,start,mid);
        count_inv+= recursive_merge(v,mid+1,end);

        count_inv += merging(v,start,mid,end);
    }
    return count_inv;
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

//Lowest Common Ancestor
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

int scc_count(int n, vector<vector<int>> &adj) {

    vector<int> vis(n, 0);
    vector<int> order;

    // Step 1: DFS for finishing order
    function<void(int)> dfs1 = [&](int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i);
    }

    // Step 2: Transpose graph
    vector<vector<int>> radj(n);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            radj[v].push_back(u);
        }
    }

    // Step 3: DFS on reversed graph in reverse finish order
    vector<int> visited(n, 0);
    int scc_count = 0;

    function<void(int)> dfs2 = [&](int u) {
        visited[u] = 1;
        for (int v : radj[u]) {
            if (!visited[v]) dfs2(v);
        }
    };

    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        if (!visited[u]) {
            scc_count++;
            dfs2(u);
        }
    }

    return scc_count;
}

//DSU
int find(int v, vector<int> &parent) {
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v], parent);
}
bool union_sets(int a, int b, vector<int> &parent, vector<int> &sz) {
    a = find(a, parent);
    b = find(b, parent);

    if (a == b) return false;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

signed main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
