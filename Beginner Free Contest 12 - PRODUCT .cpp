//
// Created by khanhnvtb on 9/21/2022.
//

//https://oj.vnoi.info/problem/fcb012_product

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long a, b;
    cin >> a >> b;
    if (a == 0 || b == 0) cout << 0;
    else {
        if (a > 0 && b > 0) cout << 1;
        else if (a < 0 && b < 0) cout << 1;
        else cout << -1;
    }
    return 0;
}