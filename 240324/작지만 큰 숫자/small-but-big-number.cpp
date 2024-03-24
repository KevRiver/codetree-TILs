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
        if(it == seq.end()){
            cout << -1 << '\n';
            continue;
        }
        
        if(*it > q && it == seq.begin()){
            cout << -1 << '\n';
            continue;
        }

        if(*it > q) advance(it, -1);
        cout << *it << '\n';
        seq.erase(it);        
    }
    return 0;
}