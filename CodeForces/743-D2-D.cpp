#include <bits/stdc++.h>

using namespace std;
#define oo 1e18+1
vector<vector<int> >adj(200005);
long long x[200005],sum[200005],ans=-oo;
bool vis[200005];
void dfs(int n)
{
    vis[n]=1;
    sum[n]=x[n];
    x[n]=-oo;
    long long m1=-oo,m2=-oo;
    for(int i=0; i<adj[n].size(); i++)
    {
        int ch=adj[n][i];
        if(!vis[ch])
        {
            dfs(ch);
            sum[n]+=sum[ch];
            long long val=x[ch];
            x[n]=max(x[n],val);
            if(m1<val) swap(m1,val);
            if(m2<val) swap(m2,val);
        }
    }
    if(m2>-oo)
        ans=max(ans,m1+m2);
    x[n]=max(x[n],sum[n]);
}
int main()
{
    int n,a,b;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>x[i];
    for(int i=1; i<n; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    if(ans==-oo)
        cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}
