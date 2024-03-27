#include <bits/stdc++.h>
using namespace std;

struct Tuple{
    int first;
    int second;
    int third;
};

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> stone(N);
    vector<Tuple> acc(N+1, {0, 0, 0});
    for(int i=0; i<N; ++i){
        cin >> stone[i];
        acc[i+1] = acc[i];
        switch(stone[i]){
            case 1: acc[i+1].first++; break;
            case 2: acc[i+1].second++; break;
            case 3: acc[i+1].third++; break;
        }
    }
    for(int i=0; i<Q; ++i){
        int start, end; cin >> start >> end;
        Tuple& f = acc[start - 1];
        Tuple& l = acc[end];
        cout << l.first - f.first << " "
        << l.second - f.second << " "
        << l.third - f.third << '\n';
    }
    return 0;
}