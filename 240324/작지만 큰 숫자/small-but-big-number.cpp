#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> seq(n);
    for(int i=0; i<n; ++i) cin >> seq[i];
    
    sort(begin(seq), end(seq));

    for(int reps = 0; reps < m; ++reps){
        int q; cin >> q;
        
        if(seq.empty()){
            cout << -1 << '\n';
            continue;
        }

        auto it = lower_bound(begin(seq), end(seq), q);

        // 모든 원소가 q 보다 크다
        if(it == seq.begin() && *it > q){
            cout << -1 << '\n';
            continue;
        }

        // 모든 원소가 q 보다 작거나 현재 it 값이 q보다 크다
        if(it == seq.end() || *it > q){
            advance(it, -1);
        } 
        cout << *it << '\n';
        seq.erase(it);        
    }
    return 0;
}