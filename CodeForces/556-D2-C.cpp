#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,x;
    cin>>n>>k;
    int ans=n-1;
    for(int i=0; i<k; i++)
    {
        cin>>x;
        int a[x+1];
        for(int j=1; j<=x; j++)
        {
            cin>>a[j];
        }
        int f=0;
        for(int j=1; j<=x; j++)
        {
            if(j==a[j])
                f++;
            else
                break;
        }
        if(f)
        {
            ans-=(f-1);
            x-=(f-1);
        }
        ans+=(x-1);
    }
    cout<<ans;
    return 0;
}
