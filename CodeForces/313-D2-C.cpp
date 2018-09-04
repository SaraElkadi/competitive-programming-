#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",a+i);
    sort(a,a+n,greater<int>());
    vector<int> v;
    for(int x=1; x<=n; x*=4)
        v.push_back(x);
    for(int i=v.size()-1; i>0; i--)
    {
        v[i]-=v[i-1];
    }
    long long ans=0,x=v.size(),idx=0;
    for(int i=0; i<n; i++)
    {
        if(!v[idx])
        {
            idx++;
            x--;
        }
        ans+=x*a[i];
        v[idx]--;
    }
    printf("%lld\n",ans);
    return 0;
}
