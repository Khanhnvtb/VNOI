//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/bedao_m11_league

#include <bits/stdc++.h>

using namespace std;

struct data {
    int r, pts, gd, g;
};

data a[20];

bool cmp(data x, data y) {
    if (x.pts > y.pts) return true;
    if (x.pts == y.pts && x.gd > y.gd) return true;
    if (x.pts == y.pts && x.gd == y.gd && x.g > y.g) return true;
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].r);
        m[a[i].r] = i;
    }
    int x, y, z, t;
    for (int i = 0; i < n * (n - 1); i++) {
        scanf("%d %d %d %d", &x, &y, &z, &t);
        if (z > t) a[m[x]].pts += 3;
        else if (z == t) {
            a[m[x]].pts += 1;
            a[m[y]].pts += 1;
        } else a[m[y]].pts += 3;
        a[m[x]].gd += z - t;
        a[m[y]].gd += t - z;
        a[m[x]].g += z;
        a[m[y]].g += t;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        if (a[i].pts == a[0].pts && a[i].gd == a[0].gd && a[i].g == a[0].g) printf("%d ", a[i].r);
        else break;
    return 0;
}