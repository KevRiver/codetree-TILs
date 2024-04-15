#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int k; cin >> k;

    int answer = 0;
    int n = str.size();
    int j = 0;
    unordered_map<char, int> characters;
    for(int i=0; i<n; ++i){
        while(j < n && characters.size() <= k){
            characters[str[j]]++;
            ++j;
        }

        answer = max(answer, j-i);

        characters[str[i]]--;
        if(characters[str[i]] == 0) characters.erase(str[i]);
    }
    cout << answer << '\n';

    return 0;
}