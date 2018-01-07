#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x,y,m;
    cin>>x>>y>>m;
    if(x>=m||y>=m)
        cout<<0;
    else if(x<=0&&y<=0)
        cout<<-1;
    else
    {
        if(x>y)
            swap(x,y);
        long long ans=0;
        if(x<0){
            ans+=abs(x)/y+1;
            x+=abs(x)/y*y+y;
        }
        long long a=1,b=1,w=1;
        for(int i=0; i<120; i++)
        {
            if(a*x+b*y>=m)
                break;
            else
            {
                long long temp=b;
                b+=a;
                a=temp;
                w++;
            }
        }
        cout<<ans+w;
    }
    return 0;
}
