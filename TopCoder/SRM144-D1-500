#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<pair<ll,string>> name;
vector<ll> n(55),k(55);
vector<bool>S(55),q(55);
int sz;
ll dp[10][105];
ll pow(ll b,ll p)
{
    if(!p)
        return 1;
    ll sq=pow(b,p/2);
    sq*=sq;
    if(p%2==1)
        sq*=b;
    return sq;
}
ll p(ll n,ll k)
{
    ll res=1;
    for(int i=n; i>n-k; i--)
        res*=i;
    return res;
}
ll solve1(ll n,ll k,ll last)
{
    if(k==0)
        return 1;
    ll &ret=dp[k][last];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=last; i<=n; i++)
        ret+=solve1(n,k-1,i);
    return ret;
}
ll solve2(ll n,ll k,ll last)
{
    if(k==0)
        return 1;
    if(last==n)
        return 0;
    ll &ret=dp[k][last];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=last+1; i<=n; i++)
        ret+=solve2(n,k-1,i);
    return ret;
}
class Lottery
{
public:
    vector<string> sortByOdds(vector<string> rules)
    {
        sz=rules.size();
        char x,y;
        string s;
        for(int i=0; i<sz; i++)
        {
            name.push_back(make_pair(0,""));
            for(int j=0; j<rules[i].size(); j++)
            {
                while(rules[i][j]!=':')
                {
                    name.back().second+=rules[i][j];
                    j++;
                }
                s=rules[i].substr(j+1);
                break;
            }
            stringstream ss(s);

            ss>>n[i]>>k[i]>>x>>y;
            if(x=='F')
                S[i]=0;
            else
                S[i]=1;
            if(y=='F')
                q[i]=0;
            else
                q[i]=1;
        }

        for(int i=0; i<sz; i++)
        {
            memset(dp,-1,sizeof dp);
            if(!S[i]&&!q[i])
                name[i].first=pow(n[i],k[i]);
            else if(!S[i]&&q[i])
                name[i].first=p(n[i],k[i]);
            else if(S[i]&&!q[i])
                name[i].first=solve1(n[i],k[i],1);
            else
                name[i].first=solve2(n[i],k[i],0);
        }
        sort(name.begin(),name.end());
        vector<string> ans;
        for(int i=0; i<sz; i++)
            ans.push_back(name[i].second);
        return ans;
    }
};

