#include <bits/stdc++.h>
using namespace std;
//std::cin
vector<long long int>* formPrime(long long int n)
{
     bool *primes= new bool[n+1];
     memset(primes, true, (n+1)*sizeof(bool));
     primes[0]=false;
     primes[1]=false;
     for(long long int i=2; i*i<=n; i++)
     {
       if(primes[i])
       {
         for(long long int j=i*i; j<=n; j+=i)
              primes[j]=false;
       }
     }

     vector<long long int> *ans= new vector<long long int>();
     ans->push_back(2);
     for(long long int i=3; i<=n; i+=2){
         if(primes[i])
         ans->push_back(i);
     }
     delete []primes;
     return ans;
}

long long int etf(long long int n, vector<long long int> *ans)
{
    long long int num=n;
    for(long long int i=0; ans->at(i)*ans->at(i)<=n; i++){
        if(n%ans->at(i)==0){
            num= (num*(ans->at(i)-1))/ans->at(i);
            //cout << "num" << ans->at(i)<< " " << num << endl;
            while(n%ans->at(i)==0){
                n/= ans->at(i);
            }
             //cout << "num" << ans->at(i)<< " " << num << endl;
        }
     }
    if(n==1)
    return num;
    else{
        return (num*(n-1))/n;
    }
}

int main()
{
    long long int n;
    vector<long long int> *ans= formPrime(100000);
    while(scanf("%lld", &n)!=EOF)
    {
        cout << etf(n,ans)/2 << endl;
    }
    return 0;
}
