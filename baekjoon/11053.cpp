#include <bits/stdc++.h>
using namespace std;
int N, a[1001], dp[1001], ans, len;
// dp[i] = i번째 항을 마지막으로 사용하는 수열 중 최대 길이
void solve() {
    for(int i = 1; i <= N; i++) {
        dp[i] = 1;
        for(int j = 1; j < i; j++) 
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    solve();
}