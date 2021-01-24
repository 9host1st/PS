#include <bits/stdc++.h>
using namespace std;
int a[10];
int main () {
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
        for(int j = 0; j < i; j++) {
            if(a[j] > a[i]) {
                swap(a[j], a[i]);
            }
        }
    }
    for(int i = 0; i < 10; i++) cout << a[i] << '\n';
}
