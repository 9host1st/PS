#include <bits/stdc++.h>
using namespace std;
int N, S, a[21], ans;
void f(int k, int sum) {
    if(k == N) return;
    if(sum + a[k] == S) ans++;
    f(k + 1, sum + a[k]);
    f(k + 1, sum);
}

int main() {
    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> a[i];
    f(0, 0);
    cout << ans << '\n';
}
