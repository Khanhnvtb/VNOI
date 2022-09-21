//
// Created by khanhnvtb on 9/21/2022.
//

//https://oj.vnoi.info/problem/cprime

#include <bits/stdc++.h>

using namespace std;

bitset<100000100> prime;
int a[6000000], size = 0;

void createPrimeNumber() {
    for (int i = 2; i * i <= 100000000; i++)
        if (!prime[i]) {
            for (int j = 2 * i; j <= 100000000; j += i)
                prime[j] = 1;
        }
    for (int i = 2; i <= 100000000; i++)
        if (!prime[i]) a[size++] = i;
}

int main() {
    createPrimeNumber();
    int x;
    while (scanf("%d", &x), x) {
        int piX = upper_bound(a, a + size, x) - a;
        double ans = abs((double) piX - (double) x / log((double) x)) / piX * 100;
        printf("%.1f\n", ans);
    }
    return 0;
}
