//
// Created by khanhnvtb on 9/6/2022.
//

//https://oj.vnoi.info/problem/coci1920_r1_trol

#include <bits/stdc++.h>

using namespace std;

long long l, r;

void input() {
    cin >> l >> r;
}

void solve() {
    long long ans = (r - l + 1) / 9 * 45;
    long long val = (r - l + 1) % 9;
    long long tmp;
    while (l > 9) {
        tmp = 0;
        while (l > 0) {
            tmp += l % 10;
            l /= 10;
        }
        l = tmp;
    }
    while (val--) {
        ans += l;
        l++;
        if (l == 10) l = 1;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}