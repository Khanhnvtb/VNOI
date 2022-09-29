//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/coci2021_r1_patkice

#include <bits/stdc++.h>

using namespace std;

string ans = ":(";
char c[105][105];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};

int dfs(int i, int j, int cnt) {
    if (c[i][j] == 'x') return cnt;
    if (c[i][j] == '.') return INT_MAX;
    if (c[i][j] == '>') return dfs(i, j + 1, cnt + 1);
    if (c[i][j] == '<') return dfs(i, j - 1, cnt + 1);
    if (c[i][j] == '^') return dfs(i - 1, j, cnt + 1);
    if (c[i][j] == 'v') return dfs(i + 1, j, cnt + 1);
    return INT_MAX;
}

int main() {
    string start[4] = {"E", "N", "S", "W"};
    int n, m;
    scanf("%d %d", &n, &m);
    int si, sj;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            if (c[i][j] == 'o') {
                si = i;
                sj = j;
            }
        }
    int len = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int x = si + dx[i];
        int y = sj + dy[i];
        int cnt = dfs(x, y, 1);
        if (cnt < len) {
            ans = start[i];
            len = cnt;
        }
    }
    if (ans != ":(") cout << ":)\n" << ans;
    else cout << ans;
    return 0;
}