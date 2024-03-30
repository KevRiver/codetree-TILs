#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<pii> segments;
    for(int i=0; i<N; ++i){
        int a, b;
        cin >> a >> b;
        segments.push_back({a, b});
    }
    vector<tuple<int, int, int>> points;
    for(int i=0; i<N; ++i){
        int a, b; tie(a, b) = segments[i];
        points.push_back({a, 1, i});
        points.push_back({b, -1, i});
    }
    sort(points.begin(), points.end());
    int len = 0;
    int prev = -1;
    unordered_set<int> lines;
    vector<int> wegiths(N, 0);
    for(int i=0; i<2*N; ++i){
        int x, w, idx; tie(x, w, idx) = points[i];

        int cnt = lines.size();
        if(cnt > 0){
            len += x - prev;
        }
        if(cnt == 1){
            int target = *(lines.begin());
            wegiths[target] += x - prev;
        }
        if(w == 1) lines.insert(idx);
        else lines.erase(idx);
        prev = x;
    }
    int answer = len - *min_element(wegiths.begin(), wegiths.end());
    cout << answer << '\n';
    return 0;
}