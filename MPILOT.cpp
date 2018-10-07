#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define f first
#define s second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long int ll;

pii arr[10001];
ll dp[10001][5001];

ll minSal(int ind, int cap, int n)
{
	if(n == 0)
		return 0;
	int ass = ind-cap-1;
	if(dp[n][cap] != -1)
		return dp[n][cap];
	if(ass == cap)
		return dp[n][cap] = arr[ind].s+minSal(ind+1,cap,n-1);
	if(ass-cap == n)
		return dp[n][cap] = arr[ind].f+minSal(ind+1,cap+1,n-1);
	return dp[n][cap] = min(arr[ind].s+minSal(ind+1,cap,n-1),arr[ind].f+minSal(ind+1,cap+1,n-1));
}

int main()
{
    #ifndef ONLINE_JUDGE	
    clock_t start_s = clock();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    	cin >> arr[i].f >> arr[i].s;
    memset(dp,-1,sizeof(dp));
    cout << minSal(1,0,n);
    #ifndef ONLINE_JUDGE
    clock_t stop_s = clock();
    cout << "Time Elapsed: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << " sec" << endl;
    #endif
    return 0;
}
