#include <bits/stdc++.h>

using namespace std;
const int oo=1e9+10;
long long n,m,x,y,u,v,w;
vector<vector<long long>> adj(1005,vector<long long>(1005,oo));
long long t[1005],c[1005];
vector<vector<int> > d;
vector<int> dijkstra(long long src)
{
    vector<int> vis(1005,0),dist(1005,oo),prev(1005,-1);
    dist[src]=0;
    while(1)
    {
        long long val=oo,idx=-1;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]&&dist[i]<val)
                val=dist[i],idx=i;
        }
        if(idx==-1)
            break;
        vis[idx]=1;
        for(int i=0; i<n; i++)
        {
            val=dist[idx]+adj[idx][i];
            if(dist[i]>val)
               dist[i]=val,prev[i]=idx;
        }
    }
    return dist;
}
int dij(int src,int dest=-1)
{
    vector<int> vis(1005,0),dist(1005,oo),prev(1005,-1);
    dist[src]=0;
    while(1)
    {
        long long val=oo,idx=-1;
        for(int i=0; i<n; i++)
        {
            if(!vis[i]&&dist[i]<val)
                val=dist[i],idx=i;
        }
        if(idx==-1||idx==dest)
            break;
        vis[idx]=1;
        for(int i=0; i<n; i++)
        {
            val=dist[idx]+d[idx][i];
            if(dist[i]>val)
               dist[i]=val,prev[i]=idx;
        }
    }
    return dest==-1?-1:dist[dest];
}

int main()
{
    scanf("%d %d %d %d",&n,&m,&x,&y);
    x--,y--;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        u--,v--;
        adj[u][v]=min(adj[u][v],w);
        adj[v][u]=min(adj[v][u],w);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&t[i],&c[i]);
    }
    for(int i=0;i<n;i++){
        d.push_back(dijkstra(i));
        for(int j=0;j<d[i].size();j++){
            if(d[i][j]<=t[i])
                d[i][j]=c[i];
            else
                d[i][j]=oo;
        }
    }
    int ans=dij(x,y);
    if(ans!=oo)
      printf("%d",ans);
    else
        puts("-1");
    return 0;
}
