#include <bits/stdc++.h>
using namespace std;

int arr[100'000];

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    
    sort(arr, arr + n);

    int i=0, j=n-1;
    int answer = INT_MAX;

    while(i < j){
        int sum = arr[i] + arr[j];
        
        if(sum == 0){
            answer = 0;
            break;
        }

        answer = min(answer, abs(sum));
        
        if(sum < 0) ++i;
        else --j;     
    }

    cout << answer << '\n';

    return 0;
}