//
// Created by khanhnvtb on 9/23/2022.
//

//https://oj.vnoi.info/problem/fc142_knight

#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

string solve() {
    for (int i = 0; i < 8; i++) {
        int x = a + dx[i];
        int y = b + dy[i];
        if (x == c && y == d) return "Yes";
    }
    return "No";
}

int main() {
    cin >> a >> b >> c >> d;
    cout << solve();
    return 0;
}