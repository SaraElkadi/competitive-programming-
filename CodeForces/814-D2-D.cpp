#include <bits/stdc++.h>

using namespace std;
#define pi acos(-1.0)
const int MAX=1005;
long long x[MAX],y[MAX],r[MAX];
long long ans;
vector<vector<int> > adj(MAX);

bool contain(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=(r[i]-r[j])*(r[i]-r[j]);
}

void dfs(int n,int k)
{
    if(!k||(k%2))
        ans+=r[n]*r[n];
    else
        ans-=r[n]*r[n];
    for(int i=0; i<adj[n].size(); i++)
    {
        dfs(adj[n][i],k+1);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i]>>r[i];
    }
    int p[n];
    memset(p,-1,sizeof p);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(r[j]>r[i]&&contain(i,j))
                if(p[i]==-1||r[p[i]]>r[j])
                    p[i]=j;
        }
        if(p[i]!=-1)
            adj[p[i]].push_back(i);
    }
    for(int i=0; i<n; i++)
    {
        if(p[i]==-1)
            dfs(i,0);
    }
    cout<<fixed<<setprecision(8)<<ans*pi;
    return 0;
}
