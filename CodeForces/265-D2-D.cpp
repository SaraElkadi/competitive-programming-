#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],d[100005]= {0};
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
    {
        int mx=0;
        for(int j=1; j*j<=a[i]; j++)
        {
            if(a[i]%j==0)
            {
                if(j!=1)mx=max(mx,d[j]);
                if(a[i]/j!=1)mx=max(mx,d[a[i]/j]);
            }
        }
        for(int j=1; j*j<=a[i]; j++)
        {
            if(a[i]%j==0)
            {
                if(j!=1) d[j]=mx+1;
                if(a[i]/j!=1)d[a[i]/j]=mx+1;
            }
        }
    }
    int mx=0;
    for(int i=1; i<=n; i++)
    {
        mx=max(mx,d[i]);
    }
    if(mx==0)
        cout<<1;
    else
        cout<<mx;
    return 0;
}
