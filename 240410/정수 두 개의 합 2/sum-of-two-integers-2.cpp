#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n); 
    for(int& e: arr) cin >> e;
    
    // 두 개를 고르고 두 개의 합이 k 이하가 되는 경우의 수
    // 정렬 후, upper_bound - 1 까지의 길이 계산
    sort(begin(arr), end(arr));
    int cnt = 0;
    auto last = next(end(arr), -1);
    for(auto it = begin(arr); it != last; ++it){
        int cur = *it;
        int le = k-cur; // less or equal
        
        auto jt = upper_bound(next(it, 1), end(arr), le);

        cnt += distance(it, jt) - 1;
    }
    cout << cnt << '\n';

    return 0;
}