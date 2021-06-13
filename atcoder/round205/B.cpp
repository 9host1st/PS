#include <bits/stdc++.h>
using namespace std;
int N, a[1001];
bool chk = true;
void solve() {
    for(int i = 0; i < N - 1; i++) 
	if(a[i] + 1 != a[i + 1])
	    chk = false;
	
    if(!chk) cout << "No";
    else cout << "Yes";
    
}
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);
    solve();
}