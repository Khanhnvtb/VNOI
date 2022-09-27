//
// Created by khanhnvtb on 9/27/2022.
//

//https://oj.vnoi.info/problem/message

#include <bits/stdc++.h>

using namespace std;

vector<int> a[805];
int mark[805], vs[805];

void dfs(int u) {
    vs[u] = 1;
    for (int tmp: a[u])
        if (!vs[tmp]) dfs(tmp);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j;
    while (m--) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
    }
    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            dfs(i);
            mark[i] = 1;
        }
    }
    int ans = 0;
    memset(vs, 0, sizeof vs);
    for (int i = n; i >= 1; i--) {
        if (mark[i] && !vs[i]) {
            ans++;
            dfs(i);
        }
    }
    printf("%d", ans);
    return 0;
}