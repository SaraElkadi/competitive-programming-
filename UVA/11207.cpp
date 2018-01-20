#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,ans=-1;
    while(cin>>n&&n)
    {
        double k=-1,x,y;
        for(int i=1; i<=n; i++)
        {
            cin>>x>>y;
            if(x>y)
                swap(x,y);
            double sz=max(x/2,min(y/4,x));
            if(sz>k)
            {
                ans=i;
                k=sz;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
