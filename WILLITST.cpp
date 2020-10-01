#include<bits/stdc++.h>
using namespace std;
unsigned long long int n;
bool fun(unsigned long long int k)
{
	if(k==0)
	return false;
	return(ceil(log2(k))==floor(log2(k)));
}
int main()
{
	bool m;
	cin>>n;
	m=fun(n) ?cout<<"TAK" :cout<<"NIE";
	return 0;
}
