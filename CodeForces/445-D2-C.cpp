#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int val[n],a,b,c;
    double ans=0;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        ans=max(ans,(double)(val[a]+val[b])/c);
    }
    cout<<fixed<<setprecision(15)<<ans;
    return 0;
}
