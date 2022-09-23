//
// Created by khanhnvtb on 9/23/2022.
//

//https://oj.vnoi.info/problem/bedao_m12_modsort

#include <bits/stdc++.h>

using namespace std;

int n, k;

string solve(int a[]) {
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        if (a[i] >= m[a[i] % k]) m[a[i] % k] = a[i];
        else return "No";
    }
    return "Yes";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a) << endl;
    }
    return 0;
}