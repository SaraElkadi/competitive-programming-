#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll c(ll n,ll k)
{
    ll ans=1;
    for(ll i=n-k+1; i<=n; i++)
    {
        ans*=i;
        ans/=(i-(n-k));
    }
    return ans;
}
ll f(ll n,ll k)
{
    ll ret=0,x=n;
    for(int i=63; i>=0&&k>=0; i--)
    {
        if((n>>i)&1)
            ret+=c(i,k--);
    }
    return ret;
}

int main()
{
    ll m,k;
    cin>>m>>k;
    ll l=1,h=(ll)1e18;
    while(l<h)
    {
        ll mid=l+(h-l)/2;
        if(f(2*mid,k)-f(mid,k)<m)
            l=mid+1;
        else
            h=mid;
    }
    cout<<l<<endl;
    return 0;
}
