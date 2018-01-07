#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,k,x,y;
    cin>>n>>m>>k;
    long long a[n+5],b[100005]= {0},c[100005]= {0},r[m+5],l[m+5],d[m+5];
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>l[i]>>r[i]>>d[i];
    for(int i=1; i<=k; i++)
    {
        cin>>x>>y;
        b[x]++;
        b[y+1]--;
    }
    for(int i=1; i<=m; i++)
        b[i]+=b[i-1];
    for(int i=1; i<=m; i++)
    {
        long long q=d[i]*b[i];
        c[l[i]]+=q;
        c[r[i]+1]-=q;
    }
    for(int i=1; i<=n; i++)
        c[i]+=c[i-1];
    for(int i=1; i<=n; i++)
        cout<<a[i]+c[i]<<" ";
    return 0;
}
