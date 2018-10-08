#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000005];
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll k;
    cin>>k;
    deque <ll> G;

    for(ll i=0;i<k;i++)
        {
            while(!G.empty()&&arr[i]>=arr[G.back()])
                 G.pop_back();
            G.push_back(i);
        }
   for(ll i=k;i<n;i++)
   {
       cout<<arr[G.front()]<<" ";
       while(!G.empty()&&G.front()<=i-k)
        G.pop_front();
       while(!G.empty()&&arr[G.back()]<=arr[i])
        G.pop_back();
       G.push_back(i);
   }
   cout<<arr[G.front()]<<endl;
}
