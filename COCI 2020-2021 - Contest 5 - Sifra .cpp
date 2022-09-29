//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/coci2021_r5_sifra

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string num = "";
    unordered_map<int, int> m;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) num += s[i];
        else {
            m[atoi(num.c_str())]++;
            num = "";
        }
    }
    m[atoi(num.c_str())]++;
    cout << m.size() - 1;
    return 0;
}