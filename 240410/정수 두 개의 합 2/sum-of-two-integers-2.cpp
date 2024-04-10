#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int arr[100'001] = {0, }; 
    for(int i=1; i<=n; ++i)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    
    int cnt = 0;
    int j = n;
    for(int i=1; i<=n; ++i){
        while(j > 1 && arr[i] + arr[j] > k)
            --j;
        if(j <= i)
            break;
        cnt += j-i;
    }
    cout << cnt << '\n';
    return 0;
}