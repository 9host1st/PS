#include <bits/stdc++.h>
using namespace std;
int x, y, z;
int main() {
  cin >> x >> y;
  if(x == y) {
    cout << x << '\n';
    return 0;
  }
  else {
  	if(x == 1) {
    	if(y == 2) cout << "0" << '\n';
        else if(y == 0) cout << "2" << '\n';
    } else if(x == 2) {
    	if(y == 1) cout << "0" << '\n';
      	else if(y == 0) cout << "1" << '\n';
    } else if(x == 0) {
    	if(y == 1) cout << "2" << '\n';
      	else if(y == 2) cout << "1" << '\n';
    }
  }
}