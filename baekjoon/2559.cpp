#include <bits/stdc++.h>
using namespace std;
int N, K, a[100001], sum[100001], ans = -987654321;
int main() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for(int i = 1; i <= N - K + 1; i++) 
        ans = max(ans, sum[i + K - 1] - sum[i - 1]);
    cout << ans;
}