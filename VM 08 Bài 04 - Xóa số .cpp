//
// Created by khanhnvtb on 10/4/2022.
//

//https://oj.vnoi.info/problem/kdel

#include <bits/stdc++.h>

using namespace std;

vector<int> Prime(50001);

void sievePrime() {
    int cnt = 1;
    bitset<611954> prime;
    for (int i = 2; i * i < 611953; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j < 611953; j += i)
                prime[j] = 1;
        }
    }
    for (int i = 2; i <= 611953; i++) {
        if (prime[i] == 0) Prime[cnt++] = i;
        if (cnt == 50001) break;
    }
}

int main() {
    sievePrime();
    int n, k;
    scanf("%d %d", &n, &k);
    string ans = "";
    for (int i = 1; i <= n; i++)
        ans += to_string(Prime[i]);
    deque<char> dq;
    int i = 0;
    n = ans.length();
    while (i < n) {
        while (k > 0 && !dq.empty() && ans[i] > dq.back()) {
            dq.pop_back();
            k--;
        }
        dq.push_back(ans[i++]);
    }
    while (k--) dq.pop_back();
    while (!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
    return 0;
}