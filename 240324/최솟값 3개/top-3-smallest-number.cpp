#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    auto cmp = [](int l, int r){
        return l > r;
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    int elems[3];
    for(int i=0; i<n; ++i){
        int e;
        cin >> e;
        pq.push(e);
        if(pq.size() < 3){
            cout << -1 << '\n';
            continue;
        }

        for(int j=0; j<3; ++j){
            elems[j] = pq.top();
            pq.pop();
        }

        long long product = (long long)elems[0] * elems[1] * elems[2];
        cout << product << '\n';

        for(int j=0; j<3; ++j){
            pq.push(elems[j]);
        }

    }

    return 0;
}