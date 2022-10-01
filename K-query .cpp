//
// Created by khanhnvtb on 10/1/2022.
//

//https://oj.vnoi.info/problem/kquery

#include <bits/stdc++.h>

using namespace std;

int n, a[30005];
vector<int> st[30005 * 4];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].push_back(a[l]);
        return;
    }
    st[id] = vector<int>(r - l + 1);
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(), st[id].begin());
}

int get(int id, int l, int r, int u, int v, int k) {
    if (u > r || v < l) return 0;
    if (u <= l && v >= r) return st[id].size() - (upper_bound(st[id].begin(), st[id].end(), k) - st[id].begin());
    int m = (l + r) / 2;
    return get(id * 2, l, m, u, v, k) + get(id * 2 + 1, m + 1, r, u, v, k);
}

int main() {
    int q, u, v, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d", &u, &v, &k);
        printf("%d\n", get(1, 1, n, u, v, k));
    }
    return 0;
}
