//
// Created by khanhnvtb on 9/17/2022.
//

//https://oj.vnoi.info/problem/nklineup

#include <bits/stdc++.h>

using namespace std;

struct data {
    int minHigh, maxHigh;
};

int n, q, a[50005];
data st[4 * 50000];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = {a[l], a[r]};
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = {min(st[id * 2].minHigh, st[id * 2 + 1].minHigh), max(st[id * 2].maxHigh, st[id * 2 + 1].maxHigh)};
}

int getMax(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return INT_MIN;
    if (l >= u && r <= v) return st[id].maxHigh;
    int m = (l + r) / 2;
    int get1 = getMax(id * 2, l, m, u, v);
    int get2 = getMax(id * 2 + 1, m + 1, r, u, v);
    return max(get1, get2);
}

int getMin(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return INT_MAX;
    if (l >= u && r <= v) return st[id].minHigh;
    int m = (l + r) / 2;
    int get1 = getMin(id * 2, l, m, u, v);
    int get2 = getMin(id * 2 + 1, m + 1, r, u, v);
    return min(get1, get2);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    int u, v;
    while (q--) {
        cin >> u >> v;
        cout << getMax(1, 1, n, u, v) - getMin(1, 1, n, u, v) << endl;
    }
    return 0;
}