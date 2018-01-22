#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,l,r,ql,qr,ans=1000000000;
    cin>>n>>l>>r>>ql>>qr;
    int w[n];
    cin>>w[0];
    for(int i=1;i<n;i++){
        cin>>w[i];
        w[i]+=w[i-1];
    }
    for(int i=0;i<=n;i++){
       ans=min(ans,(i==0?0:w[i-1])*l+(w[n-1]-(i==0?0:w[i-1]))*r+max(abs(n-2*i)-1,0)*(n-i<i?ql:qr));
    }
    cout<<ans;
    return 0;
}
