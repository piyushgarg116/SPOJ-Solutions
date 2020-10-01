#include<bits/stdc++.h>
using namespace std;
int main()
{long long int n,i;
cin>>n;long long int a[n];
for(i=0;i<n;i++)
{
	scanf("%lld",&a[i]);
}
sort(a,a+n);
for(i=0;i<n;i+=2)
{int flag=0;
	if(a[i]==a[i+1])
	flag=1;
	if(flag==0)
	{printf("%lld",a[i]);break;
	}
}
}
