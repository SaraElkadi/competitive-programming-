#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >adj(100005);
bool vis[100005],used[100005];
int a[100005],p[100005];
vector<int> v,ans;
void dfs(int n)
{
    if(vis[n])
        return ;
    vis[n]=1;
    for(int i=0; i<adj[n].size(); i++)
    {
        dfs(adj[n][i]);
    }
    v.push_back(n);
}
void dfs1(int n,int x)
{
    if(p[n]!=-1)
        return ;
    p[n]=x;
    for(int i=0; i<adj[n].size(); i++)
    {
       dfs1(adj[n][i],x);
    }
}
int main()
{
    int n,m,x,y;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&x,&y);
        x-- ,y--;
        adj[x].push_back(y);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
        used[a[i]]=1;
    }
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    memset(p,-1,sizeof p);
    vector<int> ans;
    for(int i=0; i<n; i++)
    {
       if(used[v[i]]){
         dfs1(v[i],v[i]);
         ans.push_back(v[i]);
       }
    }
    for(int i=0;i<n;i++){
        if(p[i]!=a[i]){
            cout<<-1;
            return 0;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<endl;
    }
    return 0;
}
