//This is the solution of the question named JNEXT on Spoj 

//problem link : https://www.spoj.com/problems/JNEXT/

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++)
            cin >> arr[i];

        bool v = next_permutation(arr, arr + n);

        if (v == false)
            cout << -1 << endl;

        else
        {
            for (i = 0; i < n; i++)
                cout << arr[i];

            cout << endl;
        }
    }
}
