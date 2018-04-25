#include <bits/stdc++.h>

using namespace std;
const long long OO=1e18+7;
const int N=1e5+5;
long long ss[N];
vector<pair<int,int>> t;
struct edge
{
    int from, to, w;

    edge(int from, int to, int w): from(from), to(to), w(w) {}

    bool operator < (const edge & e) const
    {
        return w > e.w;
    }
};

vector< vector< edge > > adj(N);
vector<long long> dij( int src)
{
    int n =adj.size();
    vector<long long> dist(n, OO), prev(n, -1);
    dist[src] = 0;

    priority_queue<edge> q;
    q.push( edge(-1, src, 0) );

    while( !q.empty() )
    {
        edge e = q.top();
        q.pop();

        if(e.w > dist[e.to]) continue;

        prev[ e.to ] = e.from;

        for(int j=0; j<adj[e.to].size(); j++)
        {
            edge ne = adj[e.to][j];
            if( dist[ne.to] > dist[ne.from] + ne.w )
            {
                ne.w = dist[ne.to] = dist[ne.from] + ne.w;
                ss[ne.to]=1;
                q.push( ne );
            }
            else if( dist[ne.to] == dist[ne.from] + ne.w )
                ss[ne.to]++;
        }
    }
    return dist;
}


int main()
{
    long long n,m,k,u,v,w;
    cin>>n>>m>>k;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back(edge {u,v,w});
        adj[v].push_back(edge {v,u,w});
    }
    for(int i=0; i<k; i++)
    {
        cin>>u>>w;
        u--;
        t.push_back(make_pair(u,w));
        adj[0].push_back(edge {0,u,w});
        adj[u].push_back(edge {u,0,w});
    }
    int ans=0;
    vector<long long> d=dij(0);
    for(int i=0; i<k; i++)
    {
        if(t[i].second>d[t[i].first])
            ans++;
        else if(ss[t[i].first]>1)
        {
            ss[t[i].first]--;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
