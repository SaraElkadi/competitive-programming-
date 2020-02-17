#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}

int main()
{
    ll t,n,m,a,d;
    cin>>t;
    while(t--)
    {
        ll arr[5];
        cin>>n>>m>>a>>d;
        for(int i=0; i<5; i++)
            arr[i]=a+i*d;
        ll div=0;
        for(int i=0; i<(1<<5); i++)
        {
            ll num=1,cnt=0;
            int val=i;
            for(int j=0; j<5; j++)
            {
                if(val&1)
                {
                    num=lcm(num,arr[j]);
                    cnt++;
                }
                val>>=1;
            }
            if(cnt%2)
                div-=((m/num)-((n-1)/num));
            else
                div+=((m/num)-((n-1)/num));
        }
        cout<<div<<endl;
    }
    return 0;
}
