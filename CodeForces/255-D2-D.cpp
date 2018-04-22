#include <bits/stdc++.h>

using namespace std;
long long sol(long long n)
{
    return n*(n+1)/2;
}
long long n,x,y,c;
long long check(long long m)
{
    long long k=m*m+(m-1)*(m-1);
    long long k1=max(0ll,(m-1)-(n-x));
    long long k2=max(0ll,m-x);
    long long k3=max(0ll,(m-1)-(n-y));
    long long k4=max(0ll,m-y);
    k-=k1*k1;
    k-=k2*k2;
    k-=k3*k3;
    k-=k4*k4;
    k1=max(0ll,m-x-y);
    k2=max(0ll,(m-1)-x-(n-y));
    k3=max(0ll,(m-1)-(n-x)-y);
    k4=max(0ll,(m-1)-(n-x)-(n-y)-1);
    k+=sol(k1)+sol(k2)+sol(k3)+sol(k4);
    if(k>=c)
        return 1;
    return 0;
}

int main()
{
    cin>>n>>x>>y>>c;
    int l=0,r=1e9,ans=1e9;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
            ans=min(ans,mid),r=mid-1;
        else
            l=mid+1;
    }
    cout<<max(ans-1,0);
    return 0;
}
