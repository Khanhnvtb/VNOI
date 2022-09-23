//
// Created by khanhnvtb on 9/21/2022.
//

//https://oj.vnoi.info/problem/bedao_t1_frac

#include<bits/stdc++.h>

using namespace std;

struct data {
    int x, y;
};

vector<int> v;

void createPrimeNumber() {
    vector<int> prime(15000005, 0);
    for (int i = 2; i * i <= 15000000; i++)
        if (prime[i] == 0) {
            for (int j = 2 * i; j <= 15000000; j += i)
                prime[j] = 1;
        }
    for (int i = 2; i <= 15000000; i++)
        if (prime[i] == 0) v.push_back(i);
}

unsigned long long power(unsigned long long x, int y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    unsigned long long tmp = power(x, y / 2);
    if (y % 2 == 1) return tmp * tmp * x;
    return tmp * tmp;
}

int main() {
    createPrimeNumber();
    int n;
    cin >> n;
    int a[n], tmp = 0;
    bool check = true;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            check = false;
            break;
        }
        if (a[i] < 0) tmp++;
    }
    if (tmp == n) check = false;
    if (check) {
        unordered_map<int, data> m;
        for (int i = 0; i < n; i++) {
            int cnt, j = 0;
            while (a[i] > 1) {
                cnt = 0;
                if (a[i] % v[j] == 0) {
                    while (a[i] % v[j] == 0) {
                        cnt++;
                        a[i] /= v[j];
                    }
                    m[v[j]].x += cnt;
                    if (m[v[j]].y < cnt) m[v[j]].y = cnt;
                }
                j++;
            }
        }
        unsigned long long ans = 1;
        for (auto i: m) {
            ans *= power((unsigned long long) i.first, i.second.x - i.second.y);
        }
        cout << ans;
    } else cout << "impossible";
    return 0;
}
