//
// Created by khanhnvtb on 8/20/2022.
//

//https://oj.vnoi.info/problem/mmaxper

#include <bits/stdc++.h>

using namespace std;

struct rec {
    int i, j;
};

int main() {
    int n;
    cin >> n;
    rec a[n];
    int dp1[n], dp2[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].i >> a[i].j;
        if (a[i].i > a[i].j) swap(a[i].i, a[i].j);
    }
    dp1[0] = a[0].i;
    dp2[0] = a[0].j;
    for (int i = 1; i < n; i++) {
        dp1[i] = a[i].i + max(abs(a[i].j - a[i - 1].i) + dp2[i - 1], abs(a[i].j - a[i - 1].j) + dp1[i - 1]);
        dp2[i] = a[i].j + max(abs(a[i].i - a[i - 1].i) + dp2[i - 1], abs(a[i].i - a[i - 1].j) + dp1[i - 1]);
    }
    cout << max(dp1[n - 1], dp2[n - 1]);
    return 0;
}