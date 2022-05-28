//
// Created by khanhnvtb on 5/28/2022.
//

//https://oj.vnoi.info/problem/pnumber

#include <bits/stdc++.h>

using namespace std;

vector<long> P;

void createPrimeNumbers(long b) {
    long prime[b + 1];
    for (long i = 0; i <= b; i++) prime[i] = 1;
    for (long i = 2; i <= b; i++) {
        if (prime[i] == 1) {
            P.push_back(i);
            for (long j = i * i; j <= b; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int main() {
    long a, b;
    cin >> a >> b;
    createPrimeNumbers(b);
    for (long i = 0; i < P.size(); i++)
        if (P[i] >= a) cout << P[i] << endl;
    return 0;
}
