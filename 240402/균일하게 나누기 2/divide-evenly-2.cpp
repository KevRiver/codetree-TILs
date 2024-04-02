#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
     
    vector<pair<int, int>> points;
    int max_y = 0;
    for(int i=0; i<n; ++i){
        int x, y; 
        cin >> x >> y;
        points.push_back({x, y});
        max_y = max(max_y, y);
    }
    sort(points.begin(), points.end());

    int ans = INT_MAX;
    for(int b=0; b < max_y+1; b += 2){
        
        int quad[4] = {0, };
        for(int i=0; i<n; ++i){
            int y; tie(ignore, y) = points[i];
            if(y > b) quad[0]++;
            else quad[3]++;
        }

        for(int i=0; i<n; ++i){
            if(i == 0 || points[i].first != points[i-1].first){
                int max_quad = 0;
                for(int j=0; j<4; ++j)
                    max_quad = max(max_quad, quad[j]);
                ans = min(max_quad, ans);
            }

            int y; tie(ignore, y) = points[i];
            if(y > b){
                quad[0]--;
                quad[1]++;
            } else {
                quad[2]++;
                quad[3]--;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}