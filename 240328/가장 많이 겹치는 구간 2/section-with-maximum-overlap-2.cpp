#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    map<int, int> ranges;
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        int b; cin >> b;
        ranges[a]++;
        ranges[b+1]--;
    }
    int acc = 0;
    int answer = 0;
    for(auto it = begin(ranges); it != end(ranges); ++it){
        acc += it->second;
        answer = max(answer, acc);
    }
    cout << answer << '\n';
    
    return 0;
}