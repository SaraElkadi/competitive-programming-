#include <bits/stdc++.h>

using namespace std;
#define sz(v)      ((int)((v).size()))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
typedef long long ll;
typedef vector<ll> vi;
const ll OO = 1e8;
const double EPS = (1e-7);

struct edge
{
    ll from, to, w;

    edge(ll from, ll to, ll w): from(from), to(to), w(w) {}

    bool operator < (const edge & e) const
    {
        return w > e.w;
    }
};

vector<ll> Dijkstra2(vector< vector< edge > > adjList, ll src) // O(E logV)
{
    ll n = sz(adjList);
    vi dist(n, OO), prev(n, -1);
    dist[src] = 0;

    priority_queue<edge> q;
    q.push( edge(-1, src, 0) );

    while( !q.empty() )
    {
        edge e = q.top();
        q.pop();

        if(e.w > dist[e.to]) continue;   // some other state reached better

        prev[ e.to ] = e.from;

        rep(j, adjList[e.to])
        {
            edge ne = adjList[e.to][j];
            if( dist[ne.to] > dist[ne.from] + ne.w )
            {
                ne.w = dist[ne.to] = dist[ne.from] + ne.w;
                q.push( ne );
            }
        }
    }
    return dist;
}
vector<vector<ll> > v(12);
ll dp[12][1<<12],s[12],ns;
ll solve(int cur,int st)
{
    if(st==0)
        return v[cur][s[ns-1]];
    if(dp[cur][st]!=-1)
        return dp[cur][st];
    ll &ret=dp[cur][st];
    ret=OO;
    for(int i=0; i<ns; i++)
    {
        if(st&(1<<i))
            ret=min(ret,solve(i,st-(1<<i))+v[cur][s[i]]);
    }
    return ret;
}
int main()
{
    // freopen("out.txt","w",stdout);
    int t,n,m,x,y,d;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<12; i++)
            v[i].clear();
        cin>>n>>m;
        vector<vector<edge>> adj(n+1);
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>d;
            adj[x].push_back({x,y,d});
            adj[y].push_back({y,x,d});
        }
        cin>>ns;
        for(int i=0; i<ns; i++)
            cin>>s[i];
        s[ns++]=0;
        for(int i=0; i<ns; i++)
        {
            v[i]=(Dijkstra2(adj,s[i]));
        }
        memset(dp,-1,sizeof dp);
        cout<<solve(ns-1,(1<<ns)-1)<<endl;
    }
    return 0;
}
