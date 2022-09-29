//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/coci1920_r3_preokret

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    int vs[3] = {0}, cnt2 = 1, cnt3 = 2, cnt = 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vs[a[0]]++;
    int prev = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) cnt++;
        else {
            if (prev < vs[a[i]] && vs[a[i - 1]] > vs[a[i]]) cnt3 = max(cnt3, cnt);
            prev = vs[a[i]];
            cnt = 1;
        }
        vs[a[i]]++;
        if (vs[1] == vs[2]) cnt2++;
    }
    if (a[n - 1] == 1) {
        if (prev < vs[2] && vs[1] > vs[2]) cnt3 = max(cnt3, cnt);
    } else {
        if (prev < vs[1] && vs[2] > vs[1]) cnt3 = max(cnt3, cnt);
    }
    printf("%d %d\n%d\n%d", vs[1], vs[2], cnt2, cnt3);
    return 0;
}