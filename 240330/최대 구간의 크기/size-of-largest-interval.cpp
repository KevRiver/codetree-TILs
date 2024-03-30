#include <bits/stdc++.h>
using namespace std;

#define INF 1'000'000'001;
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
        int a, b; tie(a, b) = segments[i];
        points.push_back({a, 1});
        points.push_back({b, -1});
    }
    sort(points.begin(), points.end());
    
    
    int start = INF;
    int acc = 0;
    int answer = 0;
    for(int i=0; i<2*n; ++i){
        int x, w; tie(x, w) = points[i];
        acc += w;
        if(acc > 0){
            start = min(x, start);
        } else {
            answer = max(answer, x - start);
            start = INF;
        }
    }
    cout << answer << '\n';
    return 0;
}