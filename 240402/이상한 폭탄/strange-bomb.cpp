#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> bombs(N);
    for(int i=0; i<N; ++i) cin >> bombs[i];

    multiset<int> s;
    
    // 0
    // 3 4 2
    for(int i=1; i<K+1; ++i) 
        s.insert(bombs[i]);
    
    int ans = -1;
    for(int i=0; i<N-1; ++i){
        if(s.find(bombs[i]) != s.end())
            ans = max(ans, bombs[i]);
            
        if(i+1+K < N)
            s.insert(bombs[i+1+K]);
        s.erase(s.find(bombs[i+1]));
    }
    cout << ans << '\n';

    return 0;
}