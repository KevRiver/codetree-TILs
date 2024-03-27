#include <bits/stdc++.h>
using namespace std;

#define L 0
#define R 1

int main() {
    int N; cin >> N;
    vector<char> B(N); for(char& e: B) cin >> e;
    
    vector<vector<int>> rock(2, vector<int>(N+1, 0));
    rock[L][0] = B[0] == 'S' ? 1 : 0;
    rock[R][N-1] = B[N-1] == 'S' ? 1 : 0;
    
    vector<vector<int>> scissors(2, vector<int>(N+1, 0));
    scissors[L][0] = B[0] == 'P' ? 1 : 0;
    scissors[R][N-1] = B[N-1] == 'P' ? 1 : 0;

    vector<vector<int>> paper(2, vector<int>(N+1, 0));
    paper[L][0] = B[0] == 'H' ? 1 : 0;
    paper[R][N-1] = B[N-1] == 'H' ? 1 : 0;
    
    for(int i=1; i<N; ++i){
        rock[L][i] = rock[L][i-1] + (B[i] == 'S' ? 1 : 0);
        scissors[L][i] = scissors[L][i-1] + (B[i] == 'P' ? 1 : 0);
        paper[L][i] = paper[L][i-1] + (B[i] == 'H' ? 1 : 0);
    }
    for(int i=N-1; i>=0; --i){
        rock[R][i] = rock[R][i+1] + (B[i] == 'S' ? 1 : 0);
        scissors[R][i] = scissors[R][i+1] + (B[i] == 'P' ? 1 : 0);
        paper[R][i] = paper[R][i+1] + (B[i] == 'H' ? 1 : 0);
    }
    int answer = -1;
    for(int k=0; k<N; ++k){
        answer = max(answer, rock[L][k] + scissors[R][k+1]);
        answer = max(answer, rock[L][k] + paper[R][k+1]);
        answer = max(answer, scissors[L][k] + rock[R][k+1]);
        answer = max(answer, scissors[L][k] + paper[R][k+1]);
        answer = max(answer, paper[L][k] + rock[R][k+1]);
        answer = max(answer, paper[L][k] + scissors[R][k+1]);
    }
    cout << answer;

    return 0;
}