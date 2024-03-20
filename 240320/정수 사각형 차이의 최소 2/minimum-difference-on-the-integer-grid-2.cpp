#include <bits/stdc++.h>
using namespace std;

int N;
int grid[100][100];
int dp[100][100];


int simulate(int lower_bound){
    
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            grid[i][j] = grid[i][j] >= lower_bound ? grid[i][j] : INT_MAX;

    dp[0][0] = grid[0][0];
    for(int j=1; j<N; ++j)
        dp[0][j] = max(dp[0][j-1], grid[0][j]);

    for(int i=1; i<N; ++i)
        dp[i][0] = max(dp[i-1][0], grid[i][0]);

    for(int i=1; i<N; ++i){
        for(int j=1; j<N; ++j){
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), grid[i][j]);
        }
    }
    return dp[N-1][N-1];
}

int main() {
    
    cin >> N;
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            cin >> grid[i][j];
    
    int answer = INT_MAX;
    for(int lower_bound = 1; lower_bound <= 100; ++lower_bound){
        int upper_bound = simulate(lower_bound);
        if(upper_bound == INT_MAX) continue;
        answer = min(answer, upper_bound - lower_bound);
    }    
    cout << answer << '\n';
    return 0;
}