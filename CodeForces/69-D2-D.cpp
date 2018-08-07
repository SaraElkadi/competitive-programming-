#include <bits/stdc++.h>

using namespace std;
int X[25],Y[25];
int dp[405][405];
int x,y,n,d;
bool vaild(int x,int y)
{
    return (x-200)*(x-200)+(y-200)*(y-200)<=d*d;
}
bool isWinning(int x,int y)
{
    if(!vaild(x,y))
        return 1;
    int &ret=dp[x][y];
    if(ret!=-1)
        return ret;
    for(int i=0; i<n; i++)
    {
        if(!isWinning(x+X[i],y+Y[i]))
            return ret=1;
    }
    return ret=0;
}

int main()
{
    cin>>x>>y>>n>>d;
    for(int i=0; i<n; i++)
        cin>>X[i]>>Y[i];
    memset(dp,-1,sizeof dp);
    if(isWinning(x+200,y+200))
        cout<<"Anton";
    else
        cout<<"Dasha";
    return 0;
}
