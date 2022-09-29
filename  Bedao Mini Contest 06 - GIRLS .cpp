//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/bedao_m06_girls

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    int check = -2;
    int a[m];
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    sort(a, a + m);
    for (int i = m - n; i >= 0; i--) {
        if (a[i] + k >= a[i + n - 1]) {
            check = i;
            break;
        }
    }
    if (check == -2) printf("-2");
    else {
        long long ans = 0;
        for (int i = check; i < check + n; i++)
            ans += a[i];
        printf("%lld", ans);
    }
    return 0;
}