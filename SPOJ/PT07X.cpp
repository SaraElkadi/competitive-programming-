#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
vector<vector<int> > adj(N);
int dp[N][2];
bool vis[N][2];
int solve(int n,bool f,int par){
int &ret=dp[n][f];
if(vis[n][f])
    return ret;
vis[n][f]=1;
ret=0;
for(int i=0;i<adj[n].size();i++){
    if(adj[n][i]!=par){
        if(!f)
            ret+=solve(adj[n][i],1,n);
        else
            ret+=min(solve(adj[n][i],1,n),solve(adj[n][i],0,n));
    }
} ret+=f;
return ret;
}
int main()
{
    int n,x,y;
    while(cin>>n){
        for(int i=0;i<N;i++){
            adj[i].clear();
            vis[i][0]=0;
            vis[i][1]=0;
        }
    for(int i=1;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans=1;
    ans=min(solve(1,0,-1),solve(1,1,-1));
    cout<<ans<<endl;
    }
    return 0;
}
