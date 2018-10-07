#include<bits/stdc++.h>
using namespace std;

long long int findMax(long long int minDist, long long int maxDist, long long int cows, long long int ans, long long int* position, long long int n)
{
  if(minDist > maxDist)
    return ans;
  long long int temp = cows;
  long long int midDist = (minDist + maxDist)/2;
  long long int lastPlaced = 0;
  long long int currIndex = 1;
  bool flag = true;
  temp--;
  while(temp > 0)
  {
    if(currIndex == n)
    {
      flag = false;
      break;
    }
    else
    {
      if(position[currIndex]-position[lastPlaced] >= midDist)
      {
        temp--;
        lastPlaced = currIndex++;
      }
      else
        currIndex++;
    }
  }
  if(temp==0)
    flag = true;
  if(flag)
    return findMax(midDist+1,maxDist,cows,midDist,position,n);
  else
    return findMax(minDist,midDist-1,cows,ans,position,n);
}
int main() 
{
  int tc;
  cin >> tc;
  while(tc--)
  {
    long long int n , c;
    cin >> n >> c;
    long long int* position = new long long int[n];
    for(long long int i = 0 ; i < n ; i++)
      cin >> position[i];
    sort(position,position+n);
    long long int maxDist = position[n-1] - position[0];
    cout << findMax(0,maxDist,c,0,position,n) << endl;
  }
}
