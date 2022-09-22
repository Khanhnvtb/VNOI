//
// Created by khanhnvtb on 9/22/2022.
//

//https://oj.vnoi.info/problem/qbschool

#include <bits/stdc++.h>

using namespace std;

int n, m, s, d, tmp;
//first là cạnh kề, second là trọng số
vector<pair<int, int>> a[5005];
//first là độ dài đường đi, second là số lượng đường đi
pair<long long, long long> ans[5005];
//first là độ dài đường đi, second là đỉnh
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int main() {
    cin >> n >> m;
    int k, u, v, l;
    while (m--) {
        cin >> k >> u >> v >> l;
        a[u].push_back({v, l});
        if (k == 2) a[v].push_back({u, l});
    }
    for (int i = 2; i <= n; i++) ans[i].first = LONG_LONG_MAX;
    ans[1].second = 1;
    pq.push({0, 1});
    while (!pq.empty()) {
        d = pq.top().first;
        s = pq.top().second;
        pq.pop();
        for (int i = 0; i < a[s].size(); i++) {
            tmp = a[s][i].first;
            l = a[s][i].second;
            if (d + l < ans[tmp].first) {
                ans[tmp] = {d + l, ans[s].second};
                pq.push({d + l, tmp});
            } else if (d + l == ans[tmp].first) ans[tmp].second += ans[s].second;
        }
    }
    cout << ans[n].first << " " << ans[n].second << endl;
    return 0;
}