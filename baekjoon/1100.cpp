#include <bits/stdc++.h>
using namespace std;
string board[8];
int ans;
int main() {
    for(int i = 0; i < 8; i++) cin >> board[i];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 'F') {
                if((i % 2 == 0) && (j % 2 == 0)) ans++;
                else if((i % 2 == 1) && (j % 2 == 1)) ans++;
            }
        }
    }
    cout << ans;
}
