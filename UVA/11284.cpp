
/*
  To solve this problem
  First, need to know the the cheapest cost to drive between every two stores and between stores and home, you can do this by floyd algorithm.
  After that , use this to build another array that store the cheapest cost between stores-that have operas only- and home (you can represent home as the first store).
  After get that , you can now try all possible ways to get operas by dp function and find the max.
  The parameters for dp function is the index of store , and indicator for stores visited ( To know what stores you visited ,you can use int variable and apply bitwise operation)
  From every store, try to go to all stores that you didn't visit yet and calculate the saved money.
  */
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
        // cost to go home again 
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
