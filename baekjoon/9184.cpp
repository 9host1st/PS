/* 9184 */
#include <bits/stdc++.h>
using namespace std;
int a, b, c, cache[51][51][51];

int f(int x, int y, int z) {
	if(x <= 0 || y <= 0 || z <= 0) return 1;
	if(x > 20 || y > 20 || z > 20) return f(20, 20, 20);
	int &ret = cache[x][y][z];
	if(cache[x][y][z] != -1) return ret;
	if(x < y && y < z && cache[x][y][z]) return ret = f(x, y, z - 1) + f(x, y - 1, z - 1) - f(x, y - 1, z);
	else return ret = f(x - 1, y, z) + f(x - 1, y - 1, z) + f(x - 1, y, z - 1) - f(x - 1, y - 1, z - 1);
}
void solve(int a, int b, int c) {
	memset(cache, -1, sizeof(cache));
	printf("w(%d, %d, %d) = %d\n", a, b, c, f(a, b, c));	
	f(a, b, c);
}
int main() {
	while(1) {
		scanf("%d %d %d", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1) return 0;
		solve(a, b, c);
	}
}
