#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    int k; cin >> k;

    int answer = 0;
    int n = str.size();
    int j = 0;
    unordered_map<char, int> u;
    auto is_exist = [&](char ch){
        return u.find(ch) != u.end();
    };
    for(int i=0; i<n; ++i){
        while(j < n && u.size() <= k){
            if(u.size() == k && !is_exist(str[j])) break;
            u[str[j]]++;
            j++;
        }

        answer = max(answer, j-i);

        u[str[i]]--;
        if(u[str[i]] == 0) u.erase(str[i]);
    }
    cout << answer << '\n';

    return 0;
}