#include <bits/stdc++.h>
using namespace std;
int N, a[100001], x, M ;
void solve() {
    cin >> M;
    while(M--) {
        bool ok = false;
        cin >> x;
        int l = 0 ;
        int r = N - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(a[m] == x) {
                ok = true;
                break;
            }
            else if(a[m] > x) r = m - 1;
            else l = m + 1;
        }
        if(ok) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);
    solve();
}