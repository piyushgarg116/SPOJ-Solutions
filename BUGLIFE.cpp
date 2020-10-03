#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define endl "\n"
using namespace std;
vector<ll>arr[2001];
ll vis[2001],col[2001];
bool dfs(ll node, ll c){
	vis[node]=1;
	col[node]=c;
	for(ll child:arr[node]){
		if(vis[child]==0){
			bool res=dfs(child,c^1);
			if(res==false){
			   return false;
		    }
		}
		else{
			if(col[node]==col[child]){
				return false;
			}
		}
	}
	return true;
}
void solve(){
    //input
    ll t=1;
    cin>>t;
    for(ll tc=1;tc<=t;tc++){
       ll n,m,a,b;
       cin>>n>>m;
       ll i;
       for(i=1;i<=n;i++){
		   arr[i].clear();
		   vis[i]=0;
	   }
       for(i=1;i<=m;i++){
		   cin>>a>>b;
		   arr[a].pb(b);
		   arr[b].pb(a);
		}
		bool flag=true;
		for(i=1;i<=n;i++){
			if(vis[i]==0){
				bool res=dfs(i,0);
				if(res==false)flag=false;
			}
		}
		cout<<"Scenario #"<<tc<<":"<<endl;
		if(flag==false){
			cout<<"Suspicious bugs found!"<<endl;
		}
		else{
			cout<<"No suspicious bugs found!"<<endl;
		}
    }
}
int main()
{
    fio;
    solve();
}
 
