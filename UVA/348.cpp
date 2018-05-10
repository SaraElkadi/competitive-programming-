#include <bits/stdc++.h>

using namespace std;
const int N=15;
int d[N],dp[N][N],p[N][N];
int solve(int a,int b)
{
    int &ret=dp[a][b];
    if(ret!=-1) return ret;
    if(a==b) return ret=0;
    for(int k=a; k<b; k++)
    {
        int cost=d[a-1]*d[k]*d[b]+solve(a,k)+solve(k+1,b);
        if(ret==-1||cost<ret)
        {
            ret=cost;
            p[a][b]=k;
        }
    }
    return ret;
}
void path(int a,int b)
{
    if(a==b)
        cout<<"A"<<a;
    else
    {
        cout<<"(";
        path(a,p[a][b]);
        cout<<" x ";
        path(p[a][b]+1,b);
        cout<<")";
    }
}
int main()
{
    int n,t=1;
    while(cin>>n&&n)
    {
        for(int i=0; i<n; i++)
            cin>>d[i]>>d[i+1];
        memset(dp,-1,sizeof dp);
        solve(1,n);
        cout<<"Case "<<t++<<": ";
        path(1,n);
        cout<<endl;
    }
    return 0;
}
