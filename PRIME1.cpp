#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<bool> segmentedSieve(long long L, long long R) {
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll m, n;
        cin>>m>>n;
        //isPrime(m,n);
        vector<bool> v=segmentedSieve(m,n);
        for(int i=m;i<=n;i++)
        {
            if(v[i-m]==true)
            {
                cout<<i<<endl;
            }
        }
    }
    return 0;
}