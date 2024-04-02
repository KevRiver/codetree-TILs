#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> bombs(N);
    for(int i=0; i<N; ++i) cin >> bombs[i];

    unordered_map<int, int> idx;
    vector<int> r(N);
    for(int i=N-1; i>=0; --i){
        if(idx.find(bombs[i]) == idx.end()){
            r[i] = -1;
        } else {
            r[i] = idx[bombs[i]];
        }
        idx[bombs[i]] = i;
    }
    
    int ans = -1;
    for(int i=0; i<N; ++i){
        if(r[i] != -1 && r[i] - i <= K)
            ans = max(ans, bombs[i]);
    }
    cout << ans << '\n';

    return 0;
}