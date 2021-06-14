#include <bits/stdc++.h>
using namespace std;
int M, N, sum;
bool a[10001];
vector<int> p;
void solve() {
	a[1] = true;
	for(int i = 2; i * i <= N; i++)
		for(int j = i + i; j <= N; j += i)
			a[j] = true;
	for(int i = M; i <= N; i++)
		if(!a[i]) p.push_back(i);
	
	sort(p.begin(), p.end());
	for(auto &x: p) sum += x;
	if(p.size() == 0) cout << "-1" << '\n';
	else cout << sum << '\n' << p[0] << '\n';
}
int main() {
	cin >> M >> N;
	solve();
}
