//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{   

   ll arr[]={	2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161,
            27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 
            279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921};
    ll t;
    cin>>t;
    ll sz=sizeof(arr)/sizeof(arr[0]);
    while(t--)
    {
       ll a,b,ct=0;
        cin>>a>>b;
        for(int i=0;i<sz;i++) if(arr[i]>=a&&arr[i]<=b) ct++;
            cout<<ct<<endl;
        
    }
}
