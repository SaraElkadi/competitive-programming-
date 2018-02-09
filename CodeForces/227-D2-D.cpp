#include <bits/stdc++.h>

using namespace std;
const int MAX=100005;
long long ans[MAX],a[MAX];
int main()
{
    long long n,q,k;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=1; i<=n; i++)
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
            long long w=1,m=0,d=0,p=0;
            while(1)
            {
                d+=(a[min(p+w,n)]-a[p])*m;
                if(p+w>=n)
                    break;
                p+=w;
                w*=k;
                m++;
            }
            ans[k]=d;
            cout<<d<<" ";
        }
    }
    return 0;
}
