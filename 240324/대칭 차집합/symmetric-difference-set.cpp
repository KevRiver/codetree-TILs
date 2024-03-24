#include <bits/stdc++.h>
using namespace std;

int main() {
    int card_a, card_b;
    cin >> card_a >> card_b;

    unordered_set<int> set_a;
    for(int i=0; i<card_a; ++i) {
        int e; cin >> e;
        set_a.insert(e);
    }
    unordered_set<int> set_b;
    for(int i=0; i<card_b; ++i){
        int e; cin >> e;
        set_b.insert(e);
    }
    int cnt = 0;
    for(auto it = begin(set_a); it != end(set_a); ++it){
        int e = *it;
        if(set_b.find(e) != set_b.end()) cnt++;
    }
    
    int answer = card_a + card_b - 2*cnt;
    cout << answer << '\n';
    
    return 0;
}