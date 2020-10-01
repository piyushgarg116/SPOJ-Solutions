#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,tow,t,pow,count;
cin>>t;
while(t--)
{
	cin>>n>>tow>>pow;
	int a[n];
	count=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	while(a[i]>pow)
	{
		a[i]=a[i]-pow;
		count++;
	}
}if(count>=tow)
cout<<"YES\n";
else
cout<<"NO\n";
}

}
