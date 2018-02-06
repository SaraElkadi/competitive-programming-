#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,bool>> > adj(200005);
int a[200005],b[200005],c[200005];
bool vis[200005];
int dfs(int n)
{
    vis[n]=1;
    for(int i=0; i<adj[n].size(); i++)
    {
        if(!vis[adj[n][i].first])
        {
            if(adj[n][i].second==0)
                a[adj[n][i].first]+=a[n]+1;
            else
                a[adj[n][i].first]+=a[n];

            dfs(adj[n][i].first);
            
            if(adj[n][i].second==1)
                b[n]+=b[adj[n][i].first]+1;
            else
                b[n]+=b[adj[n][i].first];
        }
    }
}
void dfs1(int n)
{
    vis[n]=1;
    for(int i=0; i<adj[n].size(); i++)
    {
        if(!vis[adj[n][i].first])
        {
            if(adj[n][i].second==0)
            {
                c[adj[n][i].first]=c[n]+1;
            }
            else
                c[adj[n][i].first]=c[n]-1;
            dfs1(adj[n][i].first);
        }
    }
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d",&x,&y);
        x--,y--;
        adj[x].push_back(make_pair(y,0));
        adj[y].push_back(make_pair(x,1));
    }
    dfs(0);
    c[0]=b[0]+a[0];
    memset(vis,0,sizeof vis);
    dfs1(0);
    int mn=1000000000;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        if(c[i]<mn)
        {
            mn=c[i];
            v.clear();
            v.push_back(i+1);
        }
        else if(c[i]==mn)
            v.push_back(i+1);

    }
    sort(v.begin(),v.end());
    printf("%d\n",mn);
    for(int i=0; i<v.size(); i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}
