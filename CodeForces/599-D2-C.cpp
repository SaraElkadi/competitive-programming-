#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+5],mx[n+5],mn[n+5];
    mx[0]=0,mn[0]=0;;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        mx[i]=max(mx[i-1],a[i]);
    }
    mn[n]=a[n];
    mn[n+1]=2000000000;
    for(int i=n-1; i>=1; i--)
    {
        mn[i]=min(mn[i+1],a[i]);
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        if(mx[i]<=mn[i+1])
            ans++;

    }
    cout<<ans;
    return 0;
}
