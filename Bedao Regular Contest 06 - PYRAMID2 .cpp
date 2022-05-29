//
// Created by khanhnvtb on 5/29/2022.
//

//https://oj.vnoi.info/problem/bedao_r06_pyramid2

#include <iostream>

using namespace std;

long long n, m, MOD = 1e9 + 7;

void input() {
    cin >> n >> m;
}

void solve() {
    cout << (1 + n * (m * m % MOD - 1) % MOD) % MOD << endl;
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