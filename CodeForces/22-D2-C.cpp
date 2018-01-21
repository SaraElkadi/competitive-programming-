#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,v,x=1;
    cin>>n>>m>>v;
    if(m<n-1||m>(n-1)*(n-2)/2+1)
        cout<<-1;
    else
    {
        if(v==1)
            x=2;
        for(int i=1; i<=n; i++)
        {
            if(i!=v)
                cout<<i<<" "<<v<<endl;
        }
        int k=n-1;
        for(int i=1; i<=n&&k<m; i++)
        {
            if(i!=v&&i!=x)
            {
                for(int j=i+1; j<=n&&k<m; j++)
                {
                    if(j!=v&&i!=x)
                    {
                        cout<<i<<" "<<j<<endl;
                        k++;
                    }
                }
            }
        }
    }
    return 0;
}
