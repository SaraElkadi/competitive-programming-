#include<bits/stdc++.h>

using namespace std;
vector<bool> vis(100005,0);
vector<vector<int> > adj(100005);
int a[100005];
vector<int> va,vb;
bool f=1;
void dfs(int n)
{
    vis[n]=1;
    if(a[n]==1)
        va.push_back(n);
    else if (a[n]==0)
        vb.push_back(n);
    for(int i=0; i<adj[n].size(); i++)
    {
        if(a[n]==a[adj[n][i]]){
            f=0;
        }
        else if(!vis[adj[n][i]])
        {
            a[adj[n][i]]=!a[n];
            dfs(adj[n][i]);
        }
    }
}
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    memset(a,-1,sizeof a);
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
            f=1;
            a[i]=1;
            dfs(i);
            if(!f){
                break;
            }
        }
    }
    if(!f)
        cout<<-1;
    else
    {
        cout<<va.size()<<endl;
        for(int i=0; i<va.size(); i++)
            cout<<va[i]<<" ";
        cout<<endl;
        cout<<vb.size()<<endl;
        for(int i=0; i<vb.size(); i++)
            cout<<vb[i]<<" ";

    }
    return 0;
}
