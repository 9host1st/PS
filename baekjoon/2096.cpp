#include <bits/stdc++.h>
using namespace std;
int N, a[3], b[3], c[3], d[3];
int main () {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 3; j++) {
			scanf("%d", c + j);
			d[j] = c[j];
			c[j] += max(a[1], (j == 1)?max(a[0], a[2]):a[j]);
			d[j] += min(b[1], (j == 1)?min(b[0], b[2]):b[j]);
		}
		memcpy(a, c, sizeof(int) * 3);
		memcpy(b, d, sizeof(int) * 3);
	}
	sort(a, a + 3);
	sort(b, b + 3);
	printf("%d %d\n", a[2], b[0]);
}
