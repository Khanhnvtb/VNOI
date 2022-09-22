//
// Created by khanhnvtb on 9/22/2022.
//

//https://oj.vnoi.info/problem/cf_edu1d

#include <bits/stdc++.h>

using namespace std;

char a[1005][1005];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int vs[1005][1005];
int n, m, cnt;
unordered_map<int, int> ans;

void dfs(int i, int j, int k) {
    vs[i][j] = k;
    int x, y;
    for (int z = 0; z < 4; z++) {
        x = i + dx[z];
        y = j + dy[z];
        if (a[x][y] == '*') cnt++;
        else {
            if (vs[x][y] == 0) dfs(x, y, k);
        }
    }
}

int main() {
    int i, j, k;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            cin >> a[i][j];
            vs[i][j] = 0;
        }
    int tmp = 0;
    while (k--) {
        cnt = 0;
        cin >> i >> j;
        if (vs[i][j] == 0 && a[i][j] == '.') {
            tmp++;
            dfs(i, j, tmp);
            ans[tmp] = cnt;
        }
        cout << ans[vs[i][j]] << endl;
    }
    return 0;
}
