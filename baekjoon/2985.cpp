#include <bits/stdc++.h>
using namespace std;
int x, y, z;
int main() {
    cin >> x >> y >> z;
    if(x + y == z) cout << x << "+" << y << "=" << z;
    else if(x - y == z) cout << x << "-" << y << "=" << z;
    else if(x * y == z) cout << x << "*" << y << "=" << z;
    else if(x / y == z) cout << x << "/" << y << "=" << z;
    else if(y + z == x) cout << x << "=" << y << "+" << z;
    else if(y - z == x) cout << x << "=" << y << "-" << z;
    else if(y / z == x) cout << x << "=" << y << "/" << z;
    else if(y * z == x) cout << x << "=" << y << "*" << z;
}
