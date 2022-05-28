//
// Created by khanhnvtb on 5/28/2022.
//

//https://oj.vnoi.info/problem/fcb027_divcandy

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, m;
    cin >> n >> m;
    if (n % m == 0) cout << "Yes";
    else cout << "No";
    return 0;
}
