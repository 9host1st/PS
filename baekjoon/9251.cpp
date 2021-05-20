#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[1001][1001];
void solve() { 
    int s1Len = s1.length();
    int s2Len = s2.length();
    s1 = '0' + s1;
    s2 = '0' + s2;
    for(int i = 0; i <= s1Len; i++) {
        for(int j = 0; j <= s2Len; j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(i > 0 && j > 0) {
                if(s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s1Len][s2Len];
}
int main() {
    cin >> s1 >> s2;
    solve();
}