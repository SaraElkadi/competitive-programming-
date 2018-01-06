#include <bits/stdc++.h>

using namespace std;
int vis[105],cnt,d;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

vector<vector<int> > adj(105);
void dfs(int s)
{
    vis[s]=1;
    cnt++;
    if(!adj[s].size())
        d=0;
    for(int i=0; i<adj[s].size(); i++)
    {
        if(!vis[adj[s][i]])
        {
            dfs(adj[s][i]);
        }
    }
}
int main()
{
    int n,f=1;
    cin>>n;
    int a[n+5],vv[105]={0};
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        vv[a[i]]=1;
        if(i!=a[i])
        {
            adj[i].push_back(a[i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(!vv[i])
            f=0;
    }
    vector<int> v;
    int mx=-1;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(adj[i].size())
            {
                cnt=0;
                d=1;
                dfs(i);
                if(!d)
                {
                    f=0;
                    break;
                }
                if(cnt!=1)
                {
                    v.push_back(cnt);
                    mx=max(mx,cnt);
                }
                else
                {
                    f=0;
                }
            }
        }
    }
    if(f)
    {
        int ans=1;
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]%2==0)
                v[i]/=2;
            if(ans%v[i]!=0)
            {
                ans*=(v[i]/gcd(ans,v[i]));
            }
        }
        cout<<ans;
    }
    else
        cout<<-1;
    return 0;
}
