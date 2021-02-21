#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii = pair<int, int>;
pii p1, p2, p3;
int ccw(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}
int main() {
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    int c = ccw(p2.x - p1.x, p2.y - p1.y, p3.x - p1.x, p3.y - p1.y);
    if(c > 0) cout << 1;
    else if(c < 0) cout << -1;
    else cout << 0;
}
