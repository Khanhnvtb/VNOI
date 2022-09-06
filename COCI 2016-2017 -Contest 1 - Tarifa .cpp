//
// Created by khanhnvtb on 9/6/2022.
//

//https://oj.vnoi.info/problem/coci1617_r1_tarifa

#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, n, val;
    cin >> x >> n;
    int ans = x * (n + 1);
    for (int i = 0; i < n; i++) {
        cin >> val;
        ans -= val;
    }
    cout << ans << endl;
    return 0;
}