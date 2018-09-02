#include <bits/stdc++.h>

using namespace std;

const int N=104;
double dp[N][N][N];
int x;

double solve(int r,int s,int p)
{
    if(x==0)
    {
        if(!s&&!p)
            return 1;
        if(!r)
            return 0;
    }
    if(x==1)
    {
        if(!r&&!p)
            return 1;
        if(!s)
            return 0;
    }
    if(x==2)
    {
        if(!r&&!s)
            return 1;
        if(!p)
            return 0;
    }
    double &ret=dp[r][s][p];
    if(ret==ret)
        return ret;
    ret=0;
    double q=(r*s+r*p+s*p);
    if(r>0)
        ret+=(p*r)/q*solve(r-1,s,p);
    if(s>0)
        ret+=(r*s)/q*solve(r,s-1,p);
    if(p>0)
        ret+=(s*p)/q*solve(r,s,p-1);
    return ret;
}

int main()
{
    int r,s,p;
    cin>>r>>s>>p;
    for(x=0; x<3; x++)
    {
        memset(dp,-1,sizeof dp);
        cout<<fixed<<setprecision(12)<<solve(r,s,p)<<" ";
    }
    return 0;
}
