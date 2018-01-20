#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,x1,x2,y1,y2;
    cin>>t;
    for(int i=1;i<=t;i++){
        int xmn=-100000,ymn=-100000,xmx=100000,ymx=100000;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>x1>>y1>>x2>>y2;
            xmn=max(x1,xmn);
            ymn=max(y1,ymn);
            xmx=min(x2,xmx);
            ymx=min(y2,ymx);
        }
        cout<<"Case "<<i<<": ";
        if(xmx>xmn&&ymx>ymn)
           cout<<(xmx-xmn)*(ymx-ymn)<<endl;
        else
        cout<<0<<endl;
    }
    return 0;
}
