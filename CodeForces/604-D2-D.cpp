#include <bits/stdc++.h>

using namespace std;
const int mod =1e9+7;
long long pow(long long b,long long p)
{
    if(p==0)
        return 1;
    long long sq=pow(b,p/2);
    sq=((sq%mod)*(sq%mod))%mod;
    if(p%2==1)
        sq=((sq%mod)*(b%mod))%mod;
    return sq;
}
int main()
{
    long long k,p;
    cin>>p>>k;
    if(k==0)
        cout<<pow(p,p-1);
    else if(k==1)
        cout<<pow(p,p);
    else
    {
        long long cnt=1,x=k;
        while(x!=1)
        {
            x=x*k%p;
            cnt++;
        }
        cout<<pow(p,(p-1)/cnt);
    }
    return 0;
}
