//
// Created by khanhnvtb on 5/28/2022.
//

//https://oj.vnoi.info/problem/bedao_r06_icd

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int candy = 0;
    n--;
    for (int i = 0; i < n; i++) {
        a[i] += candy;
        int people = n - i;
        candy += a[i] / people;
        cout << a[i] % people << " ";
    }
    cout << a[n] + candy;
    return 0;
}

