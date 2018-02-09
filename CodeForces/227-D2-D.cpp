#include <bits/stdc++.h>

using namespace std;
const int MAX=10000005;
long long ans[MAX],a[MAX];
int main()
{
    int n,q,k;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    for(int i=1; i<n; i++)
        a[i]+=a[i-1];
    cin>>q;
    memset(ans,-1,sizeof ans);
    while(q--)
    {
        cin>>k;
        if(ans[k]!=-1)
            cout<<ans[k]<<" ";
        else
        {
            long long w=k,m=1,d=0,r=1;
            for(int i=0; i<n; i+=r)
            {
                d+=(a[((w<=(n-1))?w:(n-1))]-a[i])*m;
                w*=k;
                r*=k;
                m++;
            }
            ans[k]=d;
            cout<<d<<" ";
        }
    }
    return 0;
}
