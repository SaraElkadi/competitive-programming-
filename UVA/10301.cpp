#include <bits/stdc++.h>

using namespace std;
typedef pair<double,double> point;
#define X first
#define Y second
bool interset(point c1,point c2,double r1,double r2)
{
    double disX=c1.X-c2.X;
    double disY=c1.Y-c2.Y;
    double rsum=r1+r2;
    double rdiff=r1-r2;
    return (disX*disX+disY*disY<=rsum*rsum)&&(disX*disX+disY*disY>=rdiff*rdiff);
}
vector<vector<int> > adj(105);
int cnt=0;
bool vis[105];
void dfs(int n)
{
    cnt++;
    vis[n]=1;
    for(int i=0; i<adj[n].size(); i++)
    {
        if(!vis[adj[n][i]])
            dfs(adj[n][i]);
    }
}
int main()
{
    //freopen("out.txt","w",stdout);
    int n;
    while(cin>>n&&n!=-1)
    {
        for(int i=0; i<100; i++)
            adj[i].clear();
        memset(vis,0,sizeof vis);
        double r[n];
        point p[n];
        for(int i=0; i<n; i++)
        {
            cin>>p[i].X>>p[i].Y>>r[i];
            for(int j=0; j<i; j++)
            {
                if(interset(p[i],p[j],r[i],r[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int mx=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                cnt=0;
                dfs(i);
                mx=max(mx,cnt);
            }
        }
        cout<<"The largest component contains "<<mx<<" ring";
        if(mx!=1)
         cout<<"s";
        cout<<"."<<endl;
    }
    return 0;
}
