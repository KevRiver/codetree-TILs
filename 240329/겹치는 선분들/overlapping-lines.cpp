#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define INF 1'000'000'001
int main() {
    int N; cin >> N;
    int K; cin >> K;

    map<int, int> points;
    int src = 0;
    for(int i=0; i<N; ++i){
        int len; cin >> len;
        char dir; cin >> dir;
        int dest = src + (dir == 'R' ? len : -len);
        if(src <= dest){
            points[src]++;
            points[dest]--;
        } else {
            points[src]--;
            points[dest]++;
        }
        src = dest;
    }

    int acc = 0;
    int answer = 0;
    int start = INF;
    for(auto it = points.begin(); it != points.end(); ++it){
        acc += it->second;
        if(acc >= K){
            start = min(start, it->first);
        } else {
            int len = it->first - start;
            if(len < 0) len = 0;
            answer += len;
            start = INF;
        }
    }
    cout << answer << '\n';
    // 선분이 겹친 모든 구간의 길이 합을 구하기
    return 0;
}