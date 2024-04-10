#include <bits/stdc++.h>
using namespace std;

int main() {
    int dat[26] = {0, };
    string str; cin >> str;
    int n = str.size();
    int answer = 0;
    int len = 0;
    int j = 0;
    for(int i=0; i<n; ++i){
        while(j < n && dat[str[j] - 'a'] == 0){
            dat[str[j] - 'a']++;
            len++;
            j++;
        }
        answer = max(answer, len);
        dat[str[i] - 'a']--;
        len--;
    }
    cout << answer << '\n';
    return 0;
}