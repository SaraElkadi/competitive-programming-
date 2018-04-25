#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,a;
    cin>>n>>m>>a;
    int b[n],p[m];
    for(int i=0; i<n; i++)
        cin>>b[i];
    for(int i=0; i<m; i++)
        cin>>p[i];
    sort(b,b+n);
    sort(p,p+m);
    int l=0,r=min(n,m);
    while(l<r)
    {
        int mid=(l+r+1)/2;
        long long need=0;
        for(int i=0; i<mid; i++)
            need+=p[i]-min(p[i],b[n-mid+i]);
        if(need<=a)
            l=mid;
        else
            r=mid-1;
    }
    long long sum=0;
    for(int i=0; i<l; i++)
        sum+=p[i];
    cout<<l<<" "<<max(sum-a,0ll)<<endl;
    return 0;
}
