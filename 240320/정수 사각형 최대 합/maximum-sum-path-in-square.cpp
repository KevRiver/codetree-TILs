#include <bits/stdc++.h>
using namespace std;

int grid[101][101];
int dp[101][101];

int main() {
    int n; cin >> n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin >> grid[i][j];


    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    cout << dp[n][n];
    return 0;
}