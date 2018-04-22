#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
long long l[N],r[N];
void sw(long long x,long long y)
{
    r[x]=y;
    l[y]=x;
}
int main()
{
    //freopen("out.txt","w",stdout);
    long long n,m,k,x,y,t=1;
    while(cin>>n>>m)
    {
        for(int i=1; i<=n; i++)
        {
            l[i]=i-1;
            r[i]=i+1;
        }
        r[n]=0;
        l[0]=n;
        r[0]=1;
        bool rev=0;
        while(m--)
        {
            cin>>k;
            if(k==4) rev=!rev;
            else
            {
                cin>>x>>y;
                if(k==3&&r[y]==x) swap(x,y);
                if(k!=3&&rev) k=3-k;
                if(k==1&&l[y]==x) continue;
                if(k==2&&r[y]==x) continue;
                int lx=l[x],rx=r[x],ly=l[y],ry=r[y];
                if(k==1)
                    sw(lx,rx),sw(ly,x),sw(x,y);
                else if(k==2)
                    sw(lx,rx),sw(x,ry),sw(y,x);
                else
                {
                    if(r[x]==y)
                        sw(lx,y),sw(y,x),sw(x,ry);
                    else
                        sw(lx,y),sw(y,rx),sw(ly,x),sw(x,ry);
                }
            }
        }
        long long sum=0,x=0;
        for(int i=1; i<=n; i++)
        {
            x=r[x];
            if(i%2)
                sum+=x;
        }
        if(rev&&n%2==0)
            sum=n*(n+1)/2-sum;
        cout<<"Case "<<t++<<": "<<sum<<endl;
    }
    return 0;
}
