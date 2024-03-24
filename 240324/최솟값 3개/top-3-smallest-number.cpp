#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    multiset<int> s;
    for(int i=0; i<n; ++i){
        int e; cin >> e;
        s.insert(e);
        if(s.size() < 3){
            cout << -1 << '\n';
            continue;
        }
        auto it = s.begin();
        long long product = *it;
        for(int j=0; j<2; ++j){
            ++it;
            product *= *it;
        }
        cout << product << '\n';
    }

    return 0;
}