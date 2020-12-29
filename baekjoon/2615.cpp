#include <bits/stdc++.h>
using namespace std;
int board[20][20];
int ansX, ansY;
bool isWhite, isBlack;

bool inrange(int nx, int ny) {
    if(nx < 0 || nx >= 19 || ny < 0 || ny >= 19) return false;
    return true;
}

bool isLine(int nx, int ny) {
    return false;
}
bool isDiagonal(int x, int y) {
    int cnt;
    if(board[x][y] == 0) return false;
    if(board[x][y] == 1) {
        cnt = 0;
        for(int i = 0; i < 6; i++) {
            int nx = x + i;
            int ny = y + i;
            if(inrange(nx, ny)) if(board[nx][ny] == 1) cnt++;
        }
        if(cnt == 5) return true;
    } else if(board[x][y] == 2) {
        cnt = 0;
        for(int i = 0; i < 6; i++) {
            int nx = x + i;
            int ny = y + i;
            if(inrange(nx, ny)) if(board[nx][ny] == 2) cnt++;
        }
        if(cnt == 5) return true;
    }
}

int main() {
    for(int i = 0; i < 19; i++) for(int j = 0; j < 19; j++) cin >> board[i][j];
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(isDiagonal(i, j) || isLine(i, j)) {
                if(board[i][j] == 1) {
                    ansX = i;
                    ansY = j;
                    isWhite = true;
                    break;
                } else if(board[i][j] == 0) {
                    ansX = i;
                    ansY = j;
                    isBlack = true;
                    break;
                }
            }
        }
    }
    if(isWhite) cout << "2" << '\n';
    if(isBlack) cout << "1" << '\n';
    cout << ansX << ' ' << ansY << '\n';
}
