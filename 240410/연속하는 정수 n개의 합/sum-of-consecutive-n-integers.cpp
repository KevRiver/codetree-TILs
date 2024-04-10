#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> seq(n);
    for(int i=0; i<n; ++i) cin >> seq[i];
    
    int sum = 0;
    int cnt = 0;
    int j = 0;
    for(int i=0; i<n; ++i){
        while(j < n && sum < m){
            sum += seq[j++];
        }
        if(sum == m) cnt++;
        sum -= seq[i];
    }
    cout << cnt << '\n';
    return 0;
}