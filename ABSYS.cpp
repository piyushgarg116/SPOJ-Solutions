#include<bits/stdc++.h>
#include <string> 
using namespace std;
bool isNumber(string s) 
        { 
    for (int i = 0; i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
    } 
int main()
{
	int t;cin>>t;
	string a,b,c,d,e;
	while(t--)
	{
		cin>>a;
		cin>>b>>c>>d>>e;
		if(isNumber(a) && isNumber(c))
		{int m1 = stoi(a); 
    	int m2 = stoi(c); 
    	cout<<m1<<" + "<<m2<<" = "<<m1+m2<<"\n";
		    
		}
		else if(isNumber(a) && isNumber(e))
		{int m1 = stoi(a); 
    	int m2 = stoi(e); 
    	cout<<m1<<" + "<<m2-m1<<" = "<<m2<<"\n";
		    
		}
		else if(isNumber(c) && isNumber(e))
		{int m1 = stoi(c); 
    	int m2 = stoi(e); 
    	cout<<m2-m1<<" + "<<m1<<" = "<<m2<<"\n";
		    
		}
		
		
	}
}
