//
// Created by khanhnvtb on 9/20/2022.
//

//https://oj.vnoi.info/problem/heap1

#include <bits/stdc++.h>

using namespace std;


int n, a[20000];
priority_queue<long long, vector<long long>, greater<long long> > pq;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
    }
}

void solve() {
    long long ans = 0;
    while (pq.size() > 1) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        long long z = x + y;
        pq.push(z);
        ans += z;
    }
    cout << ans << endl;
    pq.pop();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}