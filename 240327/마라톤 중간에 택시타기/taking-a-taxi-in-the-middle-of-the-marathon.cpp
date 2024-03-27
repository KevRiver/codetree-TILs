#include <bits/stdc++.h>
using namespace std;

int main() {
    // check point: 1 2 3 ... N
    int N; cin >> N;
    vector<pair<int, int>> pos(N + 1);
    for(int i=1; i<=N; ++i){
        cin >> pos[i].first >> pos[i].second;
    }
    function<int(int,int)> get_distance = [&](int i, int j){
        return abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
    };
    vector<int> l(N+1); l[1] = 0;
    for(int i=2; i<=N; ++i){
        l[i] = l[i-1] + get_distance(i, i-1);
    }
    vector<int> r(N+1); r[N] = 0;
    for(int i=N-1; i>=0; --i){
        r[i] = r[i+1] + get_distance(i, i+1);
    }
    int answer = INT_MAX;
    for(int i=2; i<N; ++i){
        int dist = l[i-1] + r[i+1] + get_distance(i-1, i+1);
        answer = min(answer, dist);
    }
    cout << answer << '\n';
    return 0;
}