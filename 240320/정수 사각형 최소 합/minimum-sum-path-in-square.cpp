#include <bits/stdc++.h>
using namespace std;

int grid[101][101];
int dp[101][102];

int main() {
    int n; cin >> n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin >> grid[i][j];
    for(int i=1; i<=n; ++i){
        for(int j=n; j>=1; --j){
            int less = dp[i][j+1]; // left
            if(i > 1) less = min(less, dp[i-1][j]);
            dp[i][j] = less + grid[i][j];
        }
    }
    cout << dp[n][1] << '\n';
    return 0;
}