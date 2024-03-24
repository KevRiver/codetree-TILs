#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

    set<int> s;
    for(int i=0; i<n; ++i){
        int x; cin >> x;
        s.insert(x);
    }
    
    for(int i=0; i<m; ++i){
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        if(it == s.begin()){
            cout << -1 << '\n';
            continue;
        }
        --it;
        cout << *it << '\n';
        s.erase(it);
    }
    
    return 0;
}