#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<pair<int, int>> points;
    set<int> x_set, y_set;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        x_set.insert(x);
        y_set.insert(y);
        points.push_back({x, y});
    }
    vector<tuple<int,int,int,int>> queries;
    for(int i=0; i<q; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x_set.insert(x1); x_set.insert(x2);
        y_set.insert(y1); y_set.insert(y2);
        queries.push_back({x1, y1, x2, y2});
    }

    unordered_map<int, int> x_mapper;
    int cnt = 0;
    for(int x: x_set) x_mapper[x] = cnt++;
    
    unordered_map<int, int> y_mapper;
    cnt = 0;
    for(int y: y_set) y_mapper[y] = cnt++;

    for(auto& p: points){
        p.first = x_mapper[p.first];
        p.second = y_mapper[p.second];
    }
    // O(N*Q)
    for(auto& q: queries){
        int x1, y1, x2, y2; tie(x1, y1, x2, y2) = q;
        x1 = x_mapper[x1];
        x2 = x_mapper[x2];
        y1 = y_mapper[y1];
        y2 = y_mapper[y2];
        int cnt = 0;
        for(auto& p: points){
            if(p.first < x1 
            || p.first > x2 
            || p.second < y1 
            || p.second > y2)
                continue;

            ++cnt;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}