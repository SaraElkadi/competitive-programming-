#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int x=1,y=1;
    bool f=0;
    int cnt=0;
    for(int i=0; i<2*k-2; i++)
    {
        if(cnt&&cnt%2==0)
            cout<<endl;
        if(cnt%2==0)
            cout<<2;
        cout<<" "<<x<<" "<<y;
        cnt++;
        if(!f)
        {
            x++;
            if(x>n)
            {
                y++;
                x=n;
                f=1;
            }
        }
        else
        {
            x--;
            if(x<1)
            {
                y++;
                x=1;
                f=0;
            }
        }
    }
    if(cnt)
     cout<<endl;
    cout<<m*n-2*k+2;
    for(int i=0; i<m*n-2*k+2; i++)
    {
        cout<<" "<<x<<" "<<y;
        if(!f)
        {
            x++;
            if(x>n)
            {
                y++;
                x=n;
                f=1;
            }
        }
        else
        {
            x--;
            if(x<1)
            {
                y++;
                x=1;
                f=0;
            }
        }
    }
    return 0;
}
