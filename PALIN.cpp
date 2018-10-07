#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define f first
#define s second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long int ll;

bool isPalin(string s)
{
	int i = 0, j = s.length()-1;
	while(i < j)
	{
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    clock_t start_s = clock();
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
    	string s;
    	cin >> s;
    	if(!isPalin(s))
    	{
    		int len = s.length();
    		int mid = (len+1)/2;
    		bool isLarge = false;
    		int lastNot9 = -1;
    		for(int i = 0; i < mid; ++i)
    			if(s[i] != '9')
    				lastNot9 = i;
    		if(lastNot9 != -1)
    		{
    			string ans = "";
    			for(int i = 0; i < mid; ++i)
    				ans += s[i];
    			bool falseAns = false;
    			int ptr1 = mid, ptr2;
    			if(len % 2 == 0)
    				ptr2 = mid-1;
    			else
    				ptr2 = mid-2;
    			for(; ptr1 < len && ptr2 >= 0; ++ptr1, --ptr2)
    			{
    				if(s[ptr2] > s[ptr1])
    				{
    					isLarge = true;
    					ans += s[ptr2];
    				}
    				else if(s[ptr2] == s[ptr1])
    					ans += s[ptr2];
    				else if(isLarge)
    					ans += s[ptr2];
    				else
    				{
    					falseAns = true;
    					break;
    				}
    			}
    			if(!falseAns)
    				cout << ans << endl;
    			else
    			{
    				int ptr1 = 0;
    				int ptr2 = len-1;
    				while(ptr1 <= ptr2)
    				{
    					if(ptr1 < lastNot9)
	    					s[ptr2] = s[ptr1];
    					else if(ptr1 == lastNot9)
    						s[ptr1] = s[ptr2] = s[ptr1]+1;
    					else
    						s[ptr1] = s[ptr2] = '0';
    					ptr1++;
    					ptr2--;
    				}
    				cout << s << endl;
    			}
    		}
    		else
    		{
    			for(int i = 0 ; i < len; ++i)
    				cout << '9';
    			cout << endl;
    		}
    		/*
    		ptr1 = 0;
    		ptr2 = len-1;
    		isLarge = false;
    		while(ptr1 <= ptr2)
    		{
    			if(isLarge)
    				ans[ptr2] = ans[ptr1] = '0';
    			else if(ans[ptr1] > s[ptr1])
    				isLarge = true;
    			ptr1++;
    			ptr2--;
    		}
    		cout << ans << endl;*/
    	}
    	else
    	{
    		int len = s.length();
    		if(len == 1)
    		{
    			if(s != "9")
    				cout << s[0]+1 << endl;	
    			else
    				cout << "11" << endl;
    			continue;
    		}
    		int mid = (len+1)/2;
    		int lastNot9 = -1;
    		for(int i = 0; i < mid; ++i)
    			if(s[i] != '9')
    				lastNot9 = i;
    		if(lastNot9 != -1)
    		{
    			int ptr1 = 0;
    			int ptr2 = len-1;
    			while(ptr1 <= ptr2)
    			{
    				if(ptr1 < lastNot9)
    				{

    				}
    				else if(ptr1 == lastNot9)
    					s[ptr1] = s[ptr2] = s[ptr1]+1;
    				else
    					s[ptr1] = s[ptr2] = '0';
    				ptr1++;
    				ptr2--;
    			}
    			cout << s << endl;
    		}
    		else
    		{
    			cout << '1';
    			for(int i = 0 ; i < len; ++i)
    			{
    				if(i != len-1)
    					cout << '0';
    				else
    					cout << '1' << endl;
    			}
    		}
    	}
    }
    #ifndef ONLINE_JUDGE
    clock_t stop_s = clock();
    cout << "Time Elapsed: " << ((stop_s-start_s)/double(CLOCKS_PER_SEC))*1000 << " ms" << endl;
    #endif
    return 0;
}
