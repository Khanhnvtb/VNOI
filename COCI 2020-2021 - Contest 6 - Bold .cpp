//
// Created by khanhnvtb on 9/21/2022.
//

//https://oj.vnoi.info/problem/coci2021_r6_bold

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char c[n][m];
    char ans[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            ans[i][j] = '.';
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '#') {
                ans[i][j] = '#';
                ans[i + 1][j] = '#';
                ans[i][j + 1] = '#';
                ans[i + 1][j + 1] = '#';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}