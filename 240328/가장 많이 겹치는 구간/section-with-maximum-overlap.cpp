#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int x[200'001];

int main() {

    int n; cin >> n;
    int min_x = 200'001;
    int max_x = -1;
    for(int i=0; i<n; ++i){
        int a; cin >> a;
        int b; cin >> b;
        
        min_x = min(min_x, a);
        max_x = max(max_x, b);

        x[a]++;
        x[b+1]--;
    }
    int answer = 0;
    int acc = 0;
    for(int i=min_x; i<=max_x; ++i){
        acc += x[i];
        answer = max(answer, acc);
    }
    cout << answer << '\n';
    
    return 0;
}