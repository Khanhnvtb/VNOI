//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/bedao_r08_books

#include <bits/stdc++.h>

using namespace std;

int vs[100005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    stack<int> s;
    int tmp;
    while (m--) {
        scanf("%d", &tmp);
        s.push(tmp);
    }
    while (!s.empty()) {
        tmp = s.top();
        s.pop();
        if (!vs[tmp]) {
            printf("%d\n", tmp);
            vs[tmp] = 1;
        }
    }
    for (int i = 1; i <= n; i++) if (!vs[i]) printf("%d\n", i);
    return 0;
}