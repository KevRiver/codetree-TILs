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
Node dp1[100][100]; // 최대값이 최소일 때
Node dp2[100][100]; // 최소값이 최대일 때

Node merge(const Node& a, const Node& b){
    Node result = {min(a.min, b.min), max(a.max, b.max)};
    return result;
}

int main() {
    int n; cin >> n;

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin >> grid[i][j];


    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            int cur = grid[i][j];
            if(i > 0 && j > 0){
                const Node& less_max = dp1[i-1][j].max <= dp1[i][j-1].max ? dp1[i-1][j] : dp1[i][j-1];
                dp1[i][j] = merge(less_max, {cur, cur});
                const Node& greater_min = dp2[i-1][j].min >= dp2[i][j-1].min ? dp2[i-1][j] : dp2[i][j-1];
                dp2[i][j] = merge(greater_min, {cur, cur});
            } else if(i > 0){
                dp1[i][j] = merge(dp1[i-1][j], {cur, cur});
                dp2[i][j] = merge(dp2[i-1][j], {cur, cur});
            } else if(j > 0){
                dp1[i][j] = merge(dp1[i][j-1], {cur, cur});
                dp2[i][j] = merge(dp2[i][j-1], {cur, cur});
            } else {
                dp1[i][j] = {cur, cur};
                dp2[i][j] = {cur, cur};
            }
        }
    }
    int v = dp1[n-1][n-1].abs();
    int w = dp2[n-1][n-1].abs();
    int answer = min(v, w);
    cout << answer << '\n';

    return 0;
}