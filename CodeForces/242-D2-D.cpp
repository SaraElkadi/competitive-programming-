#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
vector<vector<int>>adj(N);
int a[N],b[N];

int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=0;
    }
    queue<int> q;
    vector<int> v;
    while(1)
    {
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            if(a[x]==b[x])
            {
                v.push_back(x);
                b[x]++;
                for(int i=0; i<adj[x].size(); i++)
                {
                    b[adj[x][i]]++;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(a[i]==b[i])
                q.push(i);
        }
        if(q.empty())
            break;
    }
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    return 0;
}
