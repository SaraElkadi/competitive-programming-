#include <bits/stdc++.h>

using namespace std;
int a[105][105];
int main()
{
    int t,n,q,x1,x2,y1,y2;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        memset(a,0,sizeof a);
        while(q--)
        {
            cin>>x1>>y1>>x2>>y2;
            for(int i=x1; i<=x2; i++)
            {
                for(int j=y1; j<=y2; j++)
                {
                    a[i][j]=1;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                a[i][j]+=a[i][j-1];
            }
        }
        int ans=0,w=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                w=0;
                for(int k=1; k<=n; k++)
                {
                    if(a[k][i]==a[k][j])
                        w+=(j-i);
                    else
                        w=0;
                    ans=max(w,ans);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
