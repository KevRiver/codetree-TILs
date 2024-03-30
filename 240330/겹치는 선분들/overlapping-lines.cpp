#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define INF 1'000'000'001
int main() {
    int N; cin >> N;
    int K; cin >> K;

    vector<pii> segments;
    int x = 0;
    for(int i=0; i<N; ++i){
        int len; char dir;
        cin >> len >> dir;
        
        if(dir == 'R'){
            segments.push_back({x, x+len});
            x += len;
        } else {
            segments.push_back({x - len, x});
            x -= len;
        }
    }

    vector<pii> points;
    for(int i=0; i<N; ++i){
        int x1, x1;
        tie(x1, x2) = segments[i];
        points.push_back({x1, 1});
        points.push_back({x2, -1});
    }
    sort(points.begin(), points.end());

     // 선분이 겹친 모든 구간의 길이 합을 구하기
    int answer = 0;
    int acc = 0;
    for(int i=0; i< 2*N; ++i){
        int x, w;
        tie(x, w) = points[i];
        if(acc >= K){
            int prev;
            tie(prev, ignore) = points[i-1];
            answer += x - prev;
        }
        acc += w;
    }
    cout << answer << '\n';
   
    return 0;
}