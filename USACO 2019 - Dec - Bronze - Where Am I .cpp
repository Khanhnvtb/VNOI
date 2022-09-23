//
// Created by khanhnvtb on 9/23/2022.
//

//https://oj.vnoi.info/problem/usaco19db_whereami

#include<bits/stdc++.h>

using namespace std;

int n;

int solve(string s) {
    bool check;
    for (int i = 1; i < n; i++) {
        unordered_map<string, int> m;
        check = true;
        for (int j = 0; j <= n - i; j++) {
            string str = s.substr(j, i);
            m[str]++;
            if (m[str] > 1) {
                check = false;
                break;
            }
        }
        if (check) return i;
    }
    return n;
}

int main() {
    cin >> n;
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
