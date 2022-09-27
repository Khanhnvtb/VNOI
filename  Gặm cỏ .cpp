//
// Created by khanhnvtb on 9/27/2022.
//

//https://oj.vnoi.info/problem/vmunch

#include <bits/stdc++.h>

using namespace std;

int n, m, dp[1005][1005];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char c[1005][1005];

bool check(int x, int y) {
    if (x == 0 || y == 0 || x > n || y > m) return false;
    return true;
}

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (check(x, y) && c[x][y] != '*' && dp[x][y] == 0) {
                q.push({x, y});
                dp[x][y] = dp[i][j] + 1;
            }
            if (dp[1][1]) return dp[1][1];
        }
    }
}

int main() {
    cin >> n >> m;
    int si, sj;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'C') {
                si = i;
                sj = j;
            }
        }
    cout << bfs(si, sj);
    return 0;
}