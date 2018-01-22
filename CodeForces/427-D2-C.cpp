#include<bits/stdc++.h>

using namespace std;
int n,m,a,b,c[100005];
bool vis[100005];
int l[100005],h[100005],cnt=1,mod=1000000007;
long long cost=0,ways=1;
vector<vector<int> > adj(100005);
vector<int> v;
void dfs(int x)
{
    l[x]=h[x]=cnt++;
    v.push_back(x);
    vis[x]=1;
    for(int i=0; i<adj[x].size(); i++)
    {
        if(!h[adj[x][i]])
            dfs(adj[x][i]);
        if(vis[adj[x][i]])
            l[x]=min(l[x],l[adj[x][i]]);
    }
    if(l[x]==h[x])
    {
        int mn=c[x],w=0;
        while(1)
        {
            int q=v.back();
            if(mn==c[q])
                w++;
            else if(mn>c[q])
            {
                mn=c[q];
                w=1;
            }
            vis[q]=0;
            v.pop_back();
            if(q==x) break;
        }
        cost+=mn;
        ways*=w;
        ways%=mod;
    }
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>c[i];
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1; i<=n; i++)
    {
        if(!h[i])
            dfs(i);
    }
    cout<<cost<<" "<<ways;

    return 0;
}
