#include <bits/stdc++.h>

using namespace std;
int n,m,a[15],b[15],c[15],d[15];
int mem[15][1006];
int solve(int idx,int rem)
{
    if(idx>m||rem<=0)
        return 0;
    int &res=mem[idx][rem];
    if(res!=-1)
        return res;
    res=0;

    for(int i=0; !idx||i<=a[idx]/b[idx]; i++)
    {
        if(rem>=c[idx]*i)
            res=max(res,solve(idx+1,rem-c[idx]*i)+d[idx]*i);
        else
            break;
    }
    return res;
}

int main()
{
    cin>>n>>m>>c[0]>>d[0];
    for(int i=1; i<=m; i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    memset(mem,-1,sizeof mem);
    cout<<solve(0,n);
    return 0;
}
