#include <bits/stdc++.h>
#define inf 1000000000
#define MAXN 500000
 
using namespace std;
 
long long a[MAXN+1];
set<long long> exists;
 
void precalculate_ak() {
    for (int i = 1; i <= MAXN; ++i) {
        if (a[i-1] - i > 0 && exists.find(a[i-1] - i) == exists.end()) a[i] = a[i-1] - i;
        else a[i] = a[i-1] + i;
        exists.insert(a[i]);
    }
}
 
int main()
{
    precalculate_ak();
 
    int k;
    scanf("%d", &k);
 
    while(k != -1) {
        printf("%lld\n", a[k]);
        scanf("%d", &k);
    }
 
    return 0;
}
