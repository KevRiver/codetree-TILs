#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int q; cin >> q;

    set<int> s;
    for(int i=0; i<n; ++i){
        int pos; cin >> pos;
        s.insert(pos);
    }
    // 정렬 후 two pointer? -> nlogn + n^2 -> 시간초과

    // lower, upper bound 활용 -> 입력: O(nlogn), lower/upper bound: O(logn)
    // -> nlogn + q(2logn), where n, q are maximum 100'000
    // -> O(3nlogn) -> 3 * 100'000 * log(100'000 ~= 1024*128 = 2^17)
    // 3nlogn ~= 5'100'000 왜 시간초과???
    for(int i=0; i<q; ++i){
        int a; cin >> a;
        int b; cin >> b;

        auto it = s.lower_bound(a);
        auto jt = s.upper_bound(b);

        int cnt = distance(it, jt);
        cout << cnt << '\n';
    }
    return 0;
}