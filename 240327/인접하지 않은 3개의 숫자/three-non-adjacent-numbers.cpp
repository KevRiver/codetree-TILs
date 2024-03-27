#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    vector<int> l(N, 0);
    for(int i=2; i<=N-3; ++i){
        l[i] = max(l[i-1], arr[i-2]);
    }

    vector<int> r(N, 0);
    for(int i=N-3; i>=2; --i){
        r[i] = max(r[i+1], arr[i+2]);
    }
    
    int answer = -1;
    for(int k=2; k<N-2; ++k){
        answer = max(answer, l[k] + arr[k] + r[k]);
    }
    cout << answer << '\n';

    return 0;
}