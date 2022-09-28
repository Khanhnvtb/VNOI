//
// Created by khanhnvtb on 9/28/2022.
//

//https://oj.vnoi.info/problem/lis

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<int> v(n, 0);
    int ans = 1;
    v[0] = a[0];
    for (int i = 1; i < n; i++) {
        int index = lower_bound(v.begin(), v.begin() + ans, a[i]) - v.begin();
        if (index == ans) v[ans++] = a[i];
        else v[index] = a[i];
    }
    printf("%d", ans);
    return 0;
}