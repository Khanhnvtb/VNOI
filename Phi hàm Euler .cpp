//
// Created by khanhnvtb on 9/21/2022.
//

//https://oj.vnoi.info/problem/etf

#include <bits/stdc++.h>

using namespace std;

int n, prime[1000005];
vector<int> v;

void createPrimeNumber() {
    memset(prime, 0, sizeof prime);
    for (int i = 2; i * i <= 1000000; i++)
        if (prime[i] == 0) {
            for (int j = 2 * i; j <= 1000000; j += i)
                prime[j] = 1;
        }
    for (int i = 2; i <= 1000000; i++) if (prime[i] == 0) v.push_back(i);
}

void solve() {
    int ans = n, i = 0;
    while (n > 1) {
        if (n % v[i] == 0) {
            ans = ans / v[i] * (v[i] - 1);
            while (n % v[i] == 0) n /= v[i];
        }
        i++;
    }
    printf("%d\n", ans);
}

int main() {
    createPrimeNumber();
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        solve();
    }
    return 0;
}
