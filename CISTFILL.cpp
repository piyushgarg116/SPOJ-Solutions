#include <bits/stdc++.h>
using namespace std;
typedef double dbl;

class cis{
   public:
   dbl b,h,w,d;
};

dbl p(dbl val, cis *arr, int n){

   dbl ans=0;
   for(int i=0; i<n; i++){
    if(arr[i].b <val && arr[i].b+arr[i].h >val){
        ans+= (val-arr[i].b)*(arr[i].w)*(arr[i].d);
    }
    else if(arr[i].b<val && arr[i].b+arr[i].h<=val){
        ans+= (arr[i].h)*(arr[i].w)*(arr[i].d);
    }
   }
   return ans;
}

dbl bs(dbl lo, dbl hi, cis* arr, int n, dbl v){

    dbl mid= lo+ (hi-lo)/2;

    while(hi-lo>0.001){
        dbl ans= p(mid,arr,n);
        if(ans>=v)
            hi=mid;
        else
            lo=mid;
        mid=lo+ (hi-lo)/2;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        dbl vol=0;
        cis arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i].b >> arr[i].h >> arr[i].w >> arr[i].d;
            vol+= (arr[i].h)*(arr[i].w)*(arr[i].d);
        }

        dbl v;
        cin >> v;

        if(vol<v){
            cout << "OVERFLOW" << endl;
            continue;
        }
        //cout << p(3,arr,n) << endl;
        dbl ans= bs(0, 2*pow(10,9), arr, n,v);
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
