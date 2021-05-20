#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
// dp[x] = x일 일때 받을 수 있는 최대 수익
ll dp[1500002];
int N;
pii a[1500002];
void solve() {
    for(int i = 1; i <= N; i++) {
        if(i + a[i].first <= N + 1)
            dp[i + a[i].first] = max(dp[i] + a[i].second, dp[i + a[i].first]);
        dp[i + 1] = max(dp[i], dp[i + 1]);        
    }
    cout << *max_element(dp, dp + N + 2);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i].first >> a[i].second;
    solve();
}