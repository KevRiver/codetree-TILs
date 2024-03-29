#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    map<int, int> segments;
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        int b; cin >> b;
        segments[a]++;
        segments[b+1]--;
    }
    int acc = 0;
    int answer = 0;
    for(auto it = begin(segments); it != end(segments); ++it){
        acc += it->second;
        answer = max(answer, acc);
    }
    cout << answer << '\n';

    return 0;
}