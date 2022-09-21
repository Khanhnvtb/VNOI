//
// Created by khanhnvtb on 9/21/2022.
//

//https://oj.vnoi.info/problem/car

#include <bits/stdc++.h>

using namespace std;

struct data {
    int a, b, index;
    float f;
};

bool cmp(data x, data y) {
    return x.f > y.f;
}

int main() {
    int n;
    cin >> n;
    data arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a;
        arr[i].index = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].b;
        arr[i].f = (float) arr[i].a / arr[i].b;
    }
    sort(arr, arr + n, cmp);
    long long ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += arr[i].b;
        ans += cnt * arr[i].a;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) cout << arr[i].index << " ";
    return 0;
}
