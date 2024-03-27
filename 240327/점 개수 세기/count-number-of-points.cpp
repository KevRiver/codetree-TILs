#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n; cin >> q;

    set<int> s;
    for(int i=0; i<n; ++i){
        int pos; cin >> pos;
        s.insert(pos);
    }
    for(int i=0; i<q; ++i){
        int a, b;
        cin >> a >> b;
        auto it = s.lower_bound(a);
        auto jt = s.upper_bound(b);
        int cnt = distance(it, jt);
        cout << cnt << '\n';
    }
    return 0;
}