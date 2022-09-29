//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/segtree_itlazy

#include <bits/stdc++.h>

using namespace std;

int a[100005];

struct Node {
    long long val, lazy;
};

Node st[400020];

void down(int id) {
    long long k = st[id].lazy;
    st[id * 2].val += k;
    st[id * 2].lazy += k;
    st[id * 2 + 1].val += k;
    st[id * 2 + 1].lazy += k;
    st[id].lazy = 0;
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id].val = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
}

void update(int id, int l, int r, int u, int v, int k) {
    if (u > r || v < l) return;
    if (u <= l && v >= r) {
        st[id].val += k;
        st[id].lazy += k;
        return;
    }
    int m = (l + r) / 2;
    down(id);
    update(id * 2, l, m, u, v, k);
    update(id * 2 + 1, m + 1, r, u, v, k);
    st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
}

long long get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return INT_MIN;
    if (u <= l && v >= r) return st[id].val;
    int m = (l + r) / 2;
    down(id);
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main() {
    int n, q, p, u, v, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &p);
        if (p == 1) {
            scanf("%d %d %d", &u, &v, &k);
            update(1, 1, n, u, v, k);
        } else {
            scanf("%d %d", &u, &v);
            printf("%lld\n", get(1, 1, n, u, v));
        }
    }
    return 0;
}