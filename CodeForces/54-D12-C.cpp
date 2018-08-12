#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

typedef long long ll;
ll p10[19],l[1005],r[1005];
ll N,K;
double dp[1005][1005];

ll num(ll l,ll r)
{
    ll d=floor(log10(l)),ans=0;

    while(l<=r)
    {
        if(l>=2*p10[d]);
        else if(2*p10[d]<=r)
            ans+=(2*p10[d]-l);
        else
            ans+=(r-l+1);
        if(d==18)
            break;
        d++;
        l=p10[d];
    }
    return ans;
}

double prob(int i,int k)
{
    if(i==N)
    {
        if(k*100>=N*K)
            return 1;
        return 0;
    }
    double &ret=dp[i][k];
    if(ret==ret)
        return ret;
    ret=0;
    ll n=num(l[i],r[i]);
    ret+=((double)n/(r[i]-l[i]+1))*prob(i+1,k+1);
    ret+=((double)(r[i]-l[i]+1-n)/(r[i]-l[i]+1))*prob(i+1,k);
    return ret;
}
int main()
{
    p10[0]=1;
    for(int i=1; i<19; i++)
        p10[i]=p10[i-1]*10;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>l[i]>>r[i];
    }
    cin>>K;
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(15)<<prob(0,0);
    return 0;
}
