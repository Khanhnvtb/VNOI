//
// Created by khanhnvtb on 9/17/2022.
//

//https://oj.vnoi.info/problem/segtree_itez1

#include <bits/stdc++.h>

using namespace std;

int n, q, a[100005], st[100000 * 4];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int i, int val) {
    if (l > i || r < i) return;
    if (l == r) {
        st[id] = val;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, i, val);
    update(id * 2 + 1, m + 1, r, i, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return INT_MIN;
    if (l >= u && r <= v) return st[id];
    int m = (l + r) / 2;
    int get1 = get(id * 2, l, m, u, v);
    int get2 = get(id * 2 + 1, m + 1, r, u, v);
    return max(get1, get2);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    int x, y, z;
    while (q--) {
        cin >> x >> y >> z;
        if (x == 1) update(1, 1, n, y, z);
        else cout << get(1, 1, n, y, z) << endl;
    }
    return 0;
}