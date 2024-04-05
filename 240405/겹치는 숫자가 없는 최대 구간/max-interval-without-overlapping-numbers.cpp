#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n); for(int& e: nums) cin >> e;

    unordered_set<int> cnt;
    function<bool(int)> contains = [&](int num){
        return cnt.find(num) != cnt.end();
    };

    int len = 0;
    int j=0;
    for(int i=0; i<n; ++i){
        while(j < n && !contains(nums[j])){
            cnt.insert(nums[j]);
            ++j;
        }
        len = max(len, j-i);
        cnt.erase(nums[i]);
    }
    cout << len << '\n';
    return 0;
}