//
// Created by khanhnvtb on 5/28/2022.
//

//https://oj.vnoi.info/problem/wordcnt

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);
        int res = INT_MIN;
        int prev = 0, cnt = 0, len = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                if (len > 0) {
                    if (prev == 0) prev = len;
                    if (len == prev) {
                        cnt++;
                    } else {
                        res = max(res, cnt);
                        prev = len;
                        cnt = 1;
                    }
                    len = 0;
                }
            } else len++;
        }
        if (len == prev) cnt++;
        res = max(res, cnt);
        cout << res << endl;
    }
    return 0;
}

