#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;


    vector<pair<int, int>> candies;
    for(int i=0; i<n; ++i){
        int cnt, x;
        cin >> cnt >> x;
        candies.push_back({x, cnt});
    }
    sort(begin(candies), end(candies)); // sort by position
    
    auto distance = [&](int idx, int jdx){
        int x1 = candies[idx].first;
        int x2 = candies[jdx].first;
        return x2 - x1;
    };

    int answer = 0;
    int cnt = 0;
    int j = 0;
    
    for(int i=0; i<n; ++i){
        while(j < n && distance(i, j) <= 2*k){
            cnt += candies[j].second;
            ++j;   
        }
        answer = max(answer, cnt);
        
        cnt -= candies[i].second;
    }
    cout << answer << '\n';
    return 0;
}