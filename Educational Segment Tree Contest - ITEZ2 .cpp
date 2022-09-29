//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/segtree_itez2

#include <bits/stdc++.h>

using namespace std;

int n, q;
long long st[100000 * 4];

void update(int id, int l, int r, int i, int val) {
    if (l > i || r < i) return;
    if (l == r) {
        st[id] = val;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, i, val);
    update(id * 2 + 1, m + 1, r, i, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

long long get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return st[id];
    int m = (l + r) / 2;
    long long get1 = get(id * 2, l, m, u, v);
    long long get2 = get(id * 2 + 1, m + 1, r, u, v);
    return get1 + get2;
}

int main() {
    scanf("%d %d", &n, &q);
    int x, y, z;
    while (q--) {
        scanf("%d %d %d", &x, &y, &z);
        if (x == 1) update(1, 1, n, y, z);
        else cout << get(1, 1, n, y, z) << endl;
    }
    return 0;
}