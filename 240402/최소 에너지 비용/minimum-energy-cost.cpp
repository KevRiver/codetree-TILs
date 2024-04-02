#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    vector<ll> energy(n, 0);
    for(int i=1; i<n; ++i) cin >> energy[i];
    vector<ll> cost(n, 0); // 에너지 1을 채우는 비용
    for(int i=0; i<n; ++i) cin >> cost[i];

    vector<ll> c(n); 
    c[0] = cost[0];
    for(int i=1; i<n; ++i) c[i] = min(c[i-1], cost[i]);

    ll ans = 0;
    for(int x=1; x<n; ++x){
        ans += c[x-1]*energy[x];
    } // x 번째 노드로 가기 위한 최소 비용 = x 번째 노드 이전까지 등장했던 최저가 비용 * 다음 노드로 가기 위해 필요한 에너지
    cout << ans << '\n';
    return 0;
}