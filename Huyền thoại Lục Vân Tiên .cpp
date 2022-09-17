//
// Created by khanhnvtb on 9/17/2022.
//

//https://oj.vnoi.info/problem/mink

//Giải pháp 1: Cửa sổ trượt

#include <bits/stdc++.h>

using namespace std;

int n, k, a[17005];
deque<int> dq;

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void solve() {
    dq.clear();
    for (int i = 1; i < k; i++) {
        while (!dq.empty() && a[i] <= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    for (int i = k; i <= n; i++) {
        while (!dq.empty() && a[i] <= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        while (dq.front() <= i - k) dq.pop_front();
        cout << a[dq.front()] << " ";
    }
    cout << endl;
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

//Giải pháp 2: Cây phân đoạn

#include <bits/stdc++.h>

using namespace std;

int n, k, a[17005];
int st[170000 * 4];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return INT_MAX;
    if (l >= u && r <= v) return st[id];
    int m = (l + r) / 2;
    int get1 = get(id * 2, l, m, u, v);
    int get2 = get(id * 2 + 1, m + 1, r, u, v);
    return min(get1, get2);
}

void solve() {
    build(1, 1, n);
    for (int i = 1; i <= n - k + 1; i++)
        cout << get(1, 1, n, i, i + k - 1) << " ";
    cout << endl;
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