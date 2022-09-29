//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/qbhv

#include <bits/stdc++.h>

using namespace std;

string s;
int n, vs[10];
set<string> ans;

void Try(int i, string str) {
    if (i == n) ans.insert(str);
    for (int j = 0; j < n; j++)
        if (!vs[j]) {
            vs[j] = 1;
            Try(i + 1, str + s[j]);
            vs[j] = 0;
        }
}

int main() {
    cin >> s;
    n = s.length();
    Try(0, "");
    cout << ans.size() << endl;
    for (string str: ans) cout << str << endl;
    return 0;
}