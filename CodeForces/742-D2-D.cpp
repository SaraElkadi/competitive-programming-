#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > v(1005);
vector<vector<int> > adj(1005);
vector<vector<pair<int,int> > >vv;
int w[1005],b[1005];
bool vis[1005];
int sumw,sumb;
int dfs(int n)
{
    vis[n]=1;
    v.push_back(make_pair(w[n],b[n]));
    sumw+=w[n];
    sumb+=b[n];
    for(int i=0; i<adj[n].size(); i++)
    {
        if(!vis[adj[n][i]])
        {
            dfs(adj[n][i]);
        }
    }
}
int mem[1005][1005];
int dp(int idx,int rem)
{
    if(idx==vv.size())
        return 0;
    int &res=mem[idx][rem];
    if(res!=-1)
        return res;
    res=0;
    for(int i=0; i<vv[idx].size(); i++)
    {
        if(rem>=vv[idx][i].first)
            res=max(res,dp(idx+1,rem-vv[idx][i].first)+vv[idx][i].second);
    }
    return mem[idx][rem]=res;
}
int main()
{
    int n,m,ww,x,y;
    cin>>n>>m>>ww;
    memset(mem,-1,sizeof mem);
    for(int i=1; i<=n; i++)
        cin>>w[i];
    for(int i=1; i<=n; i++)
        cin>>b[i];
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            v.clear();
            sumw=0;
            sumb=0;
            v.push_back(make_pair(0,0));
            dfs(i);
            if(v.size()>2)
            v.push_back(make_pair(sumw,sumb));
            vv.push_back(v);
        }
    }
    cout<<dp(0,ww);
    return 0;
}
