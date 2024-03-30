#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<tuple<int, int, int>> segments;
    for(int i=0; i<n; ++i){
        int p, q; cin >> p >> q;
        segments.push_back({p, q, i});
    }

    vector<tuple<int, int, int>> points;
    for(int i=0; i<n; ++i){
        int p, q, idx; tie(p, q, idx) = segments[i];
        points.push_back({p, 1, idx});
        points.push_back({q, -1, idx});
    }
    sort(points.begin(), points.end());
    
    // 비어있는 컴퓨터 중 가장 번호가 작은 컴퓨터를 먼저 사용한다
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<=n; ++i) pq.push(i);

    vector<int> answer(n);
    for(int i=0; i<2*n; ++i){
        int w, idx; tie(ignore, w, idx) = points[i];
        if(w > 0){
            int computer = pq.top(); pq.pop();
            answer[idx] = computer;
        } else {
            int computer = answer[idx];
            pq.push(computer);
        }
    }
    for(int e: answer) cout << e << " ";

    return 0;
}