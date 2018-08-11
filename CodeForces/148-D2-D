#include <bits/stdc++.h>

using namespace std;
const int N=1005;
double dp[N][N][2];
double prob(int w,int b,int p)
{
    if(w<=0||b<0)
        return 0;

    double &ret=dp[w][b][p];
    if(ret==ret)
        return ret;
    ret=0;

    if(p==0)
    {
        ret+=((double)(w)/(w+b));
        ret+=((double)(b)/(w+b))*prob(w,b-1,p^1);
    }
    else
    {
        if(w+b>1)
        {
            ret+=(((double)b*(b-1))/((b+w)*(w+b-1)))*prob(w,b-2,p^1);
            ret+=(((double)b*(w))/((b+w)*(w+b-1)))*prob(w-1,b-1,p^1);
        }
        else
            return 0;
    }
    return ret;
}
int main()
{
    int w,b;
    cin>>w>>b;
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(9)<<prob(w,b,0);
    return 0;
}
