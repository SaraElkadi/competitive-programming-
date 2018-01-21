#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    if(k*3>n)
        cout<<-1;
    else{
      for(int i=0;i<n-3*k;i++)
        cout<<1<<" ";
      for(int i=1;i<=k;i++)
        cout<<i<<" "<<i<<" ";
      for(int i=1;i<=k;i++)
        cout<<i<<" ";
    }
    return 0;
}
