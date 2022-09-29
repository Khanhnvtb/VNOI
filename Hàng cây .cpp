//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/firs

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val, pos;
};

int n, ans, a[100005];
Node st[400020];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].val = a[l];
        st[id].pos = l;
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    if (st[id * 2].val <= st[id * 2 + 1].val) st[id] = st[id * 2];
    else st[id] = st[id * 2 + 1];
}

void update(int id, int l, int r, int pos) {
    if (pos > r || pos < l) return;
    if (l == r) {
        st[id].val = INT_MAX;
        return;
    }
    int m = (l + r) / 2;
    update(id * 2, l, m, pos);
    update(id * 2 + 1, m + 1, r, pos);
    if (st[id * 2].val <= st[id * 2 + 1].val) st[id] = st[id * 2];
    else st[id] = st[id * 2 + 1];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    ans = 0;
    while (st[1].val != INT_MAX) {
        int pos = st[1].pos;
        update(1, 1, n, pos - 1);
        update(1, 1, n, pos);
        update(1, 1, n, pos + 1);
        ans++;
    }
    printf("%d", ans);
    return 0;
}