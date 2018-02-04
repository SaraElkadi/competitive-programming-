#include <bits/stdc++.h>

using namespace std;
const long long oo=1e18+10;
long long n,m,x,y,u,v,w;
long long t[1005],c[1005];
vector<vector<long long> > d;
struct edge {
    long long from, to, w;

    edge(long long from, long long to, long long w): from(from), to(to), w(w) {}

    bool operator < (const edge & e) const {
        return w > e.w;
    }
};
vector<vector<edge> >adj(1005);
vector<long long> dijkstra(long long src)
{
    vector<long long> dist(1005,oo),prev(1005,-1);
    dist[src]=0;
    priority_queue<edge> q;
    q.push(edge(-1,src,0));
   while( !q.empty() ) {
        edge e = q.top();   q.pop();

        if(e.w > dist[e.to]) continue;   // some other state reached better

        prev[ e.to ] = e.from;

        for(int j=0;j<adj[e.to].size();j++) {
            edge ne = adj[e.to][j];
            if( dist[ne.to] > dist[ne.from] + ne.w ) {
                ne.w = dist[ne.to] = dist[ne.from] + ne.w;
                q.push( ne );
            }
        }
    }
    return dist;
}
long long dij(int src,int dest=-1)
{
    vector<long long> vis(1005,0),dist(1005,oo),prev(1005,-1);
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
    //cin>>n>>m>>x>>y;
    scanf("%lld %lld %lld %lld",&n,&m,&x,&y);
    x--,y--;
    for(int i=0; i<m; i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);
        u--,v--;
        adj[u].push_back(edge{u,v,w});
        adj[v].push_back(edge{v,u,w});
    }
    for(int i=0; i<n; i++)
    {
        scanf("%lld %lld",&t[i],&c[i]);
    }
    for( int i=0;i<n;i++){
        d.push_back(dijkstra(i));
        for(int j=0;j<d[i].size();j++){
            if(d[i][j]<=t[i])
                d[i][j]=c[i];
            else
                d[i][j]=oo;
        }
    }
    long long ans=dij(x,y);
    if(ans!=oo)
      printf("%lld",ans);
    else
        puts("-1");
    return 0;
}
