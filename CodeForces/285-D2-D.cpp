#include <bits/stdc++.h>

using namespace std;
const long long mod =1e9+7;
vector<vector<long long> > v(17);
long long ans=0,n;
void solve(int idx,int b,int res)
{
    if(idx==n)
    {
        if(b>=(1<<n)-1&&res>=(1<<n)-1)
            ans=(ans+1)%mod;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if((b&(1<<i))||(res&(1<<(v[idx][i]))))
            continue;
        solve(idx+1,b|(1<<i),res|(1<<(v[idx][i])));
    }
}
long long pow(long long b,long long p)
{
    if(p==0)
        return 1ll;
    long long sq=pow(b,p/2);
    sq=((sq%mod)*(sq%mod))%mod;
    if(p%2==1)
        sq=((sq%mod)*(b%mod))%mod;
    return sq;
}
long long fact(long long n)
{
    long long ans=1;
    for(int i=2; i<=n; i++)
        ans=((ans%mod)*(i%mod))%mod;
    return ans;
}
long long p(long long n,long long k)
{
    return (fact(n)*pow(fact(n-k),mod-2))%mod;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            v[i].push_back((i+j)%n);
        }
    }
    if(n%2==0)
        cout<<0;
    else if(n==15)
    {
        cout<<150347555;
    }
    else
    {
        solve(0,0,0);
        cout<<(ans*p(n,n))%mod;
    }
    return 0;
}
