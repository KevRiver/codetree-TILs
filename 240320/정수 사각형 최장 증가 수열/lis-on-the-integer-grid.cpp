#include <bits/stdc++.h>
using namespace std;

int N;
int dp[501][501];
int grid[501][501];
bool visited[501][501];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int dfs(int y, int x){
    if(dp[y][x] != 0) return dp[y][x];
    
    int max_len = 0;
    for(int k=0; k<4; ++k){
        int ny = y + dy[k];
        int nx = x + dx[k];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if(grid[ny][nx] <= grid[y][x]) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = true;

        max_len = max(max_len, dfs(ny, nx));

        visited[ny][nx] = false;
    }
    return 1 + max_len;
}

int main() {
    cin >> N;
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            cin >> grid[i][j];

    memset(dp, 0, sizeof(dp));

    int answer = -1;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            answer = max(answer, dfs(i, j));
        }
    }
    cout << answer << '\n';

    return 0;
}