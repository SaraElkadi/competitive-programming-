#include <bits/stdc++.h>

using namespace std;
int mx=-1,n,m,t,u,v,w;
vector<vector<pair<int,int> > >par(5005,vector<pair<int,int> >(5005,make_pair(-1,0)));
vector<vector<pair<int,int> > > adj(5005);
vector<int> vec(5005);
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    int dep=0,sz=1;
    int cur;
    for(; !q.empty(); ++dep, sz=q.size())
    {
        while(sz--)
        {
            cur=q.front(),q.pop();
            if(cur==n&&dep>mx&&par[dep-1][cur].second<=t)
            {
                mx=dep;
            }
            for(int i=0; i<adj[cur].size(); i++)
            {
                q.push(adj[cur][i].first);
                if( par[dep][adj[cur][i].first].first==-1||
                        par[dep][adj[cur][i].first].second>(dep>0?par[dep-1][cur].second:0)+adj[cur][i].second);
                par[dep][adj[cur][i].first]=make_pair(cur,(dep>0?par[dep-1][cur].second:0)+adj[cur][i].second);
            }
        }
    }
}
int main()
{
    cin>>n>>m>>t;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    bfs(1);
    cout<<mx+1<<endl;
    v=n;w=1;
    vec[0]=v;
    for(int i=mx-1; i>=0; i--)
    {
        vec[w++]=par[i][v].first;
        v=par[i][v].first;
    }
    for(int i=mx; i>=0; i--)
        cout<<vec[i]<<" ";
    return 0;
}
