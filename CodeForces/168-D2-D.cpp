#include <bits/stdc++.h>

using namespace std;
const int N=205;
int n,l,k;
double dp[N][N][N];
int p[N],a[N];
double prob(int idx,int c,int w)
{
    if(idx==n)
    {
        if(w>=l&&c>=0)
            return 1;
        return 0;
    }
    double &ret=dp[idx][c][w];
    if(ret==ret)
        return ret;
    ret=0;
    ret+=(p[idx]/100.0)*prob(idx+1,(a[idx]==-1?(c-1):min(c+a[idx],202)),w+1);
    ret+=(1-(p[idx]/100.0))*prob(idx+1,c,w);
    return ret;
}
int main()
{
    cin>>n>>l>>k;
    for(int i=0; i<n; i++)
        cin>>p[i];
    for(int i=0; i<n; i++)
        cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(12)<<prob(0,k,0);
    return 0;
}
