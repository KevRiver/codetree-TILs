#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    map<int, int> m;
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        int b; cin >> b;
        m[a]++;
        m[b]--;
    } // O(nlogn)

    int acc = 0;
    int cnt = 0;
    for(auto it = m.begin(); it != m.end(); ++it){
        acc += it->second;
        if(acc == 0) ++cnt;
    } // O(2n)
    cout << cnt << '\n';
    

    return 0;
}