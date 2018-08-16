#include <bits/stdc++.h>

using namespace std;

const int N=1005;
double f[N],p[N];

int main()
{
    int n,t,k,m;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        memset(f,0,sizeof f);
        scanf("%d%d%d",&n,&k,&m);
        for(int i=0; i<n; i++)
            scanf("%lf",p+i);
        f[1]=p[0];
        for(int i=2;i<=m;i++){
            for(int j=0;j<n;j++)
                f[i]+=p[j]*pow(f[i-1],j);
        }
        printf("Case #%d: %0.7f\n",i,pow(f[m],k));
    }
    return 0;
}
