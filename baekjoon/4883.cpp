#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int INF = 987654321;
int N, x, y, d, ans;
int a[100002][4], dp[100002][4];
void solve(int k) {
    fill(&dp[0][0], &dp[100001][4], INF);
    dp[1][1] = INF; 
    dp[1][2] = a[1][2];
    dp[1][3] = a[1][3] + dp[1][2];
    for(int i = 2; i <= x; i++) {
        for(int j = 1; j <= 3; j++) {
            if(j == 1) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + a[i][j];
            else if(j == 3) dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + a[i][j];
            else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1], dp[i][j - 1]}) + a[i][j];
        }
    } 
    ans = dp[x][2];
    cout << k << ". " << ans << '\n';
}
int main() {
    for(int i = 1; ; i++) {
        memset(a, 0, sizeof(a));
        cin >> x;
        if(x == 0) return 0;
        for(int i = 1; i <= x; i++) 
            for(int j = 1; j <= 3; j++) 
                cin >> a[i][j];
        solve(i);
    }
}