#include <iostream>
using namespace std;
void formEulers(int arr[], int n)
{
    for(int i=2; i<=n; i++)
    {
        if(arr[i]==i)
        {
            float prod= (float)(1-(1.0/i));

            for(int j=2*i; j<=n; j+=i)
            {
                arr[j]=(int)(arr[j]*(prod));
            }
            arr[i]=i-1;
        }
    }
    return;
}

int main()
{
    int n=1000000,num,t;
    int *arr= new int[n+1];
    for(int i=0; i<=n; i++)
    {
        arr[i]=i;
    }
    formEulers(arr,n);
    cin >> t;
    while(t--)
    {
        cin >> num;
        cout << arr[num] << endl;
    }

    return 0;
}
