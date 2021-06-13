#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[51];
int a[127];
void solve() { 
    bool is = true;
    fill(a, a + 128, 0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        a[s[i]]++;
    }
    for(int i = 'A'; i <= 'Z'; i++)
        if(a[i] >= 2) is = false;
    if(!is) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}
int main() {
    cin >> t;
    while(t--) solve();
}