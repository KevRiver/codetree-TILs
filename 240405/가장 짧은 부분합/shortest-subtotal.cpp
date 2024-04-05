#include <bits/stdc++.h>
using namespace std;

int seq[100'000];

int main() {
    int n, s;
    cin >> n >> s;
    for(int i=0; i<n; ++i) cin >> seq[i];

    int len = INT_MAX;
    int sum = 0;
    int i=0, j=0;
    while(i < n && j < n){
        if(sum >= s){
            len = min(len, j-i);
            sum -= seq[i++];
        } else {
            sum += seq[j++];
        }
    }
    if(len == INT_MAX) len = -1;
    cout << len << '\n';

    return 0;
}