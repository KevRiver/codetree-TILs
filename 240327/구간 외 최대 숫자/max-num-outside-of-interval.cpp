#include <bits/stdc++.h>
using namespace std;

int arr[100'001];
int l[100'001];
int r[100'001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin >> N;
    int Q; cin >> Q;

    // idx range: [1, N]
    for(int i=1; i<=N; ++i)
        cin >> arr[i];
    
    for(int i=1, j=N; i<=N && j>=1; ++i, --j){
        l[i] = max(l[i-1], arr[i]);
        r[j] = max(r[j+1], arr[j]);
    }

    for(int i=0; i<Q; ++i){
        int start; cin >> start;
        int end; cin >> end;
        cout << max(l[start-1], r[end+1]) << '\n';
    }
    
    return 0;
}