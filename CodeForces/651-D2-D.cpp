#include <bits/stdc++.h>

using namespace std;
int n,a,b,t;
int h[500005]= {0};
bool solve(int mid)
{
    for(int i=0; i<mid; i++)
    {
        int s=(h[mid-1-i]+(h[n-1]-h[n-1-i]))*b+mid+(mid-1)*a;
        s+=min(i*a,(mid-1-i)*a);
        if(s<=t)
            return 1;
    }
    return 0;
}
int main()
{
    string s;
    cin>>n>>a>>b>>t>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='w')
            h[i]=1;
        if(i>0)
            h[i]+=h[i-1];
    }
    int l=0,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(solve(mid))
        {
            l=mid+1,ans=max(ans,mid);
        }
        else
            r=mid-1;
    }
    cout<<ans;
    return 0;
}
