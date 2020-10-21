#include <iostream>
#include<cmath>
#define ll long long
using namespace std;
bool isPrime(ll int p)
{
    if(p==1)
    {
        return false;
    }
    if(p==2)
    {
        return true;
    }
    if(p%2==0)
    {
        return false;
    }
	for(int i=3;i<sqrt(p)+1;i+=2)
	{
		if(p%i==0)
		{return false;
		}
	}
    
	return true;
}
 
int main() {
	// your code goes here
	ll int m,n,t;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		for(int i=m;i<=n;i++)
		{
			if(isPrime(i))
			{
				cout<<i<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
} 