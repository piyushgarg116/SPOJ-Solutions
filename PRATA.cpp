#include <iostream>
using namespace std;
bool canmakepratas(int ranks[],int p,int n,int mid)
{    int cnt = 0;
    for(int i=0;i<n;i++){
        //for each cook count the pratas
        int c = 0;
        int time = mid;
        int perpratas = ranks[i]; // time taken to cook each pratas by ith cook
        while(time > 0){
            time = time - perpratas;
            if( time >= 0){
                c += 1;
                perpratas  += ranks[i];
            }
        }
        cnt += c;
        if(cnt >= p)
            return true;
    }
 
    return false;
}
int minimumtime(int ranks[],int p,int n)
{  
int ans=0;
 
	int s=0;
	int e=10000007;
	while(s<=e)
	{    
		int mid=(s+e)/2;
		if(canmakepratas(ranks,p,n,mid))
		{    ans=mid;
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	return ans;
}
 
int main() {
	int p;
	int n;
	int ranks[1000];
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>p;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>ranks[i];
		}
		cout<<minimumtime(ranks,p,n)<<endl;
	}
	return 0;
}
 