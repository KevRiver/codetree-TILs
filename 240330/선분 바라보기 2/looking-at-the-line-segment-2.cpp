#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<tuple<int, int, int, int>> segments;
    for(int color=0; color<n; ++color){
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        segments.push_back({y, x1, x2, color});
    }
    
    vector<tuple<int, int, int, int>> points;
    for(int i=0; i<n; ++i){
        int y, x1, x2, color; tie(y, x1, x2, color) = segments[i];
        points.push_back({x1, y, 1, color});
        points.push_back({x2, y, -1, color});
    }
    sort(points.begin(), points.end());

    set<pii> lines;
    unordered_set<int> colors;
    for(int i=0; i<2*n; ++i){
        int y, w, idx; tie(ignore, y, w, idx) = points[i];
        if(w > 0){
            // 선분 추가
            lines.insert({y, idx});
            if(lines.begin()->first >= y){
                // 현재 가장 아래에 있는 선분이 방금 추가한 선분이라면
                colors.insert(idx);
            }
        } else {
            // 선분 삭제
            pii l = {y, idx};
            lines.erase(l);
            if(lines.empty()) continue;

            // 선분 삭제 후 가장 아래쪽에 있는 선분의 색깔을 확인
            int bottom_color = lines.begin()->second;
            if(colors.find(bottom_color) == colors.end()){
                // 처음 등장한 색깔이면 추가
                colors.insert(bottom_color);
            }
        }
    }
    int answer = colors.size();
    cout << answer << '\n';
    return 0;
}