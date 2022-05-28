//
// Created by khanhnvtb on 5/28/2022.
//

//https://oj.vnoi.info/problem/fcb035_exp

#include <bits/stdc++.h>

using namespace std;

long res, a[3];

int main() {
    int t;
    cin >> t;
    while (t--) {
        res = LONG_MAX;
        cin >> a[0] >> a[1] >> a[2];
        res = min(res, abs(a[0] + a[1] + a[2]));
        res = min(res, abs(a[0] + a[1] - a[2]));
        res = min(res, abs(a[0] + a[1] * a[2]));
        res = min(res, abs(a[0] - a[1] + a[2]));
        res = min(res, abs(a[0] - a[1] - a[2]));
        res = min(res, abs(a[0] - a[1] * a[2]));
        res = min(res, abs(a[0] * a[1] + a[2]));
        res = min(res, abs(a[0] * a[1] - a[2]));
        res = min(res, abs(a[0] * a[1] * a[2]));
        cout << res << endl;
    }
    return 0;
}
