#include <bits/stdc++.h>
using namespace std;

int pos[100'000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int q; cin >> q;
    for(int i=0; i<n; ++i){
        cin >> pos[i];
    }
    sort(pos, pos+n);
    // 정렬 후 two pointer? -> nlogn + n^2 -> 시간초과

    // lower, upper bound 활용 -> 입력: O(nlogn), lower/upper bound: O(logn)
    // -> nlogn + q(2logn), where n, q are maximum 100'000
    // -> O(3nlogn) -> 3 * 100'000 * log(100'000 ~= 1024*128 = 2^17)
    // 3nlogn ~= 5'100'000 왜 시간초과???
    function<int(int)> lb = [&](int k){
        int first = 0, last = n;
        int idx = last;
        while(first < last){
            int mid = (first + last)/2;
            if(pos[mid] < k){
                first = mid+1;
            } else {
                idx = mid;
                last = mid;
            }   
        }
        return idx;
    };
    function<int(int)> ub = [&](int k){
        int first = 0, last = n;
        int idx = last;
        while(first < last){
            int mid = (first + last)/2;
            if(pos[mid] <= k){
                first = mid+1;
            } else {
                idx = mid;
                last = mid;
            }
        }
        return idx;
    };
    for(int i=0; i<q; ++i){
        int a; cin >> a;
        int b; cin >> b;
        
        int cnt = ub(b) - lb(a);
        cout << cnt << '\n';
    }
    return 0;
}