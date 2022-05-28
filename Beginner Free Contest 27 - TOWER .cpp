//
// Created by khanhnvtb on 5/28/2022.
//

//https://oj.vnoi.info/problem/fcb027_tower

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long x = sqrt(n * 2);
        if (x * (x + 1) == n * 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

