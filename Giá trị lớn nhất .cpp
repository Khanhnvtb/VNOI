//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/qmax

#include <bits/stdc++.h>

using namespace std;

int n;

struct Node {
    int lazy, val;
};

Node st[50000 * 4];

void down(int id) {
    int k = st[id].lazy;
    st[id * 2].val += k;
    st[id * 2].lazy += k;
    st[id * 2 + 1].val += k;
    st[id * 2 + 1].lazy += k;
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int k) {
    if (v < l || u > r) return;
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

int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return INT_MIN;
    if (l >= u && r <= v) return st[id].val;
    int m = (l + r) / 2;
    down(id);
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main() {
    int n, m, p, u, v, k;
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &u, &v, &k);
        update(1, 1, n, u, v, k);
    }
    scanf("%d", &p);
    while (p--) {
        scanf("%d %d", &u, &v);
        printf("%d\n", get(1, 1, n, u, v));
    }
    return 0;
}