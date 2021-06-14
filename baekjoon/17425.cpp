#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll T, N, f[1000001], sum[1000001];
void pre() {
	for(int i = 1; i <= 1000000; i++) f[i] = 1;
	for(int i = 2; i <= 1000000; i++) {
		for(int j = 1; i * j <= 1000000; j++) {
			f[i*j] += i;
        }
    }
	for(int i = 1; i <= 1000000; i++) sum[i] = sum[i - 1] + f[i];
}
ll solve(ll x) {return sum[x];}
int main() {
	pre();
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &N);
        printf("%lld\n", solve(N));
	}
}

