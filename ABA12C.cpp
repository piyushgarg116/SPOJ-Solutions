//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[105],n,k;
ll dp[105][105][105];
ll solve(ll frnd,ll wgt, ll idx)
{   if(wgt==0&&idx==k) return 0;
    if(idx==k&&wgt!=0) return INT_MAX;
    if(dp[frnd][wgt][idx]!=-1) return dp[frnd][wgt][idx];
    //dp[frnd][wgt][idx]=0;
    if(arr[idx]==-1||wgt<idx+1||frnd==0) return dp[frnd][wgt][idx]=solve(frnd,wgt,idx+1);
    else return dp[frnd][wgt][idx]=min(solve(frnd-1,wgt-(idx+1),idx)+(ll)arr[idx],solve(frnd,wgt,idx+1));
}
int main()
{
   ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<k;i++) cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        ll ans=solve(n,k,0);
        if(ans>=INT_MAX) cout<<-1<<endl;
        else 
        cout<<ans<<endl;
    }
}
