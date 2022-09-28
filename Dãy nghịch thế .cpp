//
// Created by khanhnvtb on 9/28/2022.
//

//https://oj.vnoi.info/problem/nkinv

#include <bits/stdc++.h>

using namespace std;

int n, ans = 0, a[60005];

void merge(int l, int r) {
    int m = (l + r) / 2;
    int tmp[r - l + 1];
    int i = l, j = m + 1, index = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp[index++] = a[i++];
        else {
            ans += m - i + 1;
            tmp[index++] = a[j++];
        }
    }
    while (i <= m) tmp[index++] = a[i++];
    while (j <= r) tmp[index++] = a[j++];
    for (int val: tmp) a[l++] = val;
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, r);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    mergeSort(0, n - 1);
    printf("%d", ans);
    return 0;
}