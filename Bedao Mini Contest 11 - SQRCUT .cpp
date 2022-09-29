//
// Created by khanhnvtb on 9/29/2022.
//

//https://oj.vnoi.info/problem/bedao_m11_sqrcut

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = 0;
        while (a != b) {
            int tmp = a - b;
            a = max(tmp, b);
            b = min(tmp, b);
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}