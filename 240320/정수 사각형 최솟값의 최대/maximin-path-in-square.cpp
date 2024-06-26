#include <bits/stdc++.h>
using namespace std;

int grid[101][101];
int dp[101][101];

int main() {

    int n; cin >> n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            cin >> grid[i][j];

    
    
    // dp[i][j] = (i, j)에 도달했을 때 지금까지의 거쳐온 숫자의 최소값
    // dp[i-1][j]에 도달 했을 때의 최소값, dp[i][j-1]의 최소값 중 큰 것과 grid[i][j]를 비교
    // min(max(dp[i-1][j], dp[i][j-1]), grid[i][j]);

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            
            int greater = INT_MAX;
            if(i > 1 && j > 1) greater = max(dp[i-1][j], dp[i][j-1]);
            else if(i > 1) greater = dp[i-1][j];
            else if(j > 1) greater = dp[i][j-1];

            dp[i][j] = min(greater, grid[i][j]);
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}