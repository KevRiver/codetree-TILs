#include <bits/stdc++.h>
using namespace std;

#define INF 1'000'000'001
#define pii pair<int, int>

int main() {
    int n; cin >> n;
    
    vector<pii> segments;
    for(int i=0; i<n; ++i){
        int a, b;
        cin >> a >> b;
        segments.push_back({a, b});
    }

    vector<pii> points;
    for(int i=0; i<n; ++i){
        int src, dest;
        tie(src, dest) = segments[i];
        points.push_back({src, 1});
        points.push_back({dest, -1});
    }
    sort(points.begin(), points.end());

    int x = INF;
    int acc = 0;
    int ans = 0;
    for(int i=0; i<2*n; ++i){
        int cur, w; tie(cur, w) = points[i];
        acc += w;
        if(acc > 0){
            x = min(x, cur);
        } else {
            ans += cur - x;
            x = INF;
        }
    }
    cout << ans << '\n';
    
    return 0;
}