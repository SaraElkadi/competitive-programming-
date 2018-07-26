#include <bits/stdc++.h>

using namespace std;
const long long mod=1e9+7;
const int MAX=1e5;
long long n,k;
long long dp[MAX+5];
int solve(int idx){
if(idx==0)
    return 1;
long long &ret=dp[idx];
if(ret!=-1)
    return ret;
ret=0;
ret=solve(idx-1)%mod;
if(idx-k>=0)
    ret+=solve(idx-k)%mod;
ret%=mod;
return ret;
}

int main()
{
    long long a,b;
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    solve(100001);
    dp[0]=0;
    for(int i=1;i<=MAX;i++)
        dp[i]=((dp[i]%mod)+(dp[i-1]%mod))%mod;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+mod)%mod<<endl;
    }
    return 0;
}
