#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    const int mod = 7;
    vector<int> acc(n+1); acc[0] = 0;
    unordered_map<int, int> memo = {{0, 0}};
    
    for(int i=1; i<=n; ++i){
        int num; cin >> num;
        acc[i] = (acc[i-1]%mod + num%mod)%mod;
        if(memo.find(acc[i]) == memo.end())
            memo[acc[i]] = i;
    }

    int len = 0;
    for(int i=1; i<=n; ++i){
        auto look = memo.find(acc[i]);
        if(look == memo.end()) continue;
        int j = look->second;
        if(j >= i) continue;
        len = max(len, i-j);
    }
    cout << len;

    return 0;
}