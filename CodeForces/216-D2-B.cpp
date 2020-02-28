#include <bits/stdc++.h>

using namespace std;
const int N=105;
vector<vector<int>> adj(N);
vector<int> vis(N);
int cnt=0;

bool isCycl(int n,int p)
{
    vis[n]=1;
    cnt++;
    for(int i=0; i<adj[n].size(); i++)
    {
        if(!vis[adj[n][i]])
        {
            if(isCycl(adj[n][i],n))
                return 1;
        }
        else if(adj[n][i]!=p)
            return 1;
    }
    return 0;
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        cnt=0;
        if(!vis[i])
        {
            if(isCycl(i,-1)&&cnt%2==1){
                ans++;
            }
        }
    }
    if((n-ans)%2)
        ans++;
    cout<<ans;
    return 0;
}
