#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
int dp[100][100];

int main() {
    int n; cin >> n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> arr[i][j];

    dp[0][0] = arr[0][0];
    for(int i=1; i<n; ++i) dp[i][0] = max(dp[i-1][0], arr[i][0]);
    for(int j=1; j<n; ++j) dp[0][j] = max(dp[0][j-1], arr[0][j]);
    for(int i=1; i<n; ++i){
        for(int j=1; j<n; ++j){
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), arr[i][j]);
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}