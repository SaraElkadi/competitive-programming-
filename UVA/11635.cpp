#include <bits/stdc++.h>

using namespace std;
const int OO=1e9+7;
struct edge {
    int from, to, w;

    edge(int from, int to, int w): from(from), to(to), w(w) {}

    bool operator < (const edge & e) const {
        return w > e.w;
    }
};
vector< vector< edge > > adj(10005);
vector<int> dij( int src)
{
    int n =adj.size();
    vector<int> dist(n, OO), prev(n, -1);
    dist[src] = 0;

    priority_queue<edge> q;
    q.push( edge(-1, src, 0) );

    while( !q.empty() ) {
        edge e = q.top();   q.pop();

        if(e.w > dist[e.to]) continue;

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
bool ff=0;
bool f[10005];
int ans,N;
void solve(int n,int cnt,vector<int> vis){
    vis[n]=1;
    vector<int> d=dij(n);
    if(d[N]<=600){
        ff=1;
        ans=min(cnt,ans);
        return ;
    }
    for(int i=0;i<d.size();i++){
        if(!vis[i]&&f[i]&&d[i]!=OO&&d[i]<=600)
             solve(i,cnt+1,vis);
    }
}
int main()
{
    int n,h,a,m,u,v,w;
    while(cin>>n&&n){
            ff=0;
            ans=OO;
        for(int i=0;i<10005;i++){
            f[i]=0;
            adj[i].clear();
        }
        cin>>h;
        for(int i=0;i<h;i++){
            cin>>a;
            f[a-1]=1;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            u--;v--;
            adj[u].push_back(edge{u,v,w});
            adj[v].push_back(edge{v,u,w});
        }
        vector<int> vis(10005,0);
        N=n-1;
       solve(0,0,vis);
        if(!ff)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
