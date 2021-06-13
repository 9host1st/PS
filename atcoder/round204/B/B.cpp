#include <bits/stdc++.h>
using namespace std;
int N, a[1001], ans;

void solve() {
    for(int i = 1; i <= N; i++)
        if(a[i] > 10) ans += (a[i] - 10);
    cout << ans << '\n';
}
int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    solve();
}