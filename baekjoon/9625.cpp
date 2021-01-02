#include <bits/stdc++.h>
using namespace std;
int a[46], b[46];
int k;

int main() {
    cin >> k;
    a[1] = 0;
    b[1] = 1;

    a[2] = 1;
    b[2] = 1;
    for(int i = 3; i <= k; i++) {
        a[i] = b[i - 1];
        b[i] = a[i - 1] + b[i - 1];
    }
    cout << a[k] << ' ' << b[k] << '\n';
}
