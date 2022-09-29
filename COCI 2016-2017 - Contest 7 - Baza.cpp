//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/coci1617_r7_baza

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q, ans, check;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    int b[m];
    scanf("%d", &q);
    while (q--) {
        ans = 0;
        for (int i = 0; i < m; i++)scanf("%d", &b[i]);
        for (int i = 0; i < n; i++) {
            check = 1;
            for (int j = 0; j < m; j++)
                if (b[j] != -1 && a[i][j] != b[j]) {
                    check = 0;
                    break;
                }
            if (check) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}