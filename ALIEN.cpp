#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        ll b;
        cin >> n >> b;
        ll a[n+1];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        a[n]=INT_MAX;
        int i=0,count=0;
        ll temp=0;
        while(temp+a[i]<=b){
            temp+=a[i];
            i++;
            count++;
        }

        ll anssum=temp;
        int anscount= count,k=0;
        temp-=a[k];
        k++;
        count--;
        for(; i<=n; i++){
            if(temp+a[i]<=b){
            temp+=a[i];
            count++;
            }
            else{
                i--;
                if(count>anscount){
                    anscount=count;
                    anssum=temp;
                }
                else if(count==anscount){
                    if(temp<anssum){
                        anssum=temp;
                    }
                }
                count--;
                temp-= a[k];
                k++;
            }
        }

        cout << anssum << " " << anscount << endl;

    }
    return 0;
}
