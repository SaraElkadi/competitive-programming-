#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char dir0='U',dir1;
    int ans=0;
    int x[n+1],y[n+1];
    cin>>x[0]>>y[0];
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]>x[i-1])
            dir1='R';
        else if(x[i]<x[i-1])
            dir1='L';
        else if(y[i]>y[i-1])
            dir1='U';
        else if(y[i]<y[i-1])
            dir1='D';
        if((dir0=='U'&&dir1=='L')||(dir0=='D'&&dir1=='R')||(dir0=='L'&&dir1=='D')||(dir0=='R'&&dir1=='U'))
            ans++;
        dir0=dir1;
    }
    cout<<ans;
    return 0;
}
