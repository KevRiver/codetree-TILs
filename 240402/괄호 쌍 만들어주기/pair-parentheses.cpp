#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int len = s.size();

    vector<int> r(len, 0);

    // (())
    // 0 len-3 len-2 len-1
    for(int i=len-2; i>=0; --i){    
        r[i] = r[i+1];
        if(s[i] == ')' && s[i+1] == ')') r[i]++;
    }

    int cnt = 0;
    for(int i=0; i<len-3; ++i){
        if(s[i] != '(' || s[i+1] != '(')
            continue;
        cnt += r[i+2];
    }
    cout << cnt << '\n';

    return 0;
}