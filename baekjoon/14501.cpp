#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
int N, x, y;
pii a[17];
ll dp[17];
void solve() {
    for(int i = 1; i<= N; i++) {
        if(i + a[i].first <= N + 1) 
            dp[i + a[i].first] = max(dp[i + a[i].first], dp[i] + a[i].second);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    cout << *max_element(dp, dp + N + 2);
}
int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i].first >> a[i].second;
    solve();
}