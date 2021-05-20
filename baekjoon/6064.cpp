#include <bits/stdc++.h>
using namespace std;
int t, M, N, x, y;
int solve() {
    cin >> M >> N >> x >> y;
    if(x == M) x = 0;
    if(y == N) y = 0;
    for(int i = x; i <= M * N; i+=M)
        if((i % N == y))
            return i;

    return -1;

}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) cout << solve() << '\n';
}
