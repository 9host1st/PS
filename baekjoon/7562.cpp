#include <bits/stdc++.h>
using namespace std; 
using pii=pair<int, int>;
const int horseX[8] = {-1, -2, 2, -1, 1, 2, 2, 1};
const int horseY[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dx[4] = {-1, 1, 0, 0};
const iny dy[4] = {0, 0, -1, 1};
int K, W, H;
int a[201][201];

bool inrange(int nx, int ny) {
    if(nx < 0 || nx >= W || ny < 0 || ny >= H) return false;
    return true;
}
int main() {
    cin >> K;
    cin >> W >> H;
    for(int i = 0; i < W; i++) for(int j = 0; j < H; j++) cin >> a[i][j];
}
