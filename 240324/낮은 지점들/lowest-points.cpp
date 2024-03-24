#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    unordered_map<int, int> min_y;
    for(int i=0; i<n; ++i){
        int x, y;
        cin >> x >> y;
        if(min_y.find(x) == min_y.end()){
            min_y[x] = y;
        } else {
            min_y[x] = min(min_y[x], y);
        }
    }
    long long sum = 0;
    for(auto it = min_y.begin(); it != min_y.end(); ++it){
        sum += it->second;
    }
    cout << sum;

    return 0;
}