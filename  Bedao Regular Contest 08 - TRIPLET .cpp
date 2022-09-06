//
// Created by khanhnvtb on 9/6/2022.
//

//https://oj.vnoi.info/problem/bedao_r08_triplet

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long ans = n / k;
    ans = ans * ans * ans;
    if (k % 2 == 0) {
        long long tmp = (n + k / 2) / k;
        ans += tmp * tmp * tmp;
    }
    cout << ans;
    return 0;
}
