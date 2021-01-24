#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int t;
string x, y, z;
int ans;
int main() {
    cin >> t;
    while(t--) {
        cin >> x >> y >> z;
        if(m.find(x) == m.end()) m.insert({x, 1});
        if(m.find(y) == m.end()) m.insert({y, 1});
        if(m.find(z) == m.end()) m.insert({z, 1});
        if(m.find(x) != m.end()) m[x]++;
        if(m.find(y) != m.end()) m[y]++;
        if(m.find(z) != m.end()) m[z]++;
    }
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->second << '\n';
    }
}
