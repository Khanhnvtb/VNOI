//
// Created by khanhnvtb on 9/27/2022.
//

//https://oj.vnoi.info/problem/bedao_m11_treecoloring

#include <bits/stdc++.h>

using namespace std;

int n, ans[100005], vs[100005];
vector<pair<int, int>> a[100005];

void dfs(int u) {
    vs[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].first;
        int w = a[u][i].second;
        if (!vs[v]) {
            if (w % 2 == 0) ans[v] = ans[u];
            else {
                if (ans[u] == 0) ans[v] = 1;
                else ans[v] = 0;
            }
            dfs(v);
        }
    }
}

int main() {
    cin >> n;
    int u, v, w;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}