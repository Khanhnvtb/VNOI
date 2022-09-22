//
// Created by khanhnvtb on 9/22/2022.
//

//https://oj.vnoi.info/problem/atcoder_dp_g

#include <bits/stdc++.h>

using namespace std;

int n, m, vs[100005], dp[100005];
vector<int> a[100005];

void dfs(int u) {
    vs[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int tmp = a[u][i];
        if (!vs[tmp]) dfs(tmp);
        dp[u] = max(dp[u], 1 + dp[tmp]);
    }
}

int main() {
    cin >> n >> m;
    int i, j;
    while (m--) {
        cin >> i >> j;
        a[i].push_back(j);
    }
    for (i = 1; i <= n; i++) {
        vs[i] = 0;
        dp[i] = 0;
    }
    for (i = 1; i <= n; i++)
        if (!vs[i]) dfs(i);
    int ans = 0;
    for (i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}