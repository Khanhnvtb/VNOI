//
// Created by khanhnvtb on 9/22/2022.
//

//https://oj.vnoi.info/problem/predhbb21_parallel2

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int i, f;
    while (n--) {
        cin >> i >> f;
        if (i + f > 3 || i == 3 || f == 3) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}