#include <bits/stdc++.h>
using namespace std;
int main()
{
    float a, b, c;
    while(1)
    {
        cin>>a>>b>>c;
        if(a==0 && b==0 && c==0)
        {
            break;
        }
        float ap=b-a;
        float gp=b/a;
        if((c-b)==ap)
        {
            cout<<"AP "<<a+3*ap<<endl;
        }
        else if(b*b==a*c)
        {
            cout<<"GP "<<a*pow(gp,3)<<endl;
        }
    }
    return 0;
}