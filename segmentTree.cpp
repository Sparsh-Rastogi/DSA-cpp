#include <bits/stdc++.h>
using namespace std;


// Segment Tree

// Safe size = 4*n, Build = O(n), Query = O(log n), Update = O(log n)
// Range query has 3 overlaps: Complete (use node), Partial (go both sides), No (return identity)
// Identity: Sum→0, Min→INF, Max→ (−INF), GCD→0

class SegTree {
    int n;
    vector<long long> tree;

public:
    SegTree(int n) {
        this->n = n;
        tree.resize(4 * n); 
    }

    void build(int idx, int l, int r, vector<long long> &arr) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx, l, mid, arr);
        build(2 * idx + 1, mid + 1, r, arr);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    void update(int idx, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;     
        if (ql <= l && r <= qr) return tree[idx]; 
        int mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) +
               query(2 * idx + 1, mid + 1, r, ql, qr);
    }
};
