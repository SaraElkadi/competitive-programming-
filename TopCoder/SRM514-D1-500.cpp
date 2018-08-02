#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod=1e9+7,N=10;
bool e[N][N],o[N][N];
int d[N][N];
long long dp[N][(1<<N)];

ll pow(ll b,ll p)
{
    if(!p)
        return 1ll;
    ll sq=pow(b,p/2)%mod;
    sq=(sq*sq)%mod;
    if(p%2==1)
        sq*=b;
    return sq%mod;
}
class MagicalGirlLevelTwoDivOne
{
public:
    int theCount(vector<string> g, int n, int m)
    {
        for(int i=0; i<g.size(); i++)
        {
            for(int j=0; j<g[0].size(); j++)
            {
                if(g[i][j]=='.')
                    d[i%n][j%m]++;
                else if((g[i][j]-'0')%2==0)
                    e[i%n][j%m]=1;
                else
                    o[i%n][j%m]=1;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++){
                if(e[i][j]&&o[i][j])
                    return 0;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int mask=0; mask<(1<<m); mask++)
            {
                if(__builtin_popcount(mask)%2){
                bool f=1;
                for(int j=0; j<m; j++)
                {
                    if((((mask>>j)&1)&&e[i][j])||(!((mask>>j)&1)&&o[i][j]))
                        f=0;
                }
                if(!f)
                    continue;
                long long cnt=1;
                for(int j=0; j<m; j++)
                {
                    if((mask>>j)&1) cnt=(cnt*pow(5ll,(ll)d[i][j]))%mod;
                    else cnt=(cnt*pow(4ll,(ll)d[i][j]))%mod;
                }
                if(i)
                {
                    for(int mask1=0; mask1<(1<<m); mask1++)
                    {
                        dp[i][mask^mask1]+=(dp[i-1][mask1]*cnt)%mod;
                        dp[i][mask^mask1]%=mod;
                    }
                }
                else
                    dp[i][mask]=cnt;
                }
            }
        }
        return dp[n-1][(1<<m)-1];
    }
};


