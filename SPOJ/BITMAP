#include <bits/stdc++.h>

using namespace std;
vector<int> v;
vector<int> BFS(vector<vector<int> >&adj)
{
    vector<int> len(adj.size(),-1);
    queue<pair<int,int> > q;
    for(int i=0; i<v.size(); i++)
    {
        q.push(make_pair(v[i],0));
        len[v[i]]=0;
    }
    int cur,dep;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        cur=p.first,dep=p.second;
        for(int i=0; i<adj[cur].size(); i++)
        {
            if(len[adj[cur][i]]==-1)
            {
                q.push(make_pair(adj[cur][i],dep+1));
                len[adj[cur][i]]=dep+1;
            }

        }
    }
    return len;
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        int k=1;
        v.clear();
        string s[n];
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            for(int j=0; j<m; j++)
            {
                if(s[i][j]=='1')
                {
                    v.push_back(k);
                }
                k++;
            }
        }
        vector<vector<int>> adj(40000);
        k=1;
        for(int i=0; i<n*m; i++)
        {
            if(k-m>0)
                adj[k].push_back(k-m);
            if(k+m<=n*m)
                adj[k].push_back(k+m);
            if((k+1)%m!=1)
                adj[k].push_back(k+1);
            if((k-1)%m!=0)
                adj[k].push_back(k-1);
                k++;
        }
        vector<int> l=BFS(adj);
        k=1;
        for(int i=0; i<n; i++)
        {
            printf("%d",l[k]);
            k++;
            for(int j=1; j<m; j++)
            {
                printf(" %d",l[k]);
                k++;
            }
            printf("\n");
        }
    }
    return 0;
}
