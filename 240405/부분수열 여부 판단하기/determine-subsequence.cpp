#include <bits/stdc++.h>
using namespace std;


bool is_subsequence(const vector<int>& a, const vector<int>& b){
    int n = a.size();
    int m = b.size();

    int j=0;
    for(int i=0; i<n; ++i){
        if(a[i] != b[j]) continue;
        ++j;
    }
    return j == m;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for(int& e: a) cin >> e;
    vector<int> b(m); for(int& e: b) cin >> e;

    cout << (is_subsequence(a, b) ? "Yes" : "No") << '\n';

    return 0;
}