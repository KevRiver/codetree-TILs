#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto cmp = [](const pii& l, const pii& r){
        return l.second > r.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

    int n; cin >> n;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        pq.push({x, y});
    }
    unordered_set<int> used;
    ll sum = 0;
    while(!pq.empty()){
        pii e = pq.top();
        pq.pop();
        if(used.find(e.first) != used.end()) continue;
        used.insert(e.first);
        sum += e.second;
    }
    cout << sum << '\n';
    return 0;
}