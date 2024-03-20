#include <bits/stdc++.h>
using namespace std;

int grid[100][100];
struct Node{
    int min = 0;
    int max = 0;
    int abs(){
        return max-min;
    }
};
Node dp[100][100]; // min, max

int main() {
    int n; cin >> n;

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> grid[i][j];

    // 이전 노드의 min, max 와 현재 값을 비교해서 현재 노드가 갱신된다
    // 갱신된 노드의 최대 최소 차이가 작은 것을 dp에 남긴다
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int cur = grid[i][j];
            if(i > 0 && j > 0){
                const Node& above = dp[i-1][j];
                const Node& left = dp[i][j-1];

                Node a = {min(above.min, cur), max(above.max, cur)};
                Node b = {min(left.min, cur), max(left.max, cur)};
                if(a.abs() <= b.abs()){
                    cout << "above" << "\n";
                    dp[i][j] = a;
                } else {
                    cout << "left" << "\n";
                    dp[i][j] = b;
                }
                dp[i][j] = a.abs() <= b.abs() ? a : b;
            } else if(i > 0){
                const Node& above = dp[i-1][j];
                cout << "above" << '\n';
                dp[i][j] = {min(above.min, cur), max(above.max, cur)};
            } else if(j > 0){
                const Node& left = dp[i][j-1];
                cout << "left" << '\n';
                dp[i][j] = {min(left.min, cur), max(left.max, cur)};
            } else{
                cout << "start" << '\n';
                dp[i][j] = {cur, cur};
            }
        }
    }
    cout << dp[n-1][n-1].abs() << '\n';
    return 0;
}