//
// Created by khanhnvtb on 5/28/2022.
//

//https://oj.vnoi.info/problem/fc107_maximum

#include <bits/stdc++.h>

using namespace std;

long find(int l, int r, long val, long a[]) {
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == val) return a[mid];
        else if (a[mid] > val) {
            if (mid > l) {
                if (a[mid - 1] == val) return a[mid - 1];
                else if (a[mid - 1] < val) return a[mid];
                else r = mid - 1;
            } else return a[mid];
        } else {
            if (mid < r && a[mid + 1] >= val) return a[mid + 1];
            else l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;
    long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
        int l, r;
        long val;
        cin >> l >> r >> val;
        cout << find(l - 1, r - 1, val, a) << endl;
    }
    return 0;
}