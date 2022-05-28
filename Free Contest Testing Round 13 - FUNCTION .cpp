//
// Created by khanhnvtb on 5/28/2022.
//

//https://oj.vnoi.info/problem/fct013_function

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long chan, le, cntchan = n / 2, cntle = n / 2;
    if (n % 2 == 0) {
        chan = n;
        le = n - 1;
    } else {
        chan = n - 1;
        le = n;
        cntle++;
    }
    cout << (chan + 2) * cntchan / 2 - (le + 1) * cntle / 2;
    return 0;
}