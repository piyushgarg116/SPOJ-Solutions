#include <iostream>
#include<algorithm>
#define ll long long
 
using namespace std;
bool canchop(ll int n,ll int m,ll int heights[],ll int mid)
{
	
	ll int length=0;
	for(int i=0;i<n;i++)
	{
		if(length+(heights[i]-mid)<m)
		{
			if(heights[i]<mid)
            {
                
            }
            else{
			length+=(heights[i]-mid);}
		}
		else
		{     
        
            return true;
        
		    
		}
	}
	return false;
}
int main() {
	// your code goes here
	ll int n,m,ans=0;
	ll int lar=0;
	ll int heights[1000000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>heights[i];
		if(lar<heights[i])
		{
			lar=heights[i];
		}
	}
	
	int s=0;
	ll int e=lar;
	while(s<=e)
	{
		ll int mid=s+((e-s)/2);
		if(canchop(n,m,heights,mid))
		{   ans=mid;
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
} 