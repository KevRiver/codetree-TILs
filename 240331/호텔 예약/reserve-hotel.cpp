#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> segments;
    for(int i=0; i<n; ++i){
        int s, e;
        cin >> s >> e;
        segments.push_back({s, e});
    }

    vector<pair<int, int>> points;
    for(int i=0; i<n; ++i){
        int s, e; tie(s, e) = segments[i];
        points.push_back({s, 1});
        points.push_back({e, -1});
    }
    auto cmp = [](const pair<int,int>& l, const pair<int,int>& r){
        if(l.first == r.first) return l.second > r.second;
        return l.first < r.first;
    };
    sort(points.begin(), points.end(), cmp);

    int answer = 0;
    int cnt = 0;
    for(int i=0; i<2*n; ++i){
        int t, w; tie(t, w) = points[i];
        cnt += w;
        answer = max(answer, cnt);
    }
    cout << answer << '\n';
    return 0;
}