#include <bits/stdc++.h>
using namespace std;
int K;
int n;
int a[51];

void init() { for(int i = 0; i < 51; i++) a[i] = 0; }
void solve(int idx) {
    init();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << "Class " << idx << '\n';
    sort(a, a + n);
    int ret1 = a[0];
    int ret2 = a[n - 1];
    int ret3 = -1;
    for(int i = 0; i < n - 1; i++) ret3 = max(ret3, abs(a[i] - a[i + 1]));
    cout << "Max " << ret2;
    cout << ", Min " << ret1;
    cout << ", Largest gap " << ret3 << '\n';
}
int main() {
    cin >> K;
    for(int i = 1; i <= K; i++) solve(i);
}
