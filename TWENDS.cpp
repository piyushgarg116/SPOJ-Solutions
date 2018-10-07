#include <bits/stdc++.h>
using namespace std;

int findDpSum(int* arr, int l, int r, int** dp)
{
    if(r <= l)
        return 0;
    if(r-l == 1)
        return max(arr[l],arr[r]);
    if(dp[l][r] != -1)
        return dp[l][r];
    int opt1 = arr[l];
    if(arr[l+1] >= arr[r])
        opt1 += findDpSum(arr,l+2,r,dp);
    else
        opt1 += findDpSum(arr,l+1,r-1,dp);
    int opt2 = arr[r];
    if(arr[l] >= arr[r-1])
        opt2 += findDpSum(arr,l+1,r-1,dp);
    else
        opt2 += findDpSum(arr,l,r-2,dp);
    dp[l][r] = max(opt1,opt2);
    return dp[l][r];
}

int main()
{
    int n, testCase = 1;
    while(cin >> n && n != 0)
    {
        int arr[n], sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        int** dp = new int*[n+1];
        for(int i = 0 ; i <= n ; i++)
        {
            dp[i] = new int[n+1];
            for(int j = 0 ; j <= n ; j++)
                dp[i][j] = -1;
        }
        cout << "In game " << testCase++ << ", the greedy strategy might lose by as many as " << 2*findDpSum(arr,0,n-1,dp) - sum << " points." << endl;
    }
    return 0;
}
