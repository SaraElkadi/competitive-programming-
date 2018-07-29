#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-6
const double oo=1e18;
double RC[55][55],R[15][15],SC[15];
bool vis[15][(1<<15)];
double BS[15][(1<<15)];
int k;
double solve(int idx,int a)
{
    double &ret=BS[idx][a];
    if(!vis[idx][a])
    {
        vis[idx][a]=1;
        ret-=R[idx][0];
        for(int i=0; i<=k; i++)
        {
            if(!(a&(1<<i)))
                ret=max(ret,solve(i,a|(1<<i))-R[idx][i]);
        }
        ret+=SC[idx];
    }
    return ret;
}
int main()
{
    int t,n,m,a,b;
    double x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                RC[i][j]=oo;
            }
            RC[i][i]=0;
        }
        for(int i=0; i<m; i++)
        {
            cin>>a>>b>>x;
            RC[a][b]=RC[b][a]=min(RC[a][b],x);
        }
        for(int k=0; k<=n; k++)
        {
            for(int i=0; i<=n; i++)
            {
                for(int j=0; j<=n; j++)
                {
                    RC[i][j]=min(RC[i][j],RC[i][k]+RC[k][j]);
                }
            }
        }
        cin>>k;
        int SN[k+1];
        SN[0]=0;
        for(int i=1; i<=k; i++)
        {
            cin>>SN[i]>>SC[i];
            for(int j=i; j>=0; j--)
                R[i][j]=R[j][i]=RC[SN[i]][SN[j]];
        }
        memset(vis,0,sizeof vis);
        memset(BS,0,sizeof BS);
        double ans=solve(0,0);
        if(ans<EPS)
            cout<<"Don\'t leave the house"<<endl;
        else
            cout<<"Daniel can save $"<<fixed<<setprecision(2)<<ans<<endl;

    }
    return 0;
}
