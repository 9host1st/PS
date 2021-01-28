#include <bits/stdc++.h>
using namespace std;
int L, P, V;
int ans;

int solve() {
	int t = (V / P) * L;
	int t2 = (V % P);
	if(t2 >= L) t2 = L;
	ans = t + t2;
	return ans;
}

int main() {
	for(int i = 1; ; i++) {
		cin >> L >> P >> V;
		if(L == 0 && P == 0 && V == 0) exit(0);
		cout << "Case " << i << ": " << solve() << '\n';
	}
}
