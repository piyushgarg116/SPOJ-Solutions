#include <iostream>

using namespace std;
#define ll long long
#define mod 10000007
ll n,k,ans=1,a,b,sol;
ll modular(ll a,ll b)
{   ans=1;
    while(b!=0){
          if(b%2==1){ans=ans*a;
                      ans=ans%mod;}
                      a=a*a;
                      a=a%mod;
                      b=b/2; }
                      return ans;
}
int main()
{   while(1){

    cin>>n>>k;
    if(n==0&&k==0) break;
    else {  sol=2*modular(n-1,k)%mod+modular(n,k)%mod+2*modular(n-1,n-1)%mod+modular(n,n)%mod;
            cout<<sol%mod<<endl;
    }
}}
