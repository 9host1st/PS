#include <bits/stdc++.h>
using namespace std;
int N, a[41], dp[41], M;
int ans =1;
void solve() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= 40; i++) dp[i] = (dp[i - 1] + dp[i - 2]);
}

int main() {
    cin >> N >> M;
    int now = 0;
    solve();
    for(int i = 1; i <= M; i++) {
        int tmp;
        cin >> tmp;
        ans *= dp[tmp - now - 1];
        now = tmp;    
    }
    cout << ans* dp[N - now];
}