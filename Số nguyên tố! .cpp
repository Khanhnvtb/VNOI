//
// Created by khanhnvtb on 9/21/2022.
//

//https://oj.vnoi.info/problem/c11pnum

#include<bits/stdc++.h>

using namespace std;

unsigned long long ans;

vector<int> v;

void createPrimeNumber() {
    vector<int> prime(10000000, 0);
    for (int i = 2; i * i <= 10000000; i++)
        if (prime[i] == 0) {
            for (int j = 2 * i; j <= 10000000; j += i)
                prime[j] = 1;
        }
    for (int i = 2; i < 10000000; i++)
        if (prime[i] == 0) v.push_back(i);
}

void solve(unsigned long long n, int k) {
    ans = 1;
    int size = v.size();
    for (int i = 0; i <= size - k; i++) {
        long long tmp = v[i];
        for (int j = i + 1; j < i + k; j++) {
            if (n / tmp >= v[j]) tmp *= v[j];
            else return;
        }
        ans = tmp;
    }
}

int main() {
    createPrimeNumber();
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        int k;
        cin >> k;
        solve(n, k);
        if (ans == 1) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
