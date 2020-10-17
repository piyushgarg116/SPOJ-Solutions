#include <bits/stdc++.h>
using namespace std;
int Preced(char check)
{
    switch(check)
    {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
    }
    return 0;
}
bool isOperator(char check)
{
    if(check=='+' || check=='-' || check=='*' || check=='/' || check=='^')
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string in;
        cin>>in;
        stack<char> st;
        string ans="";
        for(int i=0;i<in.length();i++)
        {
            if(in[i]=='(')
            {
                st.push(in[i]);
            }
            else if(in[i]==')')
            {
                while(st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(isOperator(in[i]))
            {
                while(Preced(st.top())>=Preced(in[i]))
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(in[i]);
            }
            else
            {
                ans+=in[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}