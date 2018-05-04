/*apply dijikstra on each node that have hotel at and store the edge between the two nodes
if the shortest path between the nodes less than 600 at a new adjlist array 
and then apply bfs on the new adjlist array to get the shortest path with minimum booking hotels. */

#include <bits/stdc++.h>

using namespace std;
const int OO=1e9+7;
const int N=10005;
int n,h,a,m,u,x,y,w;

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
vector<vector<int> > v(N);
bool vis[N];

vector<int> dij( int src)
{
    int n =adj.size();
    vector<int> dist(n, OO), prev(n, -1);
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
                q.push( ne );
            }
        }
    }
    return dist;
}

int bfs()
{
    queue<int> q;
    q.push(1);
    int dep = 0, sz = 1;
    for (; !q.empty(); ++dep, sz = q.size())
    {
        while (sz--)
        {
            int c = q.front();
            q.pop();
            if (c == n)
            {
                return dep-1;

            }
            for (int i = 0; i < v[c].size(); i++)
                if (!vis[v[c][i]])
                    vis[v[c][i]] = 1, q.push(v[c][i]);
        }
    }
    return -1;
}
int main()
{
    while(cin>>n&&n)
    {
        vector<int> s;
        for(int i=0; i<N; i++)
        {
            vis[i]=0;
            adj[i].clear();
            v[i].clear();
        }
        cin>>h;
        for(int i=0; i<h; i++)
        {
            cin>>a;
            s.push_back(a);
        }
        if(find(s.begin(),s.end(),1)==s.end())
            s.push_back(1);
        if(find(s.begin(),s.end(),n)==s.end())
            s.push_back(n);
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>w;
            adj[x].push_back(edge {x,y,w});
            adj[y].push_back(edge {y,x,w});
        }
        for(int i=0; i<s.size(); i++)
        {
            vector<int> d=dij(s[i]);
            for(int j=1; j<=n; j++)
                if(d[j]<=600)
                    v[s[i]].push_back(j);
        }
        cout<<bfs()<<endl;
    }
    return 0;
}
