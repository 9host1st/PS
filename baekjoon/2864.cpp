#include <bits/stdc++.h>
using namespace std;
string A, B;
string A2, B2;
int main() {
    cin >> A >> B;
    A2 = A;
    B2 = B;
    for(int i = 0; i < A.size(); i++) 
        if(A[i] == '5') A2[i] = '6';
    for(int i = 0; i < B.size(); i++)
        if(B[i] == '5') B2[i] = '6';
    for(int i = 0; i < A.size(); i++)
        if(A[i] == '6') A[i] = '5';
    for(int i = 0; i < B.size(); i++)
        if(B[i] == '6') B[i] = '5';
    cout << stoi(A) + stoi(B) << ' ';
    cout << stoi(A2) + stoi(B2) << '\n';
}
