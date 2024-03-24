#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    map<string, int> dict;
    for(int i=0; i<n; ++i){
        string word; cin >> word;
        dict[word]++;
    }
    for(auto it = begin(dict); it != end(dict); ++it){
        cout << it->first << " " << it->second << '\n';
    }

    return 0;
}