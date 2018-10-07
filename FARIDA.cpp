#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fun(ll *arr, int n){

    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    if(n==2){
        return max(arr[0], arr[1]);
    }
    if(n==3){
        return max(arr[2]+arr[0], arr[1]);
    }

    ll ans=LONG_MIN;

    ll *dp= new ll[n];
    for(int i=0; i<n; i++){
        dp[i]=0;
    }

    dp[n-1]=arr[n-1];
    dp[n-2]=arr[n-2];
    dp[n-3]=arr[n-3]+arr[n-1];

    for(int i=n-4; i>=0; i--){
        dp[i]= arr[i]+max(dp[i+2], dp[i+3]);
    }

    for(int i=0; i<n; i++){
        ans= max(ans, dp[i]);
    }
    delete dp;
    return ans;
}

int main()
{
    int t,tc=1;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        ll *arr= new ll[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        cout << "Case " << tc <<": " << fun(arr,n) << endl;
        tc++;
        delete arr;
    }
    return 0;
}
