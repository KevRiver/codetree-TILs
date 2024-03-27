#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    vector<int> l(N, 0);
    vector<int> r(N, 0);
    for(int i=2, j=N-3; i<=N-3 && j>=2; ++i, --j){
        l[i] = max(l[i-1], arr[i-2]);
        r[j] = max(r[j+1], arr[j+2]);
    }
    
    int answer = -1;
    for(int k=2; k<N-2; ++k){
        answer = max(answer, l[k] + arr[k] + r[k]);
    }
    cout << answer << '\n';

    return 0;
}