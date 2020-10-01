#include<bits/stdc++.h>
using namespace std;
int main()
{
	int p,f,m;
	cin>>p;
	while(p--)
	{int count=0;
		cin>>f>>m;int a[f];
		for(int i=0;i<f;i++)
		{
			cin>>a[i];
		}
		sort(a,a+f);
		for(int i=0;i<f;i++)
		{
		if(binary_search(a,a+f,m-a[i]))
		count++;
		}
		cout<<count/2<<"\n";
	}
}
