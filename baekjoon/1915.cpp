#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1001][1001];
int dp[1001][1001];
int ans, len;
// dp[x][y] = (x,y) 를 꼭짓점으로 하는 정사각형의 최대 길이
void solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++){
            if(a[i][j] == 1) dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
        }
    }
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= M; j++) 
            len = max(dp[i][j], len);
    
    cout << len * len << '\n';
    

}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%1d", &a[i][j]);

    solve();
}