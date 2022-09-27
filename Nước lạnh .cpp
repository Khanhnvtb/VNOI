//
// Created by khanhnvtb on 9/27/2022.
//

//https://oj.vnoi.info/problem/vcoldwat

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val, left, right;
};

Node a[100000];

void dfs(int u) {
    if (a[u].left) {
        a[a[u].left].val = a[u].val + 1;
        dfs(a[u].left);
    }
    if (a[u].right) {
        a[a[u].right].val = a[u].val + 1;
        dfs(a[u].right);
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        a[i].left = 0;
        a[i].right = 0;
    }
    int e, b1, b2;
    while (c--) {
        cin >> e >> b1 >> b2;
        a[e].left = b1;
        a[e].right = b2;
    }
    a[1].val = 1;
    dfs(1);
    for (int i = 1; i <= n; i++) cout << a[i].val << endl;
    return 0;
}