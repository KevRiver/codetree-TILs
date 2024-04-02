#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    vector<ll> energy(n, 0);
    for(int i=0; i<n-1; ++i) cin >> energy[i];
    vector<ll> cost(n, 0); // 에너지 1을 채우는 비용
    for(int i=0; i<n; ++i) cin >> cost[i];

    vector<ll> e(n, 0);
    e[n-1] = 0;
    for(int i=n-2; i>=0; --i){
        e[i] = e[i+1] + energy[i];
    }

    vector<ll> c(n, 0);
    c[n-1] = 0;
    for(int i=n-2; i>=0; --i){
        c[i] = min(cost[i]*e[i], cost[i]*energy[i] + c[i+1]);
    }
    cout << c[0] << '\n';

    return 0;
}